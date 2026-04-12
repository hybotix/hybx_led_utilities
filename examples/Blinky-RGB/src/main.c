/**
 * main.c
 * Hybrid RobotiX — hybx_led_utilities Blinky-RGB Example
 *
 * Demonstrates use of hybx_led_utilities for:
 *   - Blinking a standard GPIO LED
 *   - Blinking an RGB LED with a packed 32-bit color value
 *
 * Target board: Arduino Nano ESP32
 * Pin definitions: see include/globals.h
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include <stdint.h>
#include "globals.h"
#include "hybx_led_utilities.h"

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

        //  Blink the RGB LED blue
        color = hybx_rgb_color_32(0, 0, 175);
        hybx_blink_led_rgb(color, BLINK_DELAY_MS, 2);

        vTaskDelay(pdMS_TO_TICKS(LOOP_DELAY_MS));
    }

}
