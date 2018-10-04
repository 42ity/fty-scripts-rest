#ifndef FTY_SCRIPTS_REST_HELPERS_H
#define FTY_SCRIPTS_REST_HELPERS_H

#include <stdexcept>
#include <string>
#include <vector>
#include <cxxtools/serializationinfo.h>

void operator>>=(const cxxtools::SerializationInfo &si, std::vector<std::string> &out);

#endif
