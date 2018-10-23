#include "helpers.h"

void operator>>=(const cxxtools::SerializationInfo &si, std::vector<std::string> &out) {
    if (si.category() != cxxtools::SerializationInfo::Category::Array) {
        throw std::runtime_error("Parameter must be an array");
    }

    for (const auto &i : si) {
        if (i.category() != cxxtools::SerializationInfo::Category::Value) {
            throw std::runtime_error("Elements of array must be values");
        }

        std::string value;
        i.getValue(value);
        out.push_back(value);
    }
}
