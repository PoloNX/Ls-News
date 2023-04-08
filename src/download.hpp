#pragma once

constexpr int ON = 1;
constexpr int OFF = 0;

#include <curl/curl.h>
#include <memory>
#include <string>
#include <vector>

namespace net {
    void downloadImage(const std::string& url, std::vector<char>& buffer);
}