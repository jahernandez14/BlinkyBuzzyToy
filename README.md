# blinky-buzzy-jahernandez14

## Blinky Toy

This program uses interrupts and the libtimer library to produce dimming lights, LEDs, and buzzing sounds

## Instructions

The main Makefile resides in the root of the project. In order to get the game to load just enter make followed by enter.

-Button 1: Sound 1 will be displayed and red led will flash

-Button 2: Sound 2 will be displayed and green led will flash

-Button 3: Sound 3 will be displayed and red led will flash

-Button 4: Sound 4 will be displayed and green led will flash

## State Machine

The project consists of two states. inState = 0: dimming lights when no interrupt is detections. inState = 1: interrupt has been detected and will execute the case for the button
