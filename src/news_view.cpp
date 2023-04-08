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

    /*std::vector<char> buffer;
    net::downloadImage("http://www.logic-sunrise.com/images/news/1171859/in-switch-nintendo-va-reparer-gratuitement-les-joy-con-meme-sans-garantie-2.png", buffer);
    unsigned char* buffer2 = reinterpret_cast<unsigned char*>(buffer.data());
    image->setImageFromMem(buffer2, buffer.size());*/
}

brls::View* NewsView::create()
{
    // Called by the XML engine to create a new ComponentsTab
    return new NewsView();
}
