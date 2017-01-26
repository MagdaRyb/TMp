#include "irq.h"

volatile int BPM;
volatile int METRUM;
int minbpm;
int maxbpm;
int maxmetrum;
int state;
int delayms;


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
		
	switch(state){
		/*-------------------------------------------------CASE----------------------------------------------------------*/
		case 0:
			if(METRUM == 0){
				sequence(false);
			}
			else{
				sequence(false);
				state++;
			}				
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 1:
			if(METRUM == 1){
				sequence(true);
			}
			else{
				sequence(true);
				state++;
			}
			break;
			/*-------------------------------------------------CASE----------------------------------------------------------*/
		
		case 2:
			if(METRUM == 2){
				sequence(false);
				state = 1;
			}
			else{
				sequence(false);
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/
			
		case 3:
			if(METRUM == 3){
				sequence(false);
				state = 1;
			}
			else{
				sequence(false);
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 4:
			if(METRUM == 4){
				sequence(false);
				state = 1;
			}
			else{
				sequence(false);
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 5:
			if(METRUM == 5){
				sequence(false);
				state = 1;
			}
			else{
				sequence(false);
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 6:
			if(METRUM == 6){
				sequence(false);
				state = 1;
			}
			else{
				sequence(false);
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 7:
			if(METRUM == 7){
				sequence(false);
				state = 1;
			}
			else{
				sequence(false);
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/
		default:
			state = 1;
			break;
	}
		
		
	}
	else if(PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK){
		
		
	}
	
	PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK;
	PIT->CHANNEL[1].TFLG &= PIT_TFLG_TIF_MASK;
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

void sequence(bool i){
	if(i == 1){
		redled(true);
		buzzerhigh(true);
		del(delayms);
		redled(false);
		buzzerhigh(false);
	}
	else{
		greenled(true);
		buzzerlow(true);
		del(delayms);
		greenled(false);
		buzzerlow(false);
	}
}
















