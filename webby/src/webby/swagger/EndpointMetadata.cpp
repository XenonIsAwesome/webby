#include "EndpointMetadata.h"

namespace swg = webby::swagger;

swg::EndpointMetadata swg::EndpointMetadata::add_parameter(Parameter&& parameter) {
    this->parameters.emplace_back(std::move(parameter));
    return {std::move(summary), std::move(parameters), std::move(responses)};
}

swg::EndpointMetadata swg::EndpointMetadata::add_response(size_t status_code, Response&& res) {
    this->responses[status_code] = std::move(res);
    return {std::move(summary), std::move(parameters), std::move(responses)};
}

swg::EndpointMetadata swg::EndpointMetadata::add_parameter(std::string name, ParameterLocation in, std::string type, bool required) {
    return std::move(add_parameter(std::move(
        Parameter(std::move(name), in, std::move(type), required)
    )));
}

swg::EndpointMetadata swg::EndpointMetadata::add_response(size_t status_code, std::string description) {
    return std::move(add_response(status_code, std::move(
        Response(std::move(description))
    )));
}
