#pragma once

constexpr int ON = 1;
constexpr int OFF = 0;

#include <curl/curl.h>
#include <memory>
#include <string>
#include <vector>
#include <json.hpp>
using json = nlohmann::json;

namespace net {
    void downloadImage(const std::string& url, std::vector<unsigned char>& buffer);
    long downloadPage(const std::string& url, std::string& res, const std::vector<std::string>& headers = {}, const std::string& body = "");
    json getRequest(const std::string& url, const std::vector<std::string>& headers = {}, const std::string& body = "");
}