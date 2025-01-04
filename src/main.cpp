#include "M5Stack.h"
#include <Arduino.h>
#undef min
#include "M5Module-PPS/M5ModulePPS.h"
#include "config.h"
#include "display_service.h"
#include "io_service.h"
#include "user_actions.h"

static TaskHandle_t task_display;
static TaskHandle_t task_io;
static TaskHandle_t task_action;
io_service io;           /* IO control service */
display_service display; /* display service */
UserActions user_actions(io);

static void vTaskAction(void *params)
{
    user_actions.setup();
    for (;;)
        user_actions.loop();
}

static void vTaskIO(void *params)
{
    io.setup();
    xTaskCreatePinnedToCore(vTaskAction,  /* Task function */
                            "action",     /* Task name */
                            10000,        /* Stack size */
                            NULL,         /* Parameters */
                            2,            /* Priority */
                            &task_action, /* Task handle */
                            0             /* CPU core 0 */
    );
    for (;;)
        io.loop();
}

static void vTaskDisplay(void *params)
{
    display.setup();
    xTaskCreatePinnedToCore(vTaskIO,  /* Task function */
                            "io",     /* Task name */
                            10000,    /* Stack size */
                            NULL,     /* Parameters */
                            1,        /* Priority */
                            &task_io, /* Task handle */
                            1         /* CPU core 1 */
    );
    for (;;)
        display.loop();
}

void setup(void)
{
    M5.begin();

    xTaskCreatePinnedToCore(vTaskDisplay,  /* Task function */
                            "display",     /* Task name */
                            10000,         /* Stack size */
                            NULL,          /* Parameters */
                            1,             /* Priority */
                            &task_display, /* Task handle */
                            0              /* CPU core 0 */
    );


}

void loop(void) { /* Main loop is empty as work is done in tasks */ }