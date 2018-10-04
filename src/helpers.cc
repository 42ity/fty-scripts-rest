#include "helpers.h"

void operator>>=(const cxxtools::SerializationInfo &si, std::vector<std::string> &out) {
    if (si.category() != cxxtools::SerializationInfo::Category::Array) {
        throw std::runtime_error("");
    }

    for (const auto &i : si) {
        if (i.category() != cxxtools::SerializationInfo::Category::Value) {
            throw std::runtime_error("");
        }

        std::string value;
        i.getValue(value);
        out.push_back(value);
    }
}
