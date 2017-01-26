#include "MKL46Z4.h"
#include "irq.h"


int main (void) {

	setup();		// All the setup should be confined within this function to make the code clear!

	

	while(1){};	//Empty loop, gets our processor to be stuck here and wait for the interrupts to be handled
		/* Note for future: try introducing here some kind of low power mode / sleep mode instead of empty whil(1) loop */
	
		
return 0;	//Ideally program shouldn't reach here
}
