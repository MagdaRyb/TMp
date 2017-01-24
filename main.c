#include "MKL46Z4.h"
#include "buttons.c"
#include "buzzer.c"
#include "irq.c"
#include "pit.c"
#include "ledz.c"

#include "slcd.c"		//Temporary include -> try not to laugh, let's make it on sLCD first, then if tutor says so, we'll introduce LED 7-segment done on interrupts

volatile int BPM;
volatile int METRUM [2];
void setup(void);	//not finished







int main (void) {

	setup();

	
	
	
	
	
	
	
	while(1){};	//Empty loop, gets our processor to be stuck here and wait for the interrupts to be handled
		/* Note for future: try introducing here some kind of low power mode / sleep mode instead of empty whil(1) loop */
		
return 0;	//Ideally program shouldn't reach here
}

void setup(void){
	/*Put all the setup here!*/
	BPM = 60;
	METRUM[0] = 1;
	METRUM[1] = 1;
	
	
	
}