# Blinky-RGB Example

Demonstrates use of `hybx_led_utilities` to blink a standard GPIO LED and an
RGB LED using packed 32-bit color values.

## Target Board

Arduino Nano ESP32 (ESP32-S3)

## Pin Definitions

Defined in `include/globals.h` — adapt for your board.

| Signal   | GPIO    | Notes              |
|----------|---------|--------------------|
| RGB Red  | GPIO 46 | Common anode, LOW = on |
| RGB Green| GPIO 0  | Common anode, LOW = on |
| RGB Blue | GPIO 45 | Common anode, LOW = on |
| Yellow   | GPIO 48 | Active HIGH        |

## What It Does

1. Blinks the yellow LED twice
2. Blinks the RGB LED blue twice
3. Repeats

## Usage

Copy `globals.h` to your project's `include/` directory and adapt the pin
definitions for your board. Include `hybx_led_utilities.h` and link against
the `hybx_led_utilities` component.
