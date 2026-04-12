/**
 * hybx_led_utilities.h
 * Hybrid RobotiX — HybX LED Utilities
 *
 * Public API for standard GPIO LED and RGB LED control via ESP-IDF LEDC.
 *
 * Override default pin definitions by defining them before including this header.
 */

#pragma once

#include <stdint.h>
#include "driver/gpio.h"
#include "driver/ledc.h"

#ifdef __cplusplus
extern "C" {
#endif

// ── Default RGB LED pin definitions (Arduino Nano ESP32, common anode) ────────

#ifndef HYBX_LED_R
#define HYBX_LED_R GPIO_NUM_46
#endif

#ifndef HYBX_LED_G
#define HYBX_LED_G GPIO_NUM_0
#endif

#ifndef HYBX_LED_B
#define HYBX_LED_B GPIO_NUM_45
#endif

// ── Default standard LED pin definitions ──────────────────────────────────────

#ifndef LED_YELLOW
#define LED_YELLOW      GPIO_NUM_48
#endif

#ifndef LED_RED
#define LED_RED         GPIO_NUM_14
#endif

#ifndef LED_PIN
#define LED_PIN         LED_YELLOW
#endif

// ── Default control definitions ───────────────────────────────────────────────

#ifndef BLINK_DELAY_MS
#define BLINK_DELAY_MS  500
#endif

#ifndef LOOP_DELAY_MS
#define LOOP_DELAY_MS   1000
#endif

#define HIGH 1
#define LOW  0

// ── Standard LED ──────────────────────────────────────────────────────────────

/**
 * Blink a standard GPIO LED.
 *
 * @param pin         GPIO pin number
 * @param delay_ms    On/off delay in milliseconds
 * @param nr_cycles   Number of blink cycles
 */
void hybx_blink_led(uint8_t pin, uint16_t delay_ms, uint8_t nr_cycles);

// ── RGB LED ───────────────────────────────────────────────────────────────────

/**
 * Initialize the RGB LED via LEDC. All channels start off.
 * Uses HYBX_LED_R, HYBX_LED_G, HYBX_LED_B pin definitions.
 * Must be called once before any other RGB functions.
 */
void hybx_init_rgb_led(void);

/**
 * Pack red, green, blue values into a single 32-bit color value.
 *
 * @param red    Red component (0-255)
 * @param green  Green component (0-255)
 * @param blue   Blue component (0-255)
 * @return       Packed 32-bit color value
 */
uint32_t hybx_rgb_color_32(uint8_t red, uint8_t green, uint8_t blue);

/**
 * Set the RGB LED color via LEDC.
 *
 * @param color  Packed 32-bit color value from hybx_rgb_color_32()
 */
void hybx_set_rgb_color(uint32_t color);

/**
 * Turn the RGB LED on with the specified color.
 *
 * @param color  Packed 32-bit color value from hybx_rgb_color_32()
 */
void hybx_turn_rgb_on(uint32_t color);

/**
 * Turn the RGB LED fully off via ledc_stop().
 */
void hybx_turn_rgb_off(void);

/**
 * Blink the RGB LED with the specified color.
 *
 * @param color      Packed 32-bit color value from hybx_rgb_color_32()
 * @param delay_ms   On/off delay in milliseconds
 * @param nr_cycles  Number of blink cycles
 */
void hybx_blink_led_rgb(uint32_t color, uint16_t delay_ms, uint8_t nr_cycles);

#ifdef __cplusplus
}
#endif
