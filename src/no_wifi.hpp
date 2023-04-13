#pragma once

#include <borealis.hpp>

class NoWifi : public brls::Activity {
public:
    CONTENT_FROM_XML_RES("activity/nowifi.xml");
};
