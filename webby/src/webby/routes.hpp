#pragma once

#include <vector>
#include <functional>
#include <httplib.h>
#include <webby/swagger/SwaggerGenerator.h>
#include <webby/utils/Singleton.hpp>

namespace webby {
    /**
     * A registry of all the endpoints in the server
     */
    class EndpointRegistry: public utils::Singleton<EndpointRegistry> {
    public:
        using EndpointRegisterHandler = std::function<void(httplib::Server& svr)>;

        /**
         * Registers all the endpoints, generates the swagger and starts the server.
         *
         * @param bind_addr The address to listen on
         * @param port The port to listen on
         */
        static void start(const std::string& bind_addr, uint16_t port);

        /**
         * Registers all the endpoints using the collected `EndpointRegisterHandler`
         */
        static void register_all();

        /**
         * Adds a handler to the registered endpoints collection
         * @param handler Handler function to register the endpoint.
         */
        static void register_endpoint(EndpointRegisterHandler handler);

        /**
         * @return The instance of the httplib server.
         */
        static httplib::Server& get_server();

    private:
        httplib::Server svr;
        std::vector<EndpointRegisterHandler> registry;
    };

    /**
     * Helper struct to register an endpoint.
     */
    struct RegisterEndpoint {
        RegisterEndpoint(std::function<void(httplib::Server&)> f) {
            EndpointRegistry::register_endpoint(f);
        }
    };
}
