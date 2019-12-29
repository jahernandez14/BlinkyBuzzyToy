#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
unsigned ledflags = 0;

static char
redVal[] = {0, LED_RED},
greenVal[] = {0, LED_GREEN};

void led_init(){
  led_changed = 1;
  P1DIR |= LEDS;
}

void led_update(){
  if(led_changed){
    ledflags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff^LEDS) | ledflags;
    led_changed = 0;
    if(!inState){
      P1OUT ^= ledflags;
      inState = 0;
    }
  }
}
