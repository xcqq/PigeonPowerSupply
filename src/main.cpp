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
io_service io;           /* IO control service */
display_service display; /* display service */
UserActions user_actions(io);

static void vTaskIO(void *params)
{
    for (;;)
        io.loop();
}

static void vTaskDisplay(void *params)
{
    display.setup();
    io.setup();
    user_actions.setup();
    xTaskCreatePinnedToCore(vTaskIO,  /* Task function */
                            "io",     /* Task name */
                            10000,    /* Stack size */
                            NULL,     /* Parameters */
                            1,        /* Priority */
                            &task_io, /* Task handle */
                            1         /* CPU core 1 */
    );
    for (;;) {
        display.loop();
        user_actions.loop();
    }
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