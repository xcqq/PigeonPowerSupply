#include "about_page.h"
#include "config.h"

void AboutPage::init() {
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VERSION, StringValue(VERSION));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_COMPILE_DATE, StringValue(COMPILE_DATE));
}
void AboutPage::handle_short_press(uint8_t keys) {
    if (keys == KEY_M5_A) {
        eez_flow_set_screen(SCREEN_ID_ROOT_SETTING_PAGE, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0);
    }
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}
void AboutPage::update() {
    uint8_t keys;
    key_state state = io.get_key_state(keys);
    if (state == KEY_PRESSED) handle_short_press(keys);
}