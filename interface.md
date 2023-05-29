ADD_METHOD_TO(UserGroupController::add, "/{1}/add", Post);
{
    "uuids" : [], // 除自己的uuid
}
{
    "status" : 0,
    "message" : "",
    "result" : null
}
ADD_METHOD_TO(UserGroupController::addTx, "/{1}/addTx", Post);
{
    "guuid" : "", // 群组的uuid
}
{
    "status" : 0,
    "message" : "",
    "result" : null
}
ADD_METHOD_TO(UserGroupController::cancel, "/{1}/cancel", Post);
{
    "txuuid" : "",
}
ADD_METHOD_TO(UserGroupController::confirm, "/{1}/confirm", Post);
{
    "txuuid" : "",
}
ADD_METHOD_TO(UserGroupController::getInfo, "/{1}/getInfo", Get);
//有哪些群组 群组里我的顺序

ADD_METHOD_TO(UserGroupController::getConfirm, "/{1}/getConfirm", Get);
{

}

ADD_METHOD_TO(UserController::login, "/login", Post, Options)
{
    "account" : "",
    "password" : ""
}