#ifndef FTY_SCRIPTS_REST_HELPERS_H
#define FTY_SCRIPTS_REST_HELPERS_H

#include <stdexcept>
#include <string>
#include <vector>
#include <cxxtools/serializationinfo.h>

void operator>>=(const cxxtools::SerializationInfo &si, std::vector<std::string> &out);

const std::string SCRIPT_FILENAME_REGEX = "^[a-zA-Z0-9][a-zA-Z0-9_.-]{0,254}$";
const std::string SCRIPT_DIRECTORY = "/var/lib/fty/fty-scripts-rest/";

const int SCRIPT_FILE_MAX_SIZE = 64*1024;
const int SCRIPT_MAX_FILES = 256;

#endif
