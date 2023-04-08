#include "download.hpp"
#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <fstream>

namespace net {

    size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata)
    {
        std::vector<char>* buffer = static_cast<std::vector<char>*>(userdata);
        size_t total_size = size * nmemb;
        buffer->insert(buffer->end(), ptr, ptr + total_size);
        return total_size;
    }

    void downloadImage(const std::string& url, std::vector<char>& buffer)
    {
        CURL* curl = curl_easy_init();
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            CURLcode result = curl_easy_perform(curl);
            if (result != CURLE_OK)
            {
                std::cout << curl_easy_strerror(result) << std::endl;
            }
            curl_easy_cleanup(curl);
        }
    }

}