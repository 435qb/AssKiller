#include <drogon/drogon.h>
int main(int argc, char *argv[]) {
    //Set HTTP listener address and port
    // drogon::app().addListener("0.0.0.0",13456);
    //Load config file
    std::string config_path = "./config.json";
    if(argc > 1){
        config_path = argv[1];
    }
    drogon::app().loadConfigFile(config_path);
    std::string corsValue = drogon::app().getCustomConfig()["cors"].asString();
    LOG_DEBUG << corsValue;
    drogon::app()
    	.registerPostHandlingAdvice(
    		[&](const drogon::HttpRequestPtr &req, const drogon::HttpResponsePtr &resp) {
            //LOG_DEBUG << "postHandling1";
            resp->addHeader("Access-Control-Allow-Origin", corsValue);
        });
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
