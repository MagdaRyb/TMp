#include "MKL46Z4.h"
#include "irq.h"

extern int global_LDVAL;
extern bool COUNTER_STATE;
extern volatile int BPM;
extern volatile int METRUM;
extern int minbpm;
extern int maxbpm;
extern int maxmetrum;
extern int delayms;

void setup(void);	

int main (void) {

	setup();		// All the setup should be confined within this function to make the code clear!

	

	while(1){};	//Empty loop, gets our processor to be stuck here and wait for the interrupts to be handled
		/* Note for future: try introducing here some kind of low power mode / sleep mode instead of empty whil(1) loop */
	
		
return 0;	//Ideally program shouldn't reach here
}


void setup(void){
	/*Put all the setup here!*/
	COUNTER_STATE = 0;	//STOP COUNTING at first!
	
	BPM = 60;				//Initial BPM
	global_LDVAL = 24000000;	//Initial counter setting -> corresponds to BPM of 60BPM and metrum 1/X
	METRUM = 4;	//First part of metrum
	
	minbpm = 1;			//Minimum BPM to run on code -> please do not change it lower than 1, otherwise program will stall
	maxbpm = 280;		//Maximum BPM rating -> doesn't really have upper limit, yet if U use for e.g. 1000, you'll hear square wave, not rithmical beats 
	maxmetrum = 6;
	delayms = 15;
	
	slcdInitialize();			//Function that initializes sLCD
	pitInitialize();			//Function initializing Periodic Interrupt Timer
	ledsInit();						//Function initializing built-in LEDs
	buzzerInitalize();		//Function initializing external buzzers
	buttonsInitialize();	//Function initializing in-built and external buttons to be held by interrupts
	Touch_Init();					//Function initializing Touch Slider peripherial
	tpmInitialize(); 	//Function initializing TPM interrupt	
}
