#ifndef irq_h
#define irq_h

#include "buttons.h"
#include "pit.h"
#include "stdbool.h"


volatile int BPM;
volatile int METRUM [2];
int minbpm;
int maxbpm;
bool COUNTER_STATE;

void PORTC_PORTD_IRQHandler(void);	//Button IRQ Handler
void PIT_IRQHandler(void);					//Periodic Interrupt Timer IRQ Handler
void update(void);									//Function that recalculates LDVAL setting based on BPM and Metrum
void counterstst(void);							//Function alternating between start and stop of counting

#endif