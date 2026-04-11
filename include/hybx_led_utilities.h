/**
 * hybx_led_utilities.h
 * Hybrid RobotiX — HybX LED Utilities
 *
 * Public API for standard GPIO LED and RGB LED control via ESP-IDF LEDC.
 *
 * Pin definitions (LED_R, LED_G, LED_B, LED_PIN etc.) must be provided
 * by the calling project via globals.h or equivalent.
 */

#pragma once

#include <stdint.h>
#include "driver/gpio.h"
#include "driver/ledc.h"

#ifdef __cplusplus
extern "C" {
#endif

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
