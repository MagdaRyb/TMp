#include "irq.h"

void PORTC_PORTD_IRQHandler(void){		
	
	if(PORTC->PCR[SW1_PIN] & PORT_PCR_ISF_MASK) {// interrupt on SW1 //add bpm
		if(BPM<maxbpm){
			BPM++;
			update();
		}
  }
  else if(PORTC->PCR[SW3_PIN] & PORT_PCR_ISF_MASK) {// interrupt on SW3 //subtract bpm
		if(BPM>minbpm){
			BPM--;
			update();
		}

  }
  else if(PORTC->PCR[Button_1] & PORT_PCR_ISF_MASK) {//change metre
		
		
		
		
		/*--------------------------------------------------------------------------------------------EMPTY HERE!!! -------------------------------------------------------------------------*/
  }
  else if(PORTC->PCR[Button_2] & PORT_PCR_ISF_MASK) {//strat/stop metre
		counterstst();
  }
	
 
	PORTC->PCR[SW1_PIN] |= PORT_PCR_ISF_MASK; 		/* Clear interrupt service flag in port control register otherwise int. remains active - Done!*/
  PORTC->PCR[SW3_PIN] |= PORT_PCR_ISF_MASK;     /* Clear the Interrupt Flag for SW3 */	
  PORTC->PCR[Button_1] |= PORT_PCR_ISF_MASK; 
  PORTC->PCR[Button_2] |= PORT_PCR_ISF_MASK; 
}


void  PIT_IRQHandler(void) {	
	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK){ 
		
		
		
	}
	
	PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK;
}



/*---------------------------------------------------------------------FUNCTIONS NEEDED FOR IRQ HANDLING:----------------------------------------------------------------------------------*/

void update(void){
	int i;
	i = 60*24000000;
	global_LDVAL = i/BPM;
}

void counterstst(void){
	if(COUNTER_STATE == 0){
		COUNTER_STATE = 1;
	}
	else if(COUNTER_STATE == 1){
		COUNTER_STATE = 0;	
	}
	
	freezetimer0(COUNTER_STATE);
}





/*
	switch(METRUM[0]){
		case 0:
			
			break;
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
			
*/











