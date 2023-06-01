#ifndef MISC_HPP_
#define MISC_HPP_

#include <drogon/HttpAppFramework.h>
#include <json/value.h>
#include <algorithm>

enum class StatusCode { OK, ERROR };
#define TO_STATUS(x) static_cast<int>(StatusCode::x)
inline Json::Value error_json(const std::string &message) {
    Json::Value ret;
    ret["status"] = TO_STATUS(ERROR);
    ret["message"] = message;
    ret["result"]; // create a null member if it does not exist.
    return ret;
}
inline Json::Value success_json(Json::Value result) {
    Json::Value ret;
    ret["status"] = TO_STATUS(OK);
    ret["message"]; // create a null member if it does not exist.
    ret["result"] = std::move(result);
    return ret;
}
inline bool uuids_equal(const std::vector<std::string> &lhs,
                 const std::vector<std::string> &rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    // 前置条件 lhs与rhs都未重
    for (auto &&s : lhs) {
        if (std::find(rhs.begin(), rhs.end(), s) == rhs.end()) {
            return false;
        }
    }
    return true;
}
auto inline getDbClient() { return drogon::app().getDbClient("default"); }
template<class Container, class Func>
Container& filter (Container& container, Func func){
    auto end = std::remove_if(container.begin(), container.end(), func);
    container.erase(end, container.end());
}
#undef TO_STATUS
#endif // MISC_HPP_
