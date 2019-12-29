#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

/* Call before Switches are used */
void switch_init(){   /* setup switch */  
  P2REN |= SWITCHES;  /* enables resistors for switches */
  P2IE = SWITCHES;    /* enable interrupts from switches */
  P2OUT |= SWITCHES;  /* pull-ups for switches */
  P2DIR &= ~SWITCHES; /* set switches' bits for input */
  
}
/* Action being executed based on each Button */
void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  if(!(p2val & SW0)) {//S1 button
    sound1();
  } else if(!(p2val & SW1)) {//S2 button
    sound2();
  } else if(!(p2val & SW2)) {//S3 button
    sound3();
  } else if(!(p2val & SW3)) {//S4 button
    sound4();
  } else {
    buzzer_set_period(0);
  }
}
