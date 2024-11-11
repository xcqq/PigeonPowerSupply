#include <Arduino.h>
#include "M5Stack.h"
#include "M5Module-PPS/M5ModulePPS.h"
#include "config.h"
#include "io_service.h"
#include "display_service.h"

static TaskHandle_t task_cpu0;
static TaskHandle_t task_cpu1;
io_service io;          /* IO control service */
display_service display; /* display service */

static inline void loop_cpu0(void)
{
    display.loop();
}

static inline void loop_cpu1(void)
{
    io.loop();
}

static void setup_cpu0(void *params)
{
    display.setup();
    for (;;)
        loop_cpu0();
}

static void setup_cpu1(void *params)
{
    io.setup();
    for (;;)
        loop_cpu1();
}

void setup(void)
{
    M5.begin();

    xTaskCreatePinnedToCore(
        setup_cpu0,  /* Task function */
        "cpu0",      /* Task name */
        10000,       /* Stack size */
        NULL,        /* Parameters */
        1,           /* Priority */
        &task_cpu0,  /* Task handle */
        0            /* CPU core 0 */
    );

    xTaskCreatePinnedToCore(
        setup_cpu1,  /* Task function */
        "cpu1",      /* Task name */
        10000,       /* Stack size */
        NULL,        /* Parameters */
        1,           /* Priority */
        &task_cpu1,  /* Task handle */
        1            /* CPU core 1 */
    );
}

void loop(void)
{
    /* Main loop is empty as work is done in tasks */
}