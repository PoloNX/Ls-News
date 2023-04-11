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
    {
      for (auto i = 0; i < news_json.at("images").size(); i++) {
        images.push_back(news_json.at("images")["image_"+std::to_string(i+1)]);
        brls::Logger().info("Image : {}", images[i]);
      }
    }

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
    BRLS_BIND(brls::Image, image_content1, "image_content1");
    BRLS_BIND(brls::Image, image_content2, "image_content2");
    BRLS_BIND(brls::Image, image_content3, "image_content3");
};
