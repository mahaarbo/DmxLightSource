#ifndef DMXLightSource_h
#define DMXLightSource_h

/*
 * A library for handling a DMX light source
 * Uses Conceptinetics DMX shield
 * Specifically designed for the UFO Cube, but changing the channels, and max channels will make it fit others.
 */

#include "Conceptinetics.h"
#include <inttypes.h>
//CHANGE THESE IF THERE IS A NEW 
static const uint8_t RED_CH = 0;
static const uint8_t GREEN_CH = 1;
static const uint8_t BLUE_CH = 2;
static const uint8_t WHITE_CH = 3;
static const uint8_t LED_CH = 4;
static const uint8_t MAX_NUMBER_OF_CHANNELS = 5;
//
class DMX_Light_Source
{
 public:
  DMX_Light_Source (DMX_Master*, uint16_t);
  uint16_t get_address();
  void set_address(uint16_t add);
  void set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t white);
  uint8_t get_red();
  uint8_t get_green();
  uint8_t get_blue();
  uint8_t get_white();
  void set_led(uint8_t led_power);
  void led_on();
  void led_off();
  uint16_t next_available_address();
 private:
  uint16_t address;
  DMX_Master* pdmx;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t white;
};

#endif
