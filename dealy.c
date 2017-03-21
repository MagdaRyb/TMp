/*-----------------:::::||||||   delay.c  |||||::::::---------------------*/
/*     	 		Purpose: Metronome project 	  		  */
/*     		   Author: Magdalena Rybicka, Piotr Sorys		  */
/*------------------------------------------------------------------------*/
#include "MKL46Z4.h"
#include "delay.h"

void del(int ms){
	/*Simple delay, counting up to specified *1ms (around)*/
	int i;
	int y;
	
	for(i=0; i<ms; i++){
		for(y=0; y<48000; y++){
			__NOP;
		}
	}
	
	
}
