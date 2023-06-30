/**
 *
 *  JwtFilter.cc
 *
 */

#include "JwtFilter.h"
#include <drogon/HttpAppFramework.h>
#include <exception>
#include <jwt-cpp/jwt.h>
using namespace drogon;

void JwtFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    if (req->getMethod() == HttpMethod::Options) return fccb();
    const std::string& token = req->getHeader("Authorization");
    // If the authorization header is empty or if the length is lower than 7 characters, means "Bearer " is not included on authorization header string.
    if (token.length() < 7) {
        Json::Value resultJson;
        resultJson["message"] = "No header authentication!";
        resultJson["status"] = 1;

        auto res = HttpResponse::newHttpJsonResponse(resultJson);
        res->setStatusCode(k401Unauthorized);

        // Return the response and let's tell this endpoint request was cancelled
        fcb(res);
        return;
    }
    auto error_retn = [&fcb](){
        Json::Value resultJson;
        resultJson["message"] = "鉴权失败";
        resultJson["status"] = 1;

        auto res = HttpResponse::newHttpJsonResponse(resultJson);
        res->setStatusCode(k401Unauthorized);

        // Return the response and let's tell this endpoint request was cancelled
        fcb(res);
    };

    std::string uuid_token;
    try {
        auto decoded = jwt::decode(token.substr(7));
        auto secret = drogon::app().getCustomConfig()["secret"].asString();
        auto verifier = jwt::verify()
            .allow_algorithm(jwt::algorithm::hs256{ secret })
            .with_issuer("auth0");
    
        verifier.verify(decoded); 
        uuid_token = decoded.get_payload_claim("uuid").as_string();

    } catch (std::exception &e) {
        LOG_DEBUG << e.what();
        error_retn();
        return;
    }

    auto path = req->getPath();
    
    auto start = path.find('/');
    if(start == std::string::npos){
        error_retn();
        return;
    }
    ++start;
    auto end = path.find('/', start);
    if(end == std::string::npos){
        error_retn();
        return;
    }
    auto uuid = path.substr(start, end - start);
    if(uuid_token != uuid){
        error_retn();
        return;
    }

    fccb();
    return;
}
