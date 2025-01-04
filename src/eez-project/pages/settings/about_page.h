#pragma once

#include "../page.h"

class AboutPage : public Page
{
public:
    static const std::string PAGE_NAME;
    int getScreenId() const override { return SCREEN_ID_ABOUT_PAGE; }
    AboutPage(UserActions &user_actions, io_service &io) : Page(user_actions, io) {}

    void onInit() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
};