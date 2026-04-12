/**
 * main.c
 * Hybrid RobotiX — Blinky-RGB
 *
 * Demonstrates use of hybx_led_utilities for:
 *   - Blinking a standard GPIO LED
 *   - Blinking an RGB LED with a packed 32-bit color value
 *
 * Target board: Arduino Nano ESP32
 * Pin definitions: see include/hybx_led_utilities.h
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hybx_led_utilities.h"

//  Main Application
void app_main(void) {

    uint32_t color = 0;

    //  Initialization
    hybx_init_rgb_led();

    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    //  Main Loop
    while (1) {

        //  Blink the yellow LED twice
        hybx_blink_led(LED_PIN, BLINK_DELAY_MS, 2);

        //  Blink the RGB LED blue twice
        color = hybx_rgb_color_32(0, 0, 175);
        hybx_blink_led_rgb(color, BLINK_DELAY_MS, 2);

        //  End of Main Loop
        vTaskDelay(pdMS_TO_TICKS(LOOP_DELAY_MS));
    }

}
