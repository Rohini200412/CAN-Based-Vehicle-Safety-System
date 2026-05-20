#include <lpc21xx.h>
#include "mp_defines.h"
#include "mp_declarations.h"
#define LED_SIG	8

volatile char current_indicator=0;// Variable to store received indicator command
int led_index=0;// Variable used for LED scrolling position

int main() 
{
    CANF rxF;// CAN receive frame structure
    Init_CAN1();// Initialize CAN controller
    IODIR0 |= 0xFF<<LED_SIG; // Configure 8 LEDs as output pins
    IOSET0 = 0xFF<<LED_SIG; // Initially turn OFF all LEDs
    while(1) 
    {
        if(C1GSR & 0x01)  // Check whether CAN data received
	{					   
            CAN1_Rx(&rxF); // Receive CAN frame
            if(rxF.ID==0x101) // Check Indicator Node CAN ID
	    {
			current_indicator=rxF.Data1; // Store received indicator command
            }
        }
		IOSET0=0xFF<<LED_SIG;// Turn OFF all LEDs before next scrolling step
		if(current_indicator==1) // Check LEFT indicator condition
		{
		IOCLR0=(1<<(LED_SIG+led_index)); // Turn ON current left scrolling LED
		led_index++; // Move to next LED position
		if(led_index>=8) // Check LED boundary condition
		led_index=0; // Restart scrolling from first LED
		}
		else if(current_indicator==2)// Check RIGHT indicator condition
		{
		IOCLR0=(1<<(LED_SIG+(7-led_index)));// Turn ON current right scrolling LED
		led_index++;// Move to next LED position
		if(led_index>=8)// Check LED boundary condition
		led_index=0;// Restart scrolling from last LED
		}
		delay_ms(120);
    }
}
