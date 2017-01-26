#include "irq.h"

volatile int BPM;
volatile int METRUM;
int minbpm;
int maxbpm;
int maxmetrum;
int state;


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
	
   else if(PORTC->PCR[Button_1] & PORT_PCR_ISF_MASK) {//strat/stop metre
		counterstst();		//Toggle Start / Stop of PIT Counter 0
  }
	
 
	PORTC->PCR[SW1_PIN] |= PORT_PCR_ISF_MASK; 		/* Clear interrupt service flag in port control register otherwise int. remains active - Done!*/
  PORTC->PCR[SW3_PIN] |= PORT_PCR_ISF_MASK;     /* Clear the Interrupt Flag for SW3 */	
  PORTC->PCR[Button_1] |= PORT_PCR_ISF_MASK; 		/* Clear interrupt flag in PCR on Button_1*/
}


void  PIT_IRQHandler(void) {	
	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK){ 
		
		
		
	}
	else if(PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK){
		
		
	}
	
	PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK;
	PIT->CHANNEL[1].TFLG &= PIT_TFLG_TIF_MASK;
}

void  TPM0_IRQHandler(void) {
	
	if (TPM0->STATUS & TPM_STATUS_CH0F_MASK) {
		
		slcdDisplay(BPM, 10);
		
		TPM0->STATUS |= TPM_STATUS_CH0F_MASK;
	}
}



/*---------------------------------------------------------------------FUNCTIONS NEEDED FOR IRQ HANDLING:----------------------------------------------------------------------------------*/

void update(void){
	int i;
	i = 60*24000000;
	global_LDVAL = i/BPM;	//Load new value to cound for PIT[0]
	slcdDisplay(BPM, 10);	//Show updated value of BPM on sLCD 
}

void metrumchg(void){
	if(METRUM<maxmetrum){
		METRUM++;
	}
	else{
		METRUM=0;
	}
}





/*
	switch(METRUM){
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











