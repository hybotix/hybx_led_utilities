# hybx_led_utilities Design Document

## Overview

HybX LED Utilities is a reusable ESP-IDF component providing LED control functions
for use across Hybrid RobotiX projects. It supports standard GPIO-driven LEDs and
RGB LEDs via the ESP-IDF LEDC PWM peripheral.

## Repository Structure

```
hybx_led_utilities/
├── docs/
│   ├── DESIGN.md         — This document
│   └── KNOWN_ISSUES.md   — Known issues and workarounds
├── include/
│   └── hybx_led.h        — Public API header
├── src/
│   └── hybx_led.c        — Implementation
├── CMakeLists.txt        — ESP-IDF component registration
├── idf_component.yml     — IDF Component Manager manifest
└── README.md
```

## API

### Standard LED

- `void hybx_blink_led(uint8_t pin, uint16_t delay_ms, uint8_t nr_cycles)` — Blink a standard GPIO LED

### RGB LED

- `void hybx_init_rgb_led(void)` — Initialize RGB LED via LEDC, all channels off
- `uint32_t hybx_rgb_color_32(uint8_t red, uint8_t green, uint8_t blue)` — Pack RGB into 32-bit value
- `void hybx_set_rgb_color(uint32_t color)` — Set RGB LED color via LEDC
- `void hybx_turn_rgb_on(uint32_t color)` — Turn RGB LED on with specified color
- `void hybx_turn_rgb_off(void)` — Turn RGB LED off via LEDC stop
- `void hybx_blink_led_rgb(uint32_t color, uint16_t delay_ms, uint8_t nr_cycles)` — Blink RGB LED

## Hardware Support

### Active

| Board | RGB LED Pins | Standard LED Pins |
|-------|-------------|-------------------|
| Arduino Nano ESP32 | R=GPIO46, G=GPIO0, B=GPIO45 (common anode) | Yellow=GPIO48, Red=GPIO14 |

## LEDC Configuration

- Timer: LEDC_TIMER_0
- Mode: LEDC_LOW_SPEED_MODE
- Resolution: 8-bit (0-255)
- Frequency: 5000Hz
- Channels: R=CH0, G=CH1, B=CH2

## Notes

- RGB LED is common anode — duty values are inverted (255=off, 0=fully on)
- `hybx_turn_rgb_off()` uses `ledc_stop()` with idle HIGH to ensure full off
- Pin definitions should be provided by the calling project via `globals.h` or equivalent
