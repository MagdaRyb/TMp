#include "irq.h"

volatile int BPM;
volatile int METRUM;
int minbpm;
int maxbpm;
int maxmetrum;
int state;
int delayms;
int meter;
int lastmeter;
int difference;


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
			sequence(false);
			if(METRUM == 0){
				state = 0;
			}
			else{
				state++;
			}				
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 1:
			sequence(true);
			if(METRUM <= 1){
				state = 1;
			}
			else{
				state++;
			}
			break;
			/*-------------------------------------------------CASE----------------------------------------------------------*/
		
		case 2:
			sequence(false);
			if(METRUM <= 2){
				state = 1;
			}
			else{
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/
			
		case 3:
			sequence(false);
			if(METRUM <= 3){
				state = 1;
			}
			else{
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 4:
			sequence(false);
			if(METRUM <= 4){
				state = 1;
			}
			else{
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 5:
			sequence(false);
			if(METRUM <= 5){
				state = 1;
			}
			else{
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 6:
			sequence(false);

			if(METRUM <= 6){
				state = 1;
			}
			else{
				state++;
			}
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/

		case 7:
			sequence(false);
			if(METRUM == 7){	
			}
			state = 1;
			break;
		/*-------------------------------------------------CASE----------------------------------------------------------*/
		default:
			state = 1;
			break;
	}
		
		
	}
	else if(PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK){
		
		meter = Touch_Scan_LH();
		if(meter>20){
			if(meter>20 && meter<55)
				METRUM = 0;
			else if(meter>60 && meter<95)
				METRUM = 1;
			else if(meter>100 && meter<135)
				METRUM = 2;
			else if(meter>140 && meter<175)
				METRUM = 3;
			else if(meter>180 && meter<215)
				METRUM = 4;
			else if(meter>220 && meter<255)
				METRUM = 5;
			else if(meter>260 && meter<295)
				METRUM = 6;
			else if(meter>300)
				METRUM = 7;
			
			difference = meter - lastmeter;
			difference = abs(difference);
			
			if(difference>=25){			
			TPM0->CNT=0;
			}
			
			slcdDisplay(METRUM, 10);
			
			lastmeter = meter;
			
		}
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
	unsigned int i;
	i = 60*24000000;
	global_LDVAL = i/BPM;	//Load new value to cound for PIT[0]
	PIT->CHANNEL[0].LDVAL = global_LDVAL; 
	slcdDisplay(BPM, 10);	//Show updated value of BPM on sLCD 
}




void sequence(bool z){
	if(z == true){
		redled(true);
		buzzerhigh(true);
		del(delayms);
		redled(false);
		buzzerhigh(false);
	}
	else if(z == false){
		greenled(true);
		buzzerlow(true);
		del(delayms);
		greenled(false);
		buzzerlow(false);
	}
}
















