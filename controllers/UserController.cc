#include "UserController.h"
#include "utils/misc.hpp"
#include <drogon/HttpTypes.h>
#include <drogon/orm/Criteria.h>
#include <drogon/orm/Mapper.h>
#include <exception>
#include <jwt-cpp/jwt.h>

void UserController::login(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) {

    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    auto jsonPtr = req->jsonObject();
    if (!jsonPtr) {
        auto resp = HttpResponse::newHttpJsonResponse(
            error_json("No json object is found in the request"));
        resp->setStatusCode(k400BadRequest);
        (*callbackPtr)(resp);
        return;
    }
    auto account = (*jsonPtr)["account"].asString();
    auto password = (*jsonPtr)["password"].asString();

    try {
        drogon::orm::Mapper<User> UserMapper(dbClientPtr);
        auto userlist = UserMapper.findBy(
            Criteria(User::Cols::_account, CompareOperator::EQ, account) &&
            Criteria(User::Cols::_password, CompareOperator::EQ, password));
        if (userlist.empty()) {
            auto resp = HttpResponse::newHttpJsonResponse(
                error_json("帐号不存在或者密码错误"));
            resp->setStatusCode(k200OK);
            (*callbackPtr)(resp);
            return;
        }
        if (userlist.size() > 1) {
            throw std::runtime_error("数据库帐号重复");
        }
        auto user = userlist.front();

        auto secret = drogon::app().getCustomConfig()["secret"].asString();
        auto token = jwt::create()
                         .set_issuer("auth0")
                         .set_type("JWS")
                         .set_payload_claim("uuid", jwt::claim(*user.getUuid()))
                         .sign(jwt::algorithm::hs256{secret});

        Json::Value retn;
        retn["account"] = *user.getAccount();
        retn["uuid"] = *user.getUuid();
        retn["token"] = "Bearer " + token;
        
        auto resp = HttpResponse::newHttpJsonResponse(success_json(retn));
        resp->setStatusCode(k200OK);
        (*callbackPtr)(resp);
    } catch (const std::exception &e) {
        LOG_ERROR << e.what();
        auto resp = HttpResponse::newHttpJsonResponse(error_json(e.what()));
        resp->setStatusCode(k400BadRequest);
        (*callbackPtr)(resp);
    }
}