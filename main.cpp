#include <iostream>

#include <httplib.h>
#include <fstream>
#include <webby/swagger/SwaggerGenerator.h>
#include <webby/utils/web_utils.h>
#include <webby/routes.hpp>

namespace swg = webby::swagger;

int main() {
    auto registry = webby::EndpointRegistry::getInstance();

    [[maybe_unused]] static webby::RegisterEndpoint _register_main([](httplib::Server& svr) {
        DECLARE_ENDPOINT(
            svr, Get, "/", swg::EndpointMetadata("System Status")
                            .add_response(httplib::OK_200, "OK"),
            [](const httplib::Request &req, httplib::Response &res) {
                res.status = httplib::OK_200;
                res.set_content("true", "application/json");
            }
        )
    });

    registry->start("0.0.0.0", 8081);

    return 0;
}