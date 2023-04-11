#include "news_view.hpp"

#include "download.hpp"
#include <borealis/core/i18n.hpp>
#include <memory>

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
    
    for (int i = 0; i < news.images.size(); i++) {
        std::vector<unsigned char> buffer;
        net::downloadImage(news.images[i], buffer);
        brls::Logger().info("Downloaded image, size : {}, link : {}", buffer.size(), news.images[0]);
        if (i == 0) {
            image_content1->setImageFromMem(buffer.data(), buffer.size());
        }
        else if (i == 1) {
            image_content2->setImageFromMem(buffer.data(), buffer.size());
        }
        else if (i == 2){
            image_content3->setImageFromMem(buffer.data(), buffer.size());
        }
        else {
            brls::Logger().info("Too many images");
            continue;
        }
    }

    if (news.images.size() == 1) {
        image_content1->setWidth(1150);
        image_content1->setHeight(646);
    }
    else if (news.images.size() == 2) {
        image_content1->setWidthPercentage(50);
        image_content2->setWidthPercentage(50);
    }
    else {
        image_content1->setWidthPercentage(33);
        image_content2->setWidthPercentage(33);
        image_content3->setWidthPercentage(33);
    }
}

brls::View* NewsView::create()
{
    // Called by the XML engine to create a new ComponentsTab
    return new NewsView();
}
