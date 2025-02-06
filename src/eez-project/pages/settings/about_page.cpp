#include "about_page.h"
#include "./root_setting_page.h"
#include "config.h"
#include "user_actions.h"

const std::string AboutPage::PAGE_NAME = "about";

void AboutPage::onInit()
{
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VERSION, StringValue(VERSION));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_COMPILE_DATE, StringValue(COMPILE_DATE));
}

void AboutPage::handle_short_press(uint8_t keys)
{
    if (keys == KEY_M5_A) {
        user_actions.goBack();
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
    }
}

void AboutPage::update() {}