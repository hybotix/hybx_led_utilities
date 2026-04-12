/**
 * globals.h
 * Hybrid RobotiX — hybx_led_utilities Blinky-RGB Example
 *
 * Pin definitions and constants for the Arduino Nano ESP32.
 * Adapt these for your target board.
 */

#pragma once

#include "driver/gpio.h"

//  RGB LED pin definitions (common anode — LOW = on)
#define LED_R           GPIO_NUM_46
#define LED_G           GPIO_NUM_0
#define LED_B           GPIO_NUM_45

//  Standard LED pin definitions (HIGH = on)
#define LED_YELLOW      GPIO_NUM_48
#define LED_RED         GPIO_NUM_14

//  Control definitions
#define LED_PIN         LED_YELLOW
#define BLINK_DELAY_MS  500
#define LOOP_DELAY_MS   1000
