#include "routes.hpp"

void webby::EndpointRegistry::start(const std::string& bind_addr, uint16_t port) {
    auto reg = getInstance();

    // Register all endpoints
    register_all();

    // Generate swagger.json
    swagger::SwaggerGenerator::generate("web playground", "1.0.0", reg->svr);

    // Listen on requested bind address and port
    reg->svr.listen(bind_addr, port);
}

void webby::EndpointRegistry::register_all() {
    auto reg = getInstance();
    for (auto& f : reg->registry) {
        f(reg->svr);
    }
}

void webby::EndpointRegistry::register_endpoint(EndpointRegisterHandler handler) {
    auto reg = getInstance();
    reg->registry.push_back(handler);
}

httplib::Server& webby::EndpointRegistry::get_server() {
    auto reg = getInstance();
    return reg->svr;
}