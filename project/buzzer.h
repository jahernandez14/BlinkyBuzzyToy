#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);

void sound1();
void sound2();
void sound3();
void sound4();

void play(long frequency);
#endif
