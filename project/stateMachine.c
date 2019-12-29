#include <msp430.h>
#include "stateMachine.h"
#include "led.h"

void advance_state(int state){
  inState = 1;
  led_update();
  switch(state){
  case 0:
    P1OUT |= LED_RED;//Set to red
    break;
  case 1:
    P1OUT |= LED_GREEN;//Set to green
    break;
  }
}
