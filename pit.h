#ifndef pit_h
#define pit_h

#include "MKL46Z4.h"   /* Device header */
#include "stdbool.h"

extern int global_LDVAL;
extern bool COUNTER_STATE;

void pitInitalize(void);		//Initialization of PIT0
void freezetimer0 (bool);		//Function that freezes or unfreezes the timer				
void counterstst(void);			//Function alternating between start and stop of counting


#endif
