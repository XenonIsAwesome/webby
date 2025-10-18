#include "web_utils.h"
#include "string_utils.h"
#include <sstream>

void webby::utils::log_request(const httplib::Request &req, httplib::Response &res) {
    std::stringstream ss;
    ss << "INFO: " << req.remote_addr << ":" << req.remote_port;
    ss << " - " << req.method << " " << req.path;

    if (!req.params.empty()) {
        ss << "?" << httplib::detail::params_to_query_str(req.params);
    }

    ss << " " << req.version << " -> " << res.status;

    std::cout << ss.str() << std::endl;
}
