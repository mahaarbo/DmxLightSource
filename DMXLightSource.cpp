#include "DMXLightSource.h"

DMX_Light_Source::DMX_Light_Source (DMX_Master* dmx_location, uint16_t add)
{
  //Initialize the light source, and ensure lights are off.
  pdmx = dmx_location;
  address = add;
}

uint16_t DMX_Light_Source::get_address()
{
  return address;
}

void DMX_Light_Source::set_address(uint16_t add)
{
  address = add;
}

void DMX_Light_Source::set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
  red = r;
  green = g;
  blue = b;
  white = w;
  pdmx->setChannelValue(RED_CH+address, red);
  pdmx->setChannelValue(BLUE_CH+address, blue);
  pdmx->setChannelValue(GREEN_CH+address, green);
  pdmx->setChannelValue(WHITE_CH+address, white);
}
uint8_t DMX_Light_Source::get_red()
{
  return red;
}
uint8_t DMX_Light_Source::get_green()
{
  return green;
}
uint8_t DMX_Light_Source::get_blue()
{
  return blue;
}
uint8_t DMX_Light_Source::get_white()
{
  return white;
}
void DMX_Light_Source::set_led(uint8_t led_power)
{
  pdmx->setChannelValue(LED_CH+address, led_power);
  
}

void DMX_Light_Source::led_on()
{
  //The UFO cube turns on if LED channel is set between 0-250
  pdmx->setChannelValue(LED_CH+address, 1);
}
void DMX_Light_Source::led_off()
{
  //The UFO cube turns off if the LED channel is set between 251-255
  pdmx->setChannelValue(LED_CH+address, 255);
}

uint16_t DMX_Light_Source::next_available_address()
{
  return address+uint16_t(MAX_NUMBER_OF_CHANNELS);
}

  
