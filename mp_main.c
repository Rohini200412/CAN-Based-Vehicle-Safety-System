#include <lpc21xx.h>
#include "mp_declarations.h"
#include "mp_defines.h"

volatile char led_cmd=0;  // Variable to store indicator status (0=OFF,1=LEFT,2=RIGHT)
volatile char vehicle_mode=0; // Variable to store vehicle mode (0=Forward,1=Reverse)
volatile char object_distance=99;// Variable to store received obstacle distance
volatile char tx_flag=0; // Variable used to trigger CAN transmission

char left[8]={0x01,0x03,0x07,0x0F,0x1F,0x0F,0x07,0x03};//for left indicator symbol
char right[8]={0x10,0x18,0x1C,0x1E,0x1F,0x1E,0x1C,0x18};//for right indicator symbol

 float temp;
 int tp;

 unsigned char tpd;
int main() 
{
     CANF rx;// CAN receive frame structure
	 CANF tx; // CAN transmit frame structure
    INIT_LCD();// Initialize LCD display
    Init_CAN1();// Initialize CAN communication
    INTERRUPT_INIT();// Configure external interrupts
    CMD_LCD(0x80);// Move cursor to first line first position
    STR_LCD("Vehicle Control Sys"); // Display project title on LCD

    BuildCGRAM(left,1);// Store custom left arrow symbol in CGRAM
	BuildCGRAM(right,2);     // Store custom right arrow symbol in CGRAM
    while(1) 
    {
        //Temp display Line2
		temp=ReadTemp();  //READING TEMPERATURE FROM DS18B20 USING 1-WIRE PROTOCOL
		if(temp==-1)//detect disconnect temperature sensor
		{
		CMD_LCD(0xC0);
		STR_LCD("TEMP SENSOR error  ");
		}
		else
		{
		tp  = (int)temp>>4;	  //GETTING INTEGER PART
		tpd=(((int)temp)&0x08)?0x35:0x30;//GETTING FRACTIONAL PART
		CMD_LCD(0xC0); // Move cursor to second line
 		STR_LCD("ENGINE Temp:");// Display temperature label
		INT_LCD(tp); // Display integer temperature
		CHAR_LCD('.');// Display decimal point
		CHAR_LCD(tpd);// Display fractional temperature digit
		CHAR_LCD(223);  // Display degree symbol
		STR_LCD("C  "); // Display Celsius symbol
		}

        //Line3: Left/Right/Normal
        CMD_LCD(0x94);

        if(led_cmd==1) // Check left indicator status
	{
		CHAR_LCD(1); // Display custom left arrow
		STR_LCD("Left INDICATOR ");// Show left indicator message
		}
        else if(led_cmd==2)  // Check right indicator status
		{
		CMD_LCD(0x94);// Display custom right arrow
		CHAR_LCD(2);
		STR_LCD("Right INDICATOR");// Show right indicator message
		}
		if(led_cmd==0)
		{
		CMD_LCD(0x94);
		CHAR_LCD(1);
     	CHAR_LCD(2); 
        STR_LCD("INDICATORS    ");// Display normal indicator message
		}

	 // --- CAN TX: Switch press Node 2  ---
        if(tx_flag == 1) // Check whether CAN data needs transmission
	{
            tx.ID = 0x101;  // CAN ID for Indicator Node
            tx.vbf.RTR = 0; // Configure as data frame
	    tx.vbf.DLC = 1; // Send 1-byte data
            tx.Data1 = led_cmd; // Store indicator command
            CAN1_Tx(tx);// Transmit CAN frame
           // tx_flag = 0;
        }
        else if(tx_flag == 2) 
	{
            tx.ID = 0x102;  // Node 3  Fwd/Rev mode
            tx.vbf.RTR = 0; 
	    tx.vbf.DLC = 1;
            tx.Data1 = vehicle_mode;
            CAN1_Tx(tx);
            //tx_flag = 0;
        }

        //Receive distance from Node3
        if(C1GSR & 0x01) 
	{
            CAN1_Rx(&rx);// Receive CAN frame
            if(rx.ID == 0x201) 
		   object_distance = rx.Data1;// Store received distance
        }

        CMD_LCD(0xD4);
        if(vehicle_mode)   // Check reverse mode
       	{
            STR_LCD("Reverse Dist:");// Display reverse mode message
            INT_LCD(object_distance); // Display obstacle distance
	    STR_LCD("cm ");
        } 
	else 
	{
            STR_LCD("Forward Direction ");// Display forward mode
        }
        delay_ms(100);
    }	
}
