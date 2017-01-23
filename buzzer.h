#ifndef buzzer_h
#define buzzer_h

#include "MKL46Z4.h"   /* Device header */
#include "stdbool.h"
#define buzzerHigh 1UL << 6
#define buzzerLow 1UL << 7

void buzzerInitalize(void);
void buzzersOff(void);
void buzzersOn(void);
void buzzerhigh(bool);
void buzzerlow(bool);

#endif
