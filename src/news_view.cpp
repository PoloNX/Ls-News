#include "news_view.hpp"

#include "download.hpp"
#include <borealis/core/i18n.hpp>
#include <memory>
#include "parse.hpp"

using namespace brls::literals;

bool dismissView(brls::View* view, NewsView* pock)
{
    return true;
}

NewsView::NewsView(News news)
    : news(news)
{
    // Inflate the tab from the XML file
    this->inflateFromXMLRes("xml/views/news.xml");

    auto dismissAction = [this](View* view) {
        this->dismiss();
        return true;
    };

    brls::Box* holder = new brls::Box();
    holder->setFocusable(true);

    holder->addGestureRecognizer(new brls::TapGestureRecognizer(holder));

    getAppletFrameItem()->title = news.json_news["title"].get<std::string>();
    getAppletFrameItem()->setIconFromRes("img/logic_sunrise.jpg");
    getAppletFrameItem()->getHintView();

    content->setText(news.json_news["content"].get<std::string>());
    

    std::vector<unsigned char> buffer;
    net::downloadImage(news.images[0], buffer);
    brls::Logger().info("Downloaded image, size : {}, link : {}", buffer.size(), news.images[0]);
    image_content1->setImageFromMem(buffer.data(), buffer.size());
}

brls::View* NewsView::create()
{
    // Called by the XML engine to create a new ComponentsTab
    return new NewsView();
}
