#pragma once

#include <lvgl.h>
#include "io_service.h"
#include "../screens.h"
#include "../structs.h"
#include "../ui.h"

class Page {
protected:
    io_service& io;

public:
    Page(io_service& io_service) 
        : io(io_service) {}
    virtual ~Page() = default;

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void handle_short_press(uint8_t keys){};
    virtual void handle_long_press(uint8_t keys) {};
    virtual void handle_encoder(const hmi_module_status& hmi_status) {};
};