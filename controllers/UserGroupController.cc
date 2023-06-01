#include "UserGroupController.h"
#include "utils/misc.hpp"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <ctime>
#include <drogon/HttpTypes.h>
#include <drogon/orm/Criteria.h>
#include <drogon/orm/Mapper.h>
#include <json/value.h>
#include <tuple>
#include <vector>

void UserGroupController::add(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {

    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    drogon::orm::Mapper<UsergroupUser> UsergroupUserMapper(dbClientPtr);
    auto jsonPtr = req->jsonObject();
    if (!jsonPtr) {
        auto resp = HttpResponse::newHttpJsonResponse(
            error_json("No json object is found in the request"));
        resp->setStatusCode(k400BadRequest);
        (*callbackPtr)(resp);
        return;
    }
    std::vector<std::string> uuids;
    uuids.push_back(uuid);
    for (auto &&uuid : (*jsonPtr)["uuids"]) {
        uuids.push_back(uuid.asString());
    }
    if (uuids.empty() || uuids.size() == 1) {
        auto resp =
            HttpResponse::newHttpJsonResponse(error_json("不能一个人开趴"));
        resp->setStatusCode(k200OK);
        (*callbackPtr)(resp);
        return;
    }
    try {
        auto uservector = UsergroupUserMapper.findBy(Criteria(
            UsergroupUser::Cols::_useruuid, CompareOperator::EQ, uuid));
        for (auto &&user : uservector) {
            auto guuid = user.getValueOfGuuid();
            auto gvector = UsergroupUserMapper.findBy(Criteria(
                UsergroupUser::Cols::_guuid, CompareOperator::EQ, guuid));
            std::vector<std::string> out_{gvector.size()};
            std::transform(gvector.begin(), gvector.end(), out_.begin(),
                           [](const UsergroupUser &guser) {
                               return *guser.getUseruuid();
                           });
            if (uuids_equal(uuids, out_)) {
                auto resp =
                    HttpResponse::newHttpJsonResponse(error_json("重复的组"));
                resp->setStatusCode(k200OK);
                (*callbackPtr)(resp);
                return;
            }
        }

        Json::Value usergroup;
        auto guuid = drogon::utils::getUuid();
        usergroup["uuid"] = guuid;
        usergroup["nextuuid"] = uuids[1]; // uuids[0]是自己
        Usergroup object{usergroup};
        drogon::orm::Mapper<Usergroup> UsergroupMapper(dbClientPtr);
        UsergroupMapper.insert(object);
        for (auto i = 0; i != uuids.size(); ++i) {
            Json::Value usergroupUser;
            usergroupUser["guuid"] = guuid;
            usergroupUser["useruuid"] = uuids[i]; // uuids[0]是自己
            usergroupUser["num"] = i;
            UsergroupUser object{usergroupUser};
            UsergroupUserMapper.insert(object);
        }
        Json::Value tranx;
        tranx["txuuid"] = drogon::utils::getUuid();
        tranx["time"] = ::trantor::Date::now().toDbString();
        tranx["useruuid"] = uuid; // uuids[0]是自己
        tranx["guuid"] = guuid;   // 判断是否存在
        if (!addTx_(dbClientPtr, callbackPtr, tranx)) {
            return;
        }
        auto resp =
            HttpResponse::newHttpJsonResponse(success_json(Json::Value{}));
        resp->setStatusCode(k200OK);
        (*callbackPtr)(resp);
    } catch (const std::exception &e) {
        LOG_ERROR << e.what();
        auto resp = HttpResponse::newHttpJsonResponse(error_json(e.what()));
        resp->setStatusCode(k400BadRequest);
        (*callbackPtr)(resp);
    }
}
bool UserGroupController::addTx_(
    orm::DbClientPtr &dbClientPtr,
    std::shared_ptr<
        std::function<void(const std::shared_ptr<drogon::HttpResponse> &)>>
        &callbackPtr,
    Json::Value &tranx) {
    Transactions object{tranx};
    drogon::orm::Mapper<Transactions> TransactionsMapper(dbClientPtr);
    TransactionsMapper.insert(object);
    return confirm_(dbClientPtr, callbackPtr, *object.getUseruuid(),
                    *object.getTxuuid());
}
void UserGroupController::addTx(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {

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
    auto guuid = (*jsonPtr)["guuid"].asString();
    Json::Value tranx;
    tranx["txuuid"] = drogon::utils::getUuid();
    tranx["time"] = ::trantor::Date::now().toDbString();
    tranx["useruuid"] = uuid; // uuids[0]是自己
    tranx["guuid"] = guuid;   // 判断是否存在

    try {
        if (!addTx_(dbClientPtr, callbackPtr, tranx)) {
            return;
        }
        auto resp =
            HttpResponse::newHttpJsonResponse(success_json(Json::Value{}));
        resp->setStatusCode(k200OK);
        (*callbackPtr)(resp);
    } catch (const std::exception &e) {
        LOG_ERROR << e.what();
        auto resp = HttpResponse::newHttpJsonResponse(error_json(e.what()));
        resp->setStatusCode(k400BadRequest);
        (*callbackPtr)(resp);
    }
}
void UserGroupController::cancel(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {

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
    auto txuuid = (*jsonPtr)["txuuid"].asString();

    try {
        drogon::orm::Mapper<Confirm> ConfirmMapper(dbClientPtr);
        ConfirmMapper.findByPrimaryKey(std::make_tuple(uuid, txuuid));
        auto resp =
            HttpResponse::newHttpJsonResponse(error_json("确认过后无法取消"));
        resp->setStatusCode(k200OK);
        (*callbackPtr)(resp);
        return;
    } catch (UnexpectedRows ex) {
    }
    try {
        drogon::orm::Mapper<Transactions> TransactionsMapper(dbClientPtr);
        TransactionsMapper.deleteByPrimaryKey(txuuid);
        auto resp =
            HttpResponse::newHttpJsonResponse(success_json(Json::Value{}));
        resp->setStatusCode(k200OK);
        (*callbackPtr)(resp);
    } catch (const std::exception &e) {
        LOG_ERROR << e.what();
        auto resp = HttpResponse::newHttpJsonResponse(error_json(e.what()));
        resp->setStatusCode(k400BadRequest);
        (*callbackPtr)(resp);
    }
}
void UserGroupController::confirm(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {

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
    auto txuuid = (*jsonPtr)["txuuid"].asString();

    try {
        if (!confirm_(dbClientPtr, callbackPtr, uuid, txuuid)) {
            return;
        }

        auto resp =
            HttpResponse::newHttpJsonResponse(success_json(Json::Value{}));
        resp->setStatusCode(k200OK);
        (*callbackPtr)(resp);
    } catch (const std::exception &e) {
        LOG_ERROR << e.what();
        auto resp = HttpResponse::newHttpJsonResponse(error_json(e.what()));
        resp->setStatusCode(k400BadRequest);
        (*callbackPtr)(resp);
    }
}
bool UserGroupController::confirm_(
    orm::DbClientPtr &dbClientPtr,
    std::shared_ptr<
        std::function<void(const std::shared_ptr<drogon::HttpResponse> &)>>
        &callbackPtr,
    const std::string &uuid, const std::string &txuuid) {
    Json::Value confirm;
    confirm["useruuid"] = uuid;
    confirm["txuuid"] = txuuid;
    Confirm object{confirm};
    drogon::orm::Mapper<Confirm> ConfirmMapper(dbClientPtr);
    drogon::orm::Mapper<Transactions> TransactionsMapper(dbClientPtr);
    auto tx = TransactionsMapper.findByPrimaryKey(txuuid);
    auto guuid = *tx.getGuuid();
    drogon::orm::Mapper<Usergroup> UsergroupMapper(dbClientPtr);
    auto newObject = UsergroupMapper.findByPrimaryKey(guuid);
    drogon::orm::Mapper<UsergroupUser> UsergroupUserMapper(dbClientPtr);

    auto size = UsergroupUserMapper
                    .findBy(Criteria(UsergroupUser::Cols::_guuid,
                                     CompareOperator::EQ, guuid))
                    .size();
    ConfirmMapper.insert(object);
    if (*tx.getCount() == size - 1) {            // 最后一个人确认交易
        if (*newObject.getCount() == size - 1) { // 最后一个人代取
            UsergroupMapper.deleteByPrimaryKey(guuid);
        } else {
            // 更新group里的count
            auto newCount = *newObject.getCount() + 1;
            auto uv = UsergroupUserMapper.findBy(
                Criteria(UsergroupUser::Cols::_guuid, CompareOperator::EQ,
                         guuid) &&
                Criteria(UsergroupUser::Cols::_num, CompareOperator::EQ,
                         newCount));
            assert(uv.size() == 1);

            newObject.setCount(newCount);
            newObject.setNextuuid(*uv[0].getUseruuid());

            auto count = UsergroupMapper.update(newObject);
            if (count == 0) {
                auto resp = HttpResponse::newHttpJsonResponse(
                    error_json("No resources are updated"));
                resp->setStatusCode(k404NotFound);
                (*callbackPtr)(resp);
                return false;
            } else if (count != 1) {
                LOG_FATAL << "More than one resource is updated: " << count;
                auto resp = HttpResponse::newHttpJsonResponse(
                    error_json("database error"));
                resp->setStatusCode(k500InternalServerError);
                (*callbackPtr)(resp);
                return false;
            }
        }
    } else {
        tx.setCount(*tx.getCount() + 1);
        auto count = TransactionsMapper.update(tx);
        if (count == 0) {
            auto resp = HttpResponse::newHttpJsonResponse(
                error_json("No resources are updated"));
            resp->setStatusCode(k404NotFound);
            (*callbackPtr)(resp);
            return false;
        } else if (count != 1) {
            LOG_FATAL << "More than one resource is updated: " << count;
            auto resp =
                HttpResponse::newHttpJsonResponse(error_json("database error"));
            resp->setStatusCode(k500InternalServerError);
            (*callbackPtr)(resp);
            return false;
        }
    }
    return true;
}
void UserGroupController::getInfo(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {
    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));

    try {
        drogon::orm::Mapper<UsergroupUser> UsergroupUserMapper(dbClientPtr);
        drogon::orm::Mapper<Usergroup> UsergroupMapper(dbClientPtr);
        auto uv = UsergroupUserMapper.findBy(Criteria{
            UsergroupUser::Cols::_useruuid, CompareOperator::EQ, uuid});

        Json::Value retn{Json::ValueType::arrayValue};
        for (auto &&v : uv) {
            auto guuid = *v.getGuuid();
            auto gvs = UsergroupUserMapper.findBy(Criteria{
                UsergroupUser::Cols::_guuid, CompareOperator::EQ, guuid});
            Json::Value array{Json::ValueType::arrayValue};
            for (auto &&gv : gvs) {
                array.append(gv.toJson());
            }
            auto user = UsergroupMapper.findByPrimaryKey(guuid);
            Json::Value i;
            i["guuid"] = guuid;
            i["data"] = array;
            i["next"] = *user.getNextuuid();
            retn.append(i);
        }
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
void UserGroupController::getConfirm(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {
    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));

    try {
        drogon::orm::Mapper<Confirm> ConfirmMapper(dbClientPtr);
        drogon::orm::Mapper<Transactions> TransactionsMapper(dbClientPtr);
        drogon::orm::Mapper<UsergroupUser> UsergroupUserMapper(dbClientPtr);
        drogon::orm::Mapper<User> UserMapper(dbClientPtr);

        auto user = UserMapper.findOne(
            Criteria(User::Cols::_uuid, CompareOperator::EQ, uuid));
        auto pairs = user.getUsergroups(dbClientPtr);
        std::vector<Transactions> txids;
        for (auto &&[usergroup, usergroupuser] : pairs) {
            auto txs = usergroup.getTransactions(dbClientPtr);
            auto maxCount = usergroup.getUsers(dbClientPtr).size();
            auto end = std::find_if(txs.begin(), txs.end(),
                                    [maxCount](const Transactions &trans) {
                                        return *trans.getCount() < maxCount;
                                    });
            if (end == txs.end()) {
                continue;
            }
            auto confirms = end->getConfirms(dbClientPtr);
            auto confirm_end =
                std::find_if(confirms.begin(), confirms.end(),
                             [&uuid](const Confirm &confirm) {
                                 return *confirm.getUseruuid() == uuid;
                             });
            if(confirm_end == confirms.end()){
                txids.push_back(*end);
            }
        }
        Json::Value retn{Json::ValueType::arrayValue};
        for (auto &&v : txids) {
            retn.append(v.toJson());
        }
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

void UserGroupController::getUsers(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {
    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));

    try {
        drogon::orm::Mapper<User> UserMapper(dbClientPtr);
        auto txs = UserMapper.findAll();
        auto end =
            std::remove_if(txs.begin(), txs.end(), [&uuid](const User &user) {
                return *user.getUuid() == uuid;
            });
        txs.erase(end, txs.end());
        Json::Value retn{Json::ValueType::arrayValue};
        for (auto &&v : txs) {
            Json::Value value;
            value["account"] = *v.getAccount();
            value["uuid"] = *v.getUuid();
            retn.append(value);
        }
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