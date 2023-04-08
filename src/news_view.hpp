#pragma once

#include <json.hpp>
#include <borealis.hpp>
using json = nlohmann::json;

class News
{
  public:
    std::vector<std::string> images;
    json json_news;

    std::string title;
    std::string content;

    News(json news_json)
        :json_news(news_json)
    {}

    News() {
      title = "error";
      content = "error";
    }
};

class NewsView : public brls::Box
{
  public:
    NewsView(News news);
    NewsView()
        : NewsView(News())
    {
    }

    static brls::View* create();

  private:
    News news;
    BRLS_BIND(brls::Image, image, "image");
    BRLS_BIND(brls::Label, content, "content");
    BRLS_BIND(brls::Image, image_content, "image_content");
    BRLS_BIND(brls::Image, image_content2, "image_content2");
    BRLS_BIND(brls::Image, image_content3, "image_content3");
};
