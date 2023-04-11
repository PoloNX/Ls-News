#include "download.hpp"
#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <fstream>

namespace net {

    struct MemoryStruct
    {
        char* memory;
        size_t size;
    };

    size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata)
    {
        std::vector<unsigned char>* buffer = static_cast<std::vector<unsigned char>*>(userdata);
        size_t total_size = size * nmemb;
        buffer->insert(buffer->end(), ptr, ptr + total_size);
        return total_size;
    }

    size_t write_callback2(void* contents, size_t size, size_t nmemb, void* userp)
    {
        size_t realsize = size * nmemb;
        struct MemoryStruct* mem = (struct MemoryStruct*)userp;

        char* ptr = static_cast<char*>(realloc(mem->memory, mem->size + realsize + 1));
        if (ptr == NULL) {
            /* out of memory! */
            return 0;
        }

        mem->memory = ptr;
        memcpy(&(mem->memory[mem->size]), contents, realsize);
        mem->size += realsize;
        mem->memory[mem->size] = 0;

        return realsize;
    }

    void downloadImage(const std::string& url, std::vector<unsigned char>& buffer)
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

        long downloadPage(const std::string& url, std::string& res, const std::vector<std::string>& headers, const std::string& body)
    {
        CURL* curl_handle;
        struct MemoryStruct chunk;
        struct curl_slist* list = NULL;
        long status_code;

        chunk.memory = static_cast<char*>(malloc(1)); /* will be grown as needed by the realloc above */
        chunk.size = 0;                               /* no data at this point */

        curl_global_init(CURL_GLOBAL_ALL);
        curl_handle = curl_easy_init();
        curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
        if (!headers.empty()) {
            for (auto& h : headers) {
                list = curl_slist_append(list, h.c_str());
            }
            curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, list);
        }
        if (body != "") {
            curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, body.c_str());
        }

        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback2);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "SWITCH");

        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_perform(curl_handle);
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &status_code);
        curl_easy_cleanup(curl_handle);
        res = std::string(chunk.memory);
        free(chunk.memory);

        curl_global_cleanup();
        return status_code;
    }

    json getRequest(const std::string& url, const std::vector<std::string>& headers, const std::string& body)
    {
        std::string request;
        long status_code = downloadPage(url, request, headers, body);

        if (json::accept(request))
            return nlohmann::ordered_json::parse(request);
        else
            return nlohmann::ordered_json::object();

    }

}