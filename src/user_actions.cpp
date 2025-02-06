#include "user_actions.h"
#include "config.h"
#include "eez-project/pages/page.h"
#include "eez-project/pages/home_page.h"
#include "eez-project/pages/settings/about_page.h"
#include "eez-project/pages/settings/other_setting_page.h"
#include "eez-project/pages/settings/protect_limit_page.h"
#include "eez-project/pages/settings/root_setting_page.h"
#include "eez-project/i18n/lv_i18n.h"

void UserActions::switchToPage(const std::string &id)
{
    LOG_DEBUG("Switching to page: %s", id.c_str());
    if (current_page) {
        current_page->onExit();
    }

    auto it = pages.find(id);
    if (it != pages.end()) {
        if (current_page) {
            page_stack.push(current_page);
        }
        current_page = it->second.get();
        eez_flow_push_screen(current_page->getScreenId(), LV_SCR_LOAD_ANIM_FADE_IN, 200, 0);
        current_page->onInit();
        current_page->onEnter();
        LOG_INFO("Page switched to: %s", id.c_str());
    } else {
        LOG_ERROR("Page not found: %s", id.c_str());
    }
}

bool UserActions::goBack()
{
    if (page_stack.empty()) {
        LOG_DEBUG("Cannot go back: page stack is empty");
        return false;
    }

    if (current_page) {
        LOG_DEBUG("Exiting current page: %d", current_page->getScreenId());
        current_page->onExit();
        current_page->onDestroy();
    }

    eez_flow_pop_screen(LV_SCR_LOAD_ANIM_FADE_IN, 200, 0);
    current_page = page_stack.top();
    page_stack.pop();
    
    current_page->onEnter();
    LOG_INFO("Returned to page: %d", current_page->getScreenId());
    return true;
}

void UserActions::handleKeys() {
    if (!current_page) return;
    
    uint8_t keys;
    key_state state = io.get_key_state(keys);
    
    if (state == KEY_PRESSED) {
        current_page->handle_short_press(keys);
    }
    else if (state == KEY_LONG_PRESSED) {
        current_page->handle_long_press(keys);
    }
}

void UserActions::handleEncoder() {
    if (!current_page) return;
    
    hmi_module_status hmi_status = io.get_hmi_module_status();
    if (hmi_status.encoder_inc) {
        current_page->handle_encoder(hmi_status);
    }
}

void UserActions::updatePages() {
    if (!current_page) return;

    static uint32_t last_update = 0;
    uint32_t now = xTaskGetTickCount();
    
    if (now - last_update >= pdMS_TO_TICKS(UPDATE_INTERVAL_MS)) {
        last_update = now;
        current_page->update();
    } else if (now - last_update >= pdMS_TO_TICKS(SLOW_UPDATE_INTERVAL_MS)) {
        current_page->slowUpdate();
    }
}

TimerHandle_t UserActions::registerTimer(const char *name, TimerCallbackFunction_t callback,
                                         uint32_t period_ms, bool auto_reload)
{
    LOG_DEBUG("Registering timer: %s (period: %dms, auto_reload: %d)", 
              name, period_ms, auto_reload);
    TimerHandle_t timer = xTimerCreate(name, pdMS_TO_TICKS(period_ms),
                                       auto_reload ? pdTRUE : pdFALSE, nullptr, callback);

    if (timer != nullptr) {
        timer_tasks.push_back({timer, callback, name, period_ms, auto_reload});
        xTimerStart(timer, 0);
        LOG_DEBUG("Timer registered successfully");
    } else {
        LOG_ERROR("Failed to create timer: %s", name);
    }
    return timer;
}

void UserActions::unregisterTimer(TimerHandle_t timer)
{
    auto it = std::find_if(timer_tasks.begin(), timer_tasks.end(),
                           [timer](const TimerTask &task) { return task.timer_handle == timer; });

    if (it != timer_tasks.end()) {
        LOG_DEBUG("Unregistering timer: %s", it->name.c_str());
        xTimerDelete(it->timer_handle, 0);
        timer_tasks.erase(it);
    } else {
        LOG_ERROR("Timer not found for unregistering");
    }
}

void UserActions::setup()
{
    LOG_INFO("Initializing user actions...");
    registerPage(HomePage::PAGE_NAME, new HomePage(*this, io));
    registerPage(RootSettingPage::PAGE_NAME, new RootSettingPage(*this, io));
    registerPage(OtherSettingPage::PAGE_NAME, new OtherSettingPage(*this, io));
    registerPage(ProtectLimitPage::PAGE_NAME, new ProtectLimitPage(*this, io));
    registerPage(AboutPage::PAGE_NAME, new AboutPage(*this, io));
    LOG_DEBUG("All pages registered");

    // init language
    const char* language = io.get_language();
    lv_i18n_init(lv_i18n_language_pack);
    lv_i18n_set_locale(language);
    LOG_INFO("Language set to: %s", language);

    // init eez ui
    ui_init();
    extern void ui_init_input_groups();
    ui_init_input_groups();

    // switch to default page
    switchToPage(HomePage::PAGE_NAME);
    LOG_INFO("User actions initialization completed");
}

void UserActions::loop() {
    handleKeys();
    handleEncoder();
    updatePages();
    delay(1);
}
