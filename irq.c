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
		metrumchg();	
  }
	
  else if(PORTC->PCR[Button_2] & PORT_PCR_ISF_MASK) {//strat/stop metre
		counterstst();		//Toggle Start / Stop of PIT Counter 0
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

void metrumchg(void){
	if(METRUM<maxmetrum){
		METRUM++;
	}
	else{
		METRUM=0;
	}
}



void setup(void){
	/*Put all the setup here!*/
	COUNTER_STATE = 0;	//STOP COUNTING at first!
	
	BPM = 60;				//Initial BPM
	global_LDVAL = 24000000;	//Initial counter setting -> corresponds to BPM of 60BPM and metrum 1/X
	METRUM = 4;	//First part of metrum
	
	minbpm = 1;			//Minimum BPM to run on code -> please do not change it lower than 1, otherwise program will stall
	maxbpm = 280;		//Maximum BPM rating -> doesn't really have upper limit, yet if U use for e.g. 1000, you'll hear square wave, not rithmical beats 
	maxmetrum = 6;
	
	slcdInitialize();			//Function that initializes sLCD
	pitInitalize();				//Function initializing Periodic Interrupt Timer
	ledsInit();						//Function initializing built-in LEDs
	buzzerInitalize();		//Function initializing external buzzers
	buttonsInitialize();	//Function initializing in-built and external buttons to be held by interrupts
		
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











