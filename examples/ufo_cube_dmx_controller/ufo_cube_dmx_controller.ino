#include "Conceptinetics.h"
#include "DMXLightSource.h"

//Setup DMX shield things
const int DMX_MASTER_CHANNELS = 100; //See conceptinetics
const int RXEN_PIN = 2; //Not actually used
DMX_Master dmx_master(DMX_MASTER_CHANNELS, RXEN_PIN);

//Setup ufo_cube things
DMX_Light_Source ufo_cube(&dmx_master, 1);
int red = 0;
int green = 0;
int blue = 0;
int white = 0;
int led_power = 255;

void setup() {
  // Start communication with DMX
  dmx_master.enable();
  dmx_master.setChannelRange(1,127,127);
  ufo_cube.set_led(led_power); //This turns off the LED
}

void loop() {
  // Cycle to a random color in rgbw space then pan LED
  
  // Fade up to color
  for(led_power = 0; led_power < 251; led_power++){
    ufo_cube.set_led(led_power);
    delay(40);
  }

  // Move to random color
  int new_red = random(0,255);
  int new_green = random(0, 255);
  int new_blue = random(0, 255);
  int new_white = random(0, 255);
  boolean moving_to_color = true;
  
  while(moving_to_color){
    if(new_red> red){
      red++;
    }
    if(new_red < red){
      red--;
    }
    if(new_green > green){
      green++;
    }
    if(new_green < green){
      green--;
    }
    if(new_blue> blue){
      blue++; 
    }
    if(new_blue < blue){
      blue--;
    }
    if(new_white > white){
      white++;
    }
    if(new_white < white){
      white--;
    }
    if(red == new_red && 
       green == new_green && 
       blue == new_blue && 
       white == new_white){
        moving_to_color = false;
       }
    ufo_cube.set_color(red,green,blue,white);
  }
  for(led_power = 250; led_power > 0; led_power--){
    ufo_cube.set_led(led_power);
    delay(40);
  }
  delay(200);
}
