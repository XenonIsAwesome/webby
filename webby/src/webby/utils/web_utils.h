#pragma once

#include <httplib.h>

namespace webby::utils {
    /**
     * Logs a given request the same way FastAPI does.
     * (Or as close as possible)
     *
     * @param req The request object
     * @param res The response object (to show the http status code)
     */
    void log_request(const httplib::Request &req, httplib::Response &res);
};

/**
 * A helper macro to handle a request,
 * wraps around the handler and adds headers.
 * Also logs the request using `webby::utils::log_request`
 *
 * @param SERVER The server object
 * @param METHOD The http method of this endpoint
 * @param PATH The path of this endpoint
 * @param HANDLER The handler function
 */
#define HANDLE_REQUEST(SERVER, METHOD, PATH, HANDLER)                                   \
    SERVER.METHOD(PATH, [](const httplib::Request &req, httplib::Response &res){        \
        /* Adding headers */                                                            \
        res.set_header("Access-Control-Allow-Origin", "*");                             \
        res.set_header("Access-Control-Allow-Methods", req.method);                     \
        res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");  \
                                                                                        \
        /* Calling the handler */                                                       \
        res.status = httplib::OK_200;                                                   \
        HANDLER(req, res);                                                              \
                                                                                        \
        /* Logging the request */                                                       \
        webby::utils::log_request(req, res);                                            \
    });
