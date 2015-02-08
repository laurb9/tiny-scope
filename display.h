/*
 * display.h - Display class with printf() and human-readable units
 * Tiny Scope for Arduino project
 *
 * Copyright (C)2015 Laurentiu Badea
 *
 * This file may be redistributed under the terms of the MIT license.
 * A copy of this license has been included with this distribution in the file LICENSE.
 */
#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH  SSD1306_LCDWIDTH
#define SCREEN_HEIGHT SSD1306_LCDHEIGHT

#define CHR_HEIGHT 8 // found in Adafruit_GFX::write(c)
#define CHR_WIDTH 6

/*
 * SSD1306 class with printf() functionality.
 * clearDisplay() automatically sets text cursor to 0,0
 */
class Display : public Adafruit_SSD1306 {
public:
    Display(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST, int8_t CS);
    Display(int8_t DC, int8_t RST, int8_t CS);
    Display(int8_t RST);
    void clearDisplay();
    int printf(const char *format, ...);
    void printLargeUnits(unsigned long value, const char *unit);
    void printSmallUnits(unsigned long value, const char *unit);
#ifdef F // F() macro is available
    int printf(const __FlashStringHelper *format, ...);
#endif

};

#endif /* DISPLAY_H_ */
