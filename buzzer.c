/*-----------------:::::|||||| buzzer.c   |||||::::::---------------------*/
/*     	 		Purpose: Metronome project 	  		  */
/*     		   Authors: Magdalena Rybicka, Piotr Sorys		  */
/*------------------------------------------------------------------------*/
#include "buzzer.h"

void buzzerInitalize(void) {
			
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; /* Enable Clock to Port D & E */ 
	PORTC->PCR[6] = PORT_PCR_MUX(1UL);  /* Pin PTC6 is GPIO */
	PORTC->PCR[7] = PORT_PCR_MUX(1UL);  /* Pin PTC7 is GPIO */
	PTC->PDDR |= buzzerHigh;  /* enable PTD5 as Output */
	PTC->PDDR |= buzzerLow;  /* enable PTE29 as Output */
	
	PTC->PSOR = buzzerHigh;  /* switch off */
	PTC->PSOR = buzzerLow;  /* switch off */

}

void buzzersOff(void) {
		PTC->PSOR = buzzerHigh;  /* switch off */
		PTC->PSOR = buzzerLow;  /* switch off */
}

void buzzersOn(void) {
		PTC->PCOR = buzzerHigh;  /* switch on */
		PTC->PCOR = buzzerLow;  /* switch on */
}

void buzzerhigh(bool state)	{
	switch(state)
	{
		case 0:
			PTC->PSOR = buzzerHigh;
			break;
		case 1:
			PTC->PCOR = buzzerHigh;
			break;
	}
}

void buzzerlow (bool state) {
		switch(state)
	{
		case 0:
			PTC->PSOR = buzzerLow;
			break;
		case 1:
			PTC->PCOR = buzzerLow;
			break;
	}
}
