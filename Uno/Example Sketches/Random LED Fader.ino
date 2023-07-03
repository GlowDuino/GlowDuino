/*
 * This is the default sketch for the GlowDuino Uno board.
 * It uses the SoftPWM library to enable PWM output on
 * all pins. These pins will randomly light up and turn off.
 *
 * To adjust the light up and turn off times, alter the 
 * define lines in the sketch. You can also adjust the
 * density of the lit up leds by changing the probability
 * variable.
 *
 * For this sketch you will need to install the SoftPWM
 * library from the following link:
 * https://github.com/bhagman/SoftPWM
 *
 */

#include "SoftPWM.h"

#define riseTime 500  // Time while LED fades in
#define fallTime 500  // Time while LED fades out
#define probability 3 // Sets the density of the lit up LEDs

int rnd = 0;
int probable = 3;

void setup()
{
  SoftPWMBegin();

  for(int i = 2; i < 20; i++){
    SoftPWMSet(i, 0);
    SoftPWMSetFadeTime(i, riseTime, fallTime);
  }
}

void loop()
{
  rnd = random(2, 20);
  probable = random(1, 10);
  if(probable <= probability){
    SoftPWMSetPercent(rnd, 100);
  }else{
    SoftPWMSetPercent(rnd, 0);
  }
  delay(100);
}