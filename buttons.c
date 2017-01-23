#include "MKL46Z4.h"                    /* Device header */
#include "buttons.h"
//#include "slcd.h"	



void buttonsInitialize(void){
	
	SIM->SCGC5 |=  SIM_SCGC5_PORTC_MASK; 					/* Enable clock for port C */
	PORTC->PCR[SW1_PIN] |= PORT_PCR_MUX(1);      	/* Pin PTC3 is GPIO */
	
	/* Port control register for bit 3 of port C configuration. Activate pull up and interrupt */
	PORTC->PCR[SW1_PIN] |=  PORT_PCR_PE_MASK |	
													PORT_PCR_PS_MASK;	
	PORTC->PCR[SW1_PIN] |= 	PORT_PCR_IRQC(10);		/* Set value for IRQC bit field in PCR register to select falling edge interrupts for PORTC[3]. See KL46 Sub-Family Reference Manual */
	
	/* SW 3 */
	PORTC->PCR[SW3_PIN] |= PORT_PCR_MUX(1);      	/* Pin PTC12 is GPIO */
	
	PORTC->PCR[SW3_PIN] |=  PORT_PCR_PE_MASK |		/* Set bit in PCR register to enable pull resistor. See KL46 Sub-Family Reference Manual */
													PORT_PCR_PS_MASK;		/* Set bit in PCR register to select pull up. See KL46 Sub-Family Reference Manual */
	PORTC->PCR[SW3_PIN] |= 	PORT_PCR_IRQC(10);		/* Set value for IRQC bit field in PCR register to select falling edge interrupts for PORTC[3]. See KL46 Sub-Family Reference Manual */
		
  /* PTC 10 - button z AVT1616*/
  PORTC->PCR[Button_1] |= PORT_PCR_MUX(1);   
  PORTC->PCR[Button_1] |=  PORT_PCR_PE_MASK |	
													PORT_PCR_PS_MASK;	
  PORTC->PCR[Button_1] |= 	PORT_PCR_IRQC(10);
  
  
  /* PTC 11 - button z AVT1616*/
  PORTC->PCR[Button_2] |= PORT_PCR_MUX(1); 
  PORTC->PCR[Button_2] |=  PORT_PCR_PE_MASK |	
													PORT_PCR_PS_MASK;	
  PORTC->PCR[Button_2] |= 	PORT_PCR_IRQC(10);
  
	NVIC_ClearPendingIRQ(PORTC_D_IRQ_NBR);				/* Clear NVIC any pending interrupts on PORTC_D */
	NVIC_EnableIRQ(PORTC_D_IRQ_NBR);							/* Enable NVIC interrupts source for PORTC_D module */
	NVIC_SetPriority (PORTC_D_IRQ_NBR, 3);			/* ToDo 7.2a: Set PORTC_D interrupt priority level  */ 
}


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
