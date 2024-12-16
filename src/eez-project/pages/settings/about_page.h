#pragma once

#include "../page.h"

class AboutPage : public Page {
public:
    AboutPage(io_service& io_service)
        : Page(io_service) {}
        
    void init() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
}; 