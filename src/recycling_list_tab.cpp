#include "recycling_list_tab.hpp"
#include "news_view.hpp"
#include <iostream>
#include "download.hpp"

std::vector<News> news;
json json_file = net::getRequest("https://raw.githubusercontent.com/PoloNX/ls-links/master/news.json");

RecyclerCell::RecyclerCell()
{
    this->inflateFromXMLRes("xml/cells/cell.xml");
}

RecyclerCell* RecyclerCell::create()
{
    return new RecyclerCell();
}

// DATA SOURCE

int DataSource::numberOfSections(brls::RecyclerFrame* recycler)
{
    return 1;
}

int DataSource::numberOfRows(brls::RecyclerFrame* recycler, int section)
{
    return 20;
}
    
std::string DataSource::titleForHeader(brls::RecyclerFrame* recycler, int section) 
{
    if (section == 0)
        return "";
    return "Section #" + std::to_string(section+1);
}

brls::RecyclerCell* DataSource::cellForRow(brls::RecyclerFrame* recycler, brls::IndexPath indexPath)
{
    RecyclerCell* item = (RecyclerCell*)recycler->dequeueReusableCell("Cell");

    std::vector<json> json_news;
    for (auto i = 0; i < 20; i++) {
        json_news.push_back(json_file.at("news_"+std::to_string(i+1)));
    }

    item->label->setText(json_news[indexPath.row]["title"]);
    item->image->setImageFromRes("img/logic_sunrise.jpg");
    return item;
}

void DataSource::didSelectRowAt(brls::RecyclerFrame* recycler, brls::IndexPath indexPath)
{
//    brls::Logger::info("Item Index(" + std::to_string(index.section) + ":""" + std::to_string(index.row) + ") selected.");
    recycler->present(new NewsView(news[indexPath.item]));
}

// RECYCLER VIEW

RecyclingListTab::RecyclingListTab()
{
    // Inflate the tab from the XML file
    this->inflateFromXMLRes("xml/tabs/recycling_list.xml");
    

    


    std::vector<json> json_news;
    for (auto i = 0; i < 20; i++) {
        json_news.push_back(json_file.at("news_"+std::to_string(i+1)));
    }

    news.clear();
    for (auto i = 0; i < json_news.size(); i++) {
        news.push_back(News(json_news[i]));
    }

    recycler->estimatedRowHeight = 70;
    recycler->registerCell("Header", []() { return RecyclerHeader::create(); });
    recycler->registerCell("Cell", []() { return RecyclerCell::create(); });
    recycler->setDataSource(new DataSource());
}

brls::View* RecyclingListTab::create()
{
    // Called by the XML engine to create a new RecyclingListTab
    return new RecyclingListTab();
}
