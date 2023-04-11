#include <switch.h>

#include "main_activity.hpp"
#include "news_view.hpp"
#include "recycling_list_tab.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <borealis.hpp>
#include <string>

using namespace brls::literals;

int main(int argc, char* argv[]) {
    appletInitializeGamePlayRecording();
    //Debug logs
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    // Init the app and i18n
    if (!brls::Application::init()) {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }

    // Create the window
    brls::Application::createWindow("Logic Sunrise News");

    //have the application register an action on every activity that will quit when you press BUTTON_SATRT
    brls::Application::setGlobalQuit(false);

    // Register custom views (including tabs, which are views)
    brls::Application::registerXMLView("RecyclingListTab", RecyclingListTab::create);
    brls::Application::registerXMLView("NewsView", NewsView::create);

    // Add custom values to the theme
    brls::getLightTheme().addColor("captioned_image/caption", nvgRGB(2, 176, 183));
    brls::getDarkTheme().addColor("captioned_image/caption", nvgRGB(51, 186, 227));

    // Add custom values to the style
    brls::getStyle().addMetric("about/padding_top_bottom", 50);
    brls::getStyle().addMetric("about/padding_sides", 75);
    brls::getStyle().addMetric("about/description_margin", 50);

    // Create and push the main activity to the stack
    brls::Application::pushActivity(new MainActivity());

    
    
    // Run the app
    while (brls::Application::mainLoop())
        ;

    // Exit
    return EXIT_SUCCESS;
}
