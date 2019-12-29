#include <msp430.h>
#include "dim.h"
#include "led.h"

static enum {off=0, dim=1, bright=2} ledMode;
static char pwmCount = 0;		

void sm_slow_clock(){
  ledMode = (ledMode + 1) % 2;
}

void sm_fast_clock(){
  pwmCount = (pwmCount + 1) & 3; 
}

void sm_update_led(){
  char new_red_on;
  char new_green_on;
  switch (ledMode) {
  case off:
    new_green_on = 0;
    new_red_on = 0;
    break;
  case bright:
    new_green_on = 1;
    new_red_on = 1;
    break;
  case dim:
    new_red_on = (pwmCount < 1);
    new_green_on = (pwmCount < 1);
  }
  if (red_on != new_red_on) {
    red_on = new_red_on;
    green_on = new_green_on;
    led_changed = 1;
  }
}
