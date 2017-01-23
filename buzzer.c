#include "buzzer.h"

void buzzerInitalize(void) {
			
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; /* Enable Clock to Port D & E */ 
	PORTC->PCR[6] = PORT_PCR_MUX(1UL);  /* Pin PTC6 is GPIO */
	PORTC->PCR[7] = PORT_PCR_MUX(1UL);  /* Pin PTC7 is GPIO */
	PTC->PDDR |= buzzerHigh;  /* enable PTD5 as Output */
	PTC->PDDR |= buzzerLow;  /* enable PTE29 as Output */
	
	PTC->PCOR = buzzerHigh;  /* switch off */
	PTC->PCOR = buzzerLow;  /* switch off */

}

void buzzersOff(void) {
		PTC->PCOR = buzzerHigh;  /* switch off */
		PTC->PCOR = buzzerLow;  /* switch off */
}

void buzzersOn(void) {
		PTC->PSOR = buzzerHigh;  /* switch on */
		PTC->PSOR = buzzerLow;  /* switch on */
}

void buzzerhigh(bool state)	{
	switch(state)
	{
		case 0:
			PTC->PCOR = buzzerHigh;
			break;
		case 1:
			PTC->PSOR = buzzerHigh;
			break;
	}
}

void buzzerlow (bool state) {
		switch(state)
	{
		case 0:
			PTC->PCOR = buzzerLow;
			break;
		case 1:
			PTC->PSOR = buzzerLow;
			break;
	}
}
