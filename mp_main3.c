#include <lpc21xx.h>
#include "mp_defines.h"
#include "mp_declarations.h"

char reverse_mode = 0;
char toggle_state = 0;

void INIT_LED(void) 
{
       	IODIR0 |= (1<<LED); // Configure alert LED pin as output
       	IOSET0 = (1<<LED); // Initially turn OFF alert LED
}
void LED_ON(void) 
{ 
	IOCLR0 = (1<<LED);// Turn ON alert LED
}
void LED_OFF(void) 
{ 
	IOSET0 = (1<<LED); // Turn OFF alert LED
}
  
int main() 
{
    CANF txF, rxF;
    unsigned int distance;
    
    Init_CAN1();
    INIT_Ultrasonic();
    INIT_LED();
   T1PR=12000000/1000000-1;
    
    txF.ID = 0x201; 
    txF.vbf.RTR=0; 
    txF.vbf.DLC=1;
    
    while(1) 
    {
        //Check mode from Node1
        if(C1GSR & 0x01) 
	{
            CAN1_Rx(&rxF);
            if(rxF.ID == 0x102) 
		    reverse_mode = rxF.Data1;
        }
        
        if(reverse_mode) // Check reverse mode condition
	{
            distance = dist_cal();// Measure obstacle distance using ultrasonic sensor
            txF.Data1 = distance;  // Store distance value into CAN frame
            CAN1_Tx(txF); // Send distance data to main node through CAN
            
            if(distance > 0 && distance < 20) // Check whether obstacle is very near
	    {
                LED_ON(); //Continuous ON
            }
	    else 
	    {
                toggle_state = !toggle_state; // Toggle LED blinking state
                if(toggle_state) 
			LED_ON();// Turn ON alert LED
                else 
			LED_OFF();// Turn OFF alert LED
                delay_ms(300);// Delay for LED blinking effect
            }
        } 
	else 
	{
            LED_OFF();// Turn OFF alert LED when obstacle is far
        }
        delay_ms(50);
    }
} 
