#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachine.h"

/* Call before Speaker is used */
void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7; 
  P2SEL |= BIT6;
  P2DIR = BIT6;//enable output to speaker (P2.6)
}

void play(long frequency){
  long count = 0;
  buzzer_set_period(frequency);
  while(++count < 15000){
  }
  count = 0;
  buzzer_set_period(0);
  }

void sound1(){
  play(0);
  play(2000);
  play(1000);
  play(2500);
  play(1500);
  play(0);
  advance_state(0);
}

void sound2(){
  play(0);
  play(1000);
  play(1500);
  play(2000);
  play(2500);
  play(0);
  advance_state(1);
}

void sound3(){
  play(0);
  play(500);
  play(600);
  play(700);
  play(800);
  play(900);
  play(1000);
  play(0);
  advance_state(0);
}

void sound4(){
  play(0);
  play(1000);
  play(900);
  play(800);
  play(700);
  play(600);
  play(500);
  play(0);
  advance_state(1);
}

void buzzer_set_period(short beep){
  CCR0 = beep;
  CCR1 = beep >> 1;
}
