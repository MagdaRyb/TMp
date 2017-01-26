#include "pit.h"

int global_LDVAL;
bool COUNTER_STATE;


void pitInitialize(void) {
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; 	
	PIT->MCR &= ~PIT_MCR_MDIS_MASK;
	PIT->MCR |= PIT_MCR_FRZ_MASK;
	
	PIT->CHANNEL[0].LDVAL = global_LDVAL; 
	PIT->CHANNEL[1].LDVAL = 2400000; 

	NVIC_ClearPendingIRQ(PIT_IRQn);  
	NVIC_EnableIRQ(PIT_IRQn);
	NVIC_SetPriority(PIT_IRQn, 0); 
	__enable_irq();
	
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK;   
	PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_TIE_MASK;  
	
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK; 
	PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_TEN_MASK; 
	
	PIT->MCR = 0x00; 

}

void freezetimer0 (bool stat){
	if(stat == 1)
		PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK; 
	else 
		PIT->CHANNEL[0].TCTRL &= ~PIT_TCTRL_TEN_MASK;
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
