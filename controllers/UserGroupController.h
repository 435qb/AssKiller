#pragma once

#include <drogon/HttpController.h>
#include <string>

using namespace drogon;

class UserGroupController : public drogon::HttpController<UserGroupController>
{
  public:
    METHOD_LIST_BEGIN
    
    ADD_METHOD_TO(UserGroupController::add, "/{1}/add", Post);
    ADD_METHOD_TO(UserGroupController::cancel, "/{1}/cancel", Post);
    ADD_METHOD_TO(UserGroupController::confirm, "/{1}/confirm", Post);
    ADD_METHOD_TO(UserGroupController::getInfo, "/{1}/getInfo", Get);
    ADD_METHOD_TO(UserGroupController::getConfirm, "/{1}/getConfirm", Get);
    METHOD_LIST_END

    void add(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string uuid);
    void cancel(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string uuid);
    void confirm(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string uuid);
    void getInfo(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string uuid);
    void getConfirm(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string uuid);
    auto getDbClient() 
    {
        return drogon::app().getDbClient("default");
    }
};
