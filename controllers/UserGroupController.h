#pragma once

#include "models/Confirm.h"
#include "models/Transactions.h"
#include "models/User.h"
#include "models/Usergroup.h"
#include "models/UsergroupUser.h"
#include <drogon/HttpController.h>
#include <string>
using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;

class UserGroupController : public drogon::HttpController<UserGroupController> {
  public:
    METHOD_LIST_BEGIN

    ADD_METHOD_TO(UserGroupController::add, "/{1}/add", Post, Options);
    ADD_METHOD_TO(UserGroupController::addTx, "/{1}/addTx", Post, Options);
    ADD_METHOD_TO(UserGroupController::cancel, "/{1}/cancel", Post, Options);
    ADD_METHOD_TO(UserGroupController::confirm, "/{1}/confirm", Post, Options);
    ADD_METHOD_TO(UserGroupController::getInfo, "/{1}/getInfo", Get, Options);
    ADD_METHOD_TO(UserGroupController::getConfirm, "/{1}/getConfirm", Get, Options);
    ADD_METHOD_TO(UserGroupController::getUsers, "/{1}/getUsers", Get, Options);
    METHOD_LIST_END

    void add(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback,
             std::string uuid);
    bool
    addTx_(orm::DbClientPtr &dbClientPtr,
           std::shared_ptr<std::function<void(
               const std::shared_ptr<drogon::HttpResponse> &)>> &callbackPtr,
           Json::Value &tranx);
    void addTx(const HttpRequestPtr &req,
               std::function<void(const HttpResponsePtr &)> &&callback,
               std::string uuid);
    void cancel(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                std::string uuid);
    void confirm(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 std::string uuid);
    void getInfo(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 std::string uuid);
    void getConfirm(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback,
                    std::string uuid);
    void getUsers(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback,
                    std::string uuid);
    bool
    confirm_(orm::DbClientPtr &dbClientPtr,
             std::shared_ptr<std::function<void(
                 const std::shared_ptr<drogon::HttpResponse> &)>> &callbackPtr,
             const std::string &uuid, const std::string &txuuid);
};
