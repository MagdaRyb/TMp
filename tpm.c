#include "tpm.h"


void tpmInitialize(void) {
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK; /* Enable Clock to TPM0 */ 
	
	/* --------------------------------------------------check this below------------------------------------------------------*/
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(3)); 
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;
	MCG->C1 |= MCG_C1_IREFS_MASK; 
	/* --------------------------------------------------check this------------------------------------------------------*/
	
	TPM0->SC &= ~(TPM_SC_CPWMS_MASK); //Up-counting mode
	TPM0->SC |= TPM_SC_PS(4); // Prescale Factor Selection, Divide by 16

	TPM0->CNT = 0; //Clear counter

	TPM0->MOD = 7000; //Modulo value
	TPM0->CONTROLS[0].CnSC |= (TPM_CnSC_MSA_MASK ); //Software compare mode
	TPM0->CONTROLS[0].CnSC &= ~(TPM_CnSC_MSB_MASK);
	TPM0->CONTROLS[0].CnSC &= ~(TPM_CnSC_ELSA_MASK);
  TPM0->CONTROLS[0].CnSC &= ~(TPM_CnSC_ELSB_MASK);
	
	TPM0->CONTROLS[0].CnSC |= TPM_CnSC_CHIE_MASK; //Enable channel interrupt
	TPM0->SC |= TPM_SC_TOIE_MASK; //Timer Overflow Interrupt Enable
	NVIC_ClearPendingIRQ(TPM_IRQn);  
	NVIC_EnableIRQ(TPM_IRQn);
  
	NVIC_SetPriority(TPM_IRQn, 2); 
	TPM0->SC |= TPM_SC_CMOD(1); //Clock Mode Selection, TPM counter increments on every TPM counter clock
}
