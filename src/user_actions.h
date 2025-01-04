#pragma once

#include "io_service.h"
#include "eez-project/pages/page.h"
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <stack>

class UserActions {
private:
    Page* current_page;
    std::map<std::string, std::unique_ptr<Page>> pages;
    std::stack<Page*> page_stack;  // Stack to store page pointers for navigation history
    io_service& io;
    struct TimerTask {
        TimerHandle_t timer_handle;
        TimerCallbackFunction_t callback;
        const char* name;
        uint32_t period_ms;
        bool auto_reload;
    };
    std::vector<TimerTask> timer_tasks;

    static constexpr int UPDATE_INTERVAL_MS = 20; //50hz
    static constexpr int SLOW_UPDATE_INTERVAL_MS = 100; //10hz

    void handleKeys();
    void handleEncoder();
    void updatePages();

public:
    UserActions(io_service& io) : io(io), current_page(nullptr) {}
    
    void registerPage(const std::string& id, Page* page) {
        pages[id] = std::unique_ptr<Page>(page);
    }

    void switchToPage(const std::string& id);

    // Go back to previous page in the navigation stack
    bool goBack();

    Page* getCurrentPage() {
        return current_page;
    }

    // Get current navigation stack depth
    size_t getStackDepth() const {
        return page_stack.size();
    }

    io_service& getIO() { return io; }

    TimerHandle_t registerTimer(const char *name, TimerCallbackFunction_t callback,
                                uint32_t period_ms, bool auto_reload = true);
    void unregisterTimer(TimerHandle_t timer);

    void setup();
    void loop();
};
