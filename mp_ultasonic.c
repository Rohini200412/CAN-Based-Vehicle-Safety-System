#include<lpc21xx.h>
#include"mp_defines.h"
#include"mp_declarations.h"

void INIT_Ultrasonic(void)
{
PCONP|=1<<2;
IODIR0|=(1<<trr_pin);// Configure trigger pin as output
IODIR0&=~(1<<echo_pin);// Configure echo pin as inpu

T1PR=59;// Configure Timer1 for 1us resolution
T1TCR=0x02; // Reset Timer1

}																								
void send_pulse(void)
{
IOSET0=1<<trr_pin; // Trigger HIGH pulse
delay_us(10);// Wait 10 microseconds
IOCLR0=1<<trr_pin;// Trigger LOW pulse
}

unsigned int read_echo(void)
{
unsigned duration=0;
unsigned int timeout=60000;
while(((IOPIN0>>echo_pin)&1)==0)
 {
	 timeout--;
	 if(timeout==0)
	 return 0;
	 }  
T1TCR=0X02; // Reset Timer1
T1TCR=0X01;// Start Timer1
timeout=60000;
while((IOPIN0>>echo_pin)&1)
{
	 timeout--;
	 if(timeout==0)
	 break;
	 } 
T1TCR=0X00;// Stop Timer1
duration=T1TC;// Read timer count
return duration;
}

unsigned int dist_cal(void)
{
unsigned pulse;
float dis;
send_pulse();
pulse=read_echo();
dis=pulse/58;// Convert pulse width into centimeters
return dis;
}

