#pragma once

#include <json.hpp>
#include <borealis.hpp>
#include <string>
#include <fstream>
using json = nlohmann::json;

namespace parse {
    json parseJson();
}