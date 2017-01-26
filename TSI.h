#ifndef __TOUCH_SEN_H_
#define __TOUCH_SEN_H_

#include "MKL46Z4.h"


void Touch_Init(void);
int Touch_Scan_LH(void);
int Touch_Scan_HL(void);

// Macros
#define SCAN_OFFSET 200  // Offset for scan range
#define SCAN_DATA TSI0->DATA & 0xFFFF // Accessing the bits held in TSI0_DATA_TSICNT

#endif
