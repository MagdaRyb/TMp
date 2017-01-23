#include "irq.h"


void PORTC_PORTD_IRQHandler(void){		
	
	if(PORTC->PCR[SW1_PIN] & PORT_PCR_ISF_MASK) {// interrupt on SW1 //add bpm

  }
  if(PORTC->PCR[SW3_PIN] & PORT_PCR_ISF_MASK) {// interrupt on SW3 //subtract bpm
 
  }
  if(PORTC->PCR[Button_1] & PORT_PCR_ISF_MASK) {//change metre

  }
  if(PORTC->PCR[Button_2] & PORT_PCR_ISF_MASK) {//strat/stop metre
//startstop
  }
	
 
	PORTC->PCR[SW1_PIN] |= PORT_PCR_ISF_MASK; 		/* Clear interrupt service flag in port control register otherwise int. remains active - Done!*/
  PORTC->PCR[SW3_PIN] |= PORT_PCR_ISF_MASK;     /* Clear the Interrupt Flag for SW3 */	
  PORTC->PCR[Button_1] |= PORT_PCR_ISF_MASK; 
  PORTC->PCR[Button_2] |= PORT_PCR_ISF_MASK; 
}


void  PIT_IRQHandler(void) {	
	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK){ 

		
	PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK;
	}
}
