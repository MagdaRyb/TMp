#ifndef tpm_h
#define tpm_h

#define TPM_IRQn (IRQn_Type) 17

#include "MKL46Z4.h"   /* Device header */

void tpmInitialize(void);		//Initialization of TPM0


#endif
