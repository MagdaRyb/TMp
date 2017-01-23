#ifndef buttons_h
#define buttons_h

#include "MKL46Z4.h"     
#define SW1_PIN 3												
#define SW3_PIN 12
#define Button_1 10
#define Button_2 11
#define PORTC_D_IRQ_NBR (IRQn_Type) 31				

void buttonsInitialize(void);

#endif
