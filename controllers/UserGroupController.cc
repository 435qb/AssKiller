#include "UserGroupController.h"

// Add definition of your processing function here
void UserGroupController::add(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {

}
void UserGroupController::cancel(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {
}
void UserGroupController::confirm(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {
}
void UserGroupController::getInfo(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {
}
void UserGroupController::getConfirm(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, std::string uuid) {
}