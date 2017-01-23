#include "ledz.h"												//Declarations

/*----------------------------------------------------------------------------
  Function that initializes LEDs
 *----------------------------------------------------------------------------*/
void ledsInit(void){
	
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK; /* Enable Clock to Port D & E */ 
	PORTD->PCR[5] = PORT_PCR_MUX(1UL);  /* Pin PTD5 is GPIO */
	PORTE->PCR[29] = PORT_PCR_MUX(1UL);  /* Pin PTE29 is GPIO */
	PTD->PDDR |= led_mask[ledGreen];  /* enable PTD5 as Output */
	PTE->PDDR |= led_mask[ledRed];  /* enable PTE29 as Output */
	
	PTD->PSOR = led_mask[ledGreen];  /* switch Green LED off */
	PTE->PSOR = led_mask[ledRed];  /* switch Red LED off */
		
}

/*----------------------------------------------------------------------------
  Function that turns all LEDs off
 *----------------------------------------------------------------------------*/
void ledsOff(void) {
		PTD->PSOR = led_mask[ledGreen];          /* switch Red LED off  */
	  PTE->PSOR = led_mask[ledRed];       /* switch Green LED off  */
}
/*----------------------------------------------------------------------------
  Function that turns all LEDs on
 *----------------------------------------------------------------------------*/
void ledsOn(void) {
		PTD->PCOR = led_mask[ledGreen];      	/* switch Red LED on  */
	  PTE->PCOR = led_mask[ledRed];     	/* switch Green LED on */
}
/*----------------------------------------------------------------------------
  Welcome led sequence function
 *----------------------------------------------------------------------------*/
void greenled (bool state)	{
	switch(state)
	{
		case 0:
			PTD->PCOR = led_mask[ledGreen];
			break;
		case 1:
			PTD->PSOR = led_mask[ledGreen];
			break;
	}
}

void redled(bool state) {
		switch(state)
	{
		case 0:
			PTE->PCOR = led_mask[ledRed];
			break;
		case 1:
			PTE->PSOR = led_mask[ledRed];
			break;
	}
}
