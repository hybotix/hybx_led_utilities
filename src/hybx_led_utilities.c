/**
 * hybx_led_utilities.c
 * Hybrid RobotiX — HybX LED Utilities
 *
 * Implementation of standard GPIO LED and RGB LED control via ESP-IDF LEDC.
 */

#include "hybx_led_utilities.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define HIGH 1
#define LOW  0

// ── Standard LED ──────────────────────────────────────────────────────────────

void hybx_blink_led(uint8_t pin, uint16_t delay_ms, uint8_t nr_cycles) {
    uint16_t cycles = 0;

    for (cycles = 0; cycles < nr_cycles; cycles++) {
        gpio_set_level(pin, HIGH);
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);

        gpio_set_level(pin, LOW);
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }
}

// ── RGB LED ───────────────────────────────────────────────────────────────────

void hybx_init_rgb_led(void) {
    ledc_timer_config_t rgb_timer = {
        .speed_mode      = LEDC_LOW_SPEED_MODE,
        .timer_num       = LEDC_TIMER_0,
        .duty_resolution = LEDC_TIMER_8_BIT,
        .freq_hz         = 5000,
        .clk_cfg         = LEDC_AUTO_CLK,
    };

    ledc_timer_config(&rgb_timer);

    ledc_channel_config_t rgb_red_ch = {
        .gpio_num   = LED_R,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel    = LEDC_CHANNEL_0,
        .timer_sel  = LEDC_TIMER_0,
        .duty       = 255,
        .hpoint     = 0,
    };

    ledc_channel_config_t rgb_green_ch = {
        .gpio_num   = LED_G,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel    = LEDC_CHANNEL_1,
        .timer_sel  = LEDC_TIMER_0,
        .duty       = 255,
        .hpoint     = 0,
    };

    ledc_channel_config_t rgb_blue_ch = {
        .gpio_num   = LED_B,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel    = LEDC_CHANNEL_2,
        .timer_sel  = LEDC_TIMER_0,
        .duty       = 255,
        .hpoint     = 0,
    };

    ledc_channel_config(&rgb_red_ch);
    ledc_channel_config(&rgb_green_ch);
    ledc_channel_config(&rgb_blue_ch);
}

uint32_t hybx_rgb_color_32(uint8_t red, uint8_t green, uint8_t blue) {
    return (red << 16) | (green << 8) | blue;
}

void hybx_set_rgb_color(uint32_t color) {
    uint8_t red   = (color >> 16) & 0xFF;
    uint8_t green = (color >> 8)  & 0xFF;
    uint8_t blue  =  color        & 0xFF;

    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 255 - red);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, 255 - green);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);

    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, 255 - blue);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);
}

void hybx_turn_rgb_on(uint32_t color) {
    hybx_set_rgb_color(color);
}

void hybx_turn_rgb_off(void) {
    ledc_stop(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 1);
    ledc_stop(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, 1);
    ledc_stop(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, 1);
}

void hybx_blink_led_rgb(uint32_t color, uint16_t delay_ms, uint8_t nr_cycles) {
    uint8_t cycles = 0;

    hybx_set_rgb_color(color);

    for (cycles = 0; cycles < nr_cycles; cycles++) {
        hybx_turn_rgb_on(color);
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);

        hybx_turn_rgb_off();
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }
}
