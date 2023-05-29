#pragma once
#include "models/User.h"
#include <drogon/HttpController.h>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;


class UserController : public drogon::HttpController<UserController>
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(UserController::login, "/login", Post, Options);

    METHOD_LIST_END
    void login(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
};
