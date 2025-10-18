#include <webby/routes.hpp>
#include <webby/swagger/SwaggerGenerator.h>
#include <iostream>

namespace swg = webby::swagger;

[[maybe_unused]] static webby::RegisterEndpoint _register_project2([](httplib::Server& svr) {
    DECLARE_ENDPOINT(svr, Post, "/api/missions/project2/",
        swg::EndpointMetadata("")
            .add_parameter("name", swg::ParameterLocation::URL_QUERY, "string", false)
            .add_response(httplib::OK_200, "Successful request"),
        [](const httplib::Request &req, httplib::Response &res) {
            res.status = httplib::OK_200;
            if (req.has_param("name")) {
                auto name = req.get_param_value("name");
                res.set_content("{\"name\": \"" + name + "\"}", "application/json");
            } else {
                res.set_content("false", "application/json");
            }
        }
    )
});