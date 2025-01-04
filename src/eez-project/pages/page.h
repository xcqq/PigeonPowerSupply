#pragma once

#include <lvgl.h>
#include "io_service.h"
#include "../screens.h"
#include "../structs.h"
#include "../ui.h"

class UserActions;
class io_service;

class Page {
protected:
    UserActions& user_actions;
    io_service& io;

public:
    virtual int getScreenId() const = 0;  // Pure virtual function
    
    Page(UserActions& user_actions, io_service& io) 
        : user_actions(user_actions), io(io) {}
    virtual ~Page() = default;

    // Lifecycle methods
    virtual void onInit() {}    // Called once when page is first created
    virtual void onEnter() {}   // Called each time page becomes active
    virtual void onExit() {}    // Called each time page becomes inactive
    virtual void onDestroy() {} // Called when page is being destroyed

    // Update methods
    virtual void update() {}    // Called frequently (50Hz)
    virtual void slowUpdate() {} // Called less frequently (10Hz)

    // Input handling methods
    virtual void handle_short_press(uint8_t keys) {}
    virtual void handle_long_press(uint8_t keys) {}
    virtual void handle_encoder(const hmi_module_status& hmi_status) {}
};
