#include<lpc21xx.h>
#include "mp_defines.h"
#include "mp_declarations.h"

extern volatile char led_cmd;
extern volatile char vehicle_mode;
extern volatile char tx_flag;
volatile char left_active=0; // Variable to store left indicator toggle status
volatile char right_active=0; // Variable to store right indicator toggle status


void INTERRUPT_INIT(void) {
    // P0.14 = EINT1 - Left Switch
    PINSEL0 &= ~(EINT0_INPUT_PIN |EINT1_INPUT_PIN|EINT2_INPUT_PIN);  
    PINSEL0 |= (EINT0_INPUT_PIN |EINT1_INPUT_PIN |EINT2_INPUT_PIN) ; // Enable interrupt pin functions

    EXTMODE = 0x07;  // EINT0,1,2 Edge trigger
    EXTPOLAR = 0x00; // Falling edge

    VICIntEnable = (1<<14) | (1<<15) | (1<<16); // Enable EINT0,EINT1,EINT2

    // EINT0 = P0.16 = SWITCH3 = Mode
    VICVectCntl0 = 0x20 | 14; // Slot 0, Channel 14
    VICVectAddr0 = (unsigned)EINT0_ISR;

    // EINT1 = P0.14 = SWITCH1 = Left
    VICVectCntl1 = 0x20 | 15; // Slot 1, Channel 15
    VICVectAddr1 = (unsigned)EINT1_ISR;

    // EINT2 = P0.15 = SWITCH2 = Right
    VICVectCntl2 = 0x20 | 16; // Slot 2, Channel 16
    VICVectAddr2 = (unsigned)EINT2_ISR;
}

void EINT0_ISR(void) __irq { // P0.16 - Mode Switch
    vehicle_mode =!vehicle_mode; // Forward/Reverse toggle
    led_cmd = 0; // Indicators off
    tx_flag = 2; // Send mode to Node 3
    EXTINT = 0x01; // EINT0 clear
    VICVectAddr = 0;// End of interrupt service routine
}

void EINT1_ISR(void) __irq 
{ // P0.14 - Left Switch
	left_active=!left_active;
	if(led_cmd==1)// Activate left indicator
	{
	led_cmd=0 ;
	}
	else
	{
	right_active=0;
	led_cmd=1 ;
	}
	tx_flag = 1; // Send to Node 2
    EXTINT = 0x02; // EINT1 clear
    VICVectAddr = 0;// End of interrupt service routine
}

void EINT2_ISR(void) __irq 
{ // P0.15 - Right Switch
	right_active=!right_active;
	if(led_cmd==2) // Activate right indicator
	{
	led_cmd=0 ;
	}
	else
	{
	left_active=0;
	led_cmd=2 ;
	}
    tx_flag = 1; // Send to Node 2
    EXTINT = 0x04; // EINT2 clear
    VICVectAddr = 0;// End of interrupt service routine
}

