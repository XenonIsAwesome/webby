#include "string_utils.h"
#include <algorithm>

std::string webby::utils::stolower(const std::string &str) {
    std::string cpy = str;
    std::ranges::transform(cpy, cpy.begin(),
        [](const unsigned char c){ return std::tolower(c); });
    return std::move(cpy);
}

std::string webby::utils::stoupper(const std::string &str) {
    std::string cpy = str;
    std::ranges::transform(cpy, cpy.begin(),
        [](const unsigned char c){ return std::toupper(c); });
    return std::move(cpy);
}

