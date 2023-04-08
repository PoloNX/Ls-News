#include "parse.hpp"

namespace parse {
    json parseJson()
    {
        std::ifstream file("romfs:/json/news.json");
        json j = json::parse(file);
        return j;
    }
}