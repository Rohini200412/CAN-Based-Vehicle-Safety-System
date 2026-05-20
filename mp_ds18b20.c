#include<LPC21xx.h>
#include "mp_declarations.h"
#define D 1<<16		 //1-WIRE DATA LINE
#define R (IOPIN0&(1<<16))

unsigned int timeout=1000;
/**RESET FUNCTION DEFINATION FOR DS18B20**/
unsigned char ResetDS18b20(void)
{
	unsigned int  presence; 
    IODIR0 |= D;// Configure DS18B20 pin as output
	IOPIN0 |= D;// Make data line HIGH	
	delay_us(1); //////////////1Us
	IOPIN0&=~(D);
	delay_us(478);//////////////486Us 
	IOPIN0 |= D;// Release data line HIGH
	delay_us(54); //////////////55Us
	presence = IOPIN0 ; 	// Read sensor response
	delay_us(423);//////////////431Us
	if(presence&R)// Check whether sensor responded
		return 1;
	else 
		return 0;
}

/**READING A BIT USING 1-WIRE PROTOCOL FROM DS18B20**/
unsigned char ReadBit(void)
{
	unsigned int B;	
	IOPIN0 &= ~(D);// Pull bus LOW
	delay_us(1);//////////////1Us
	IOPIN0 |= D;// Release bus HIGH
	IODIR0 &= ~(D);// Configure pin as input
	delay_us(10);//////////////11Us
	B=IOPIN0;// Read data pin
	IODIR0 |=D; // Configure pin back as output
	if(B&R)// Check received bit value
		return 1;
	else 
		return 0;
}

/**WRITING A BIT USING 1-WIRE PROTOCOL INTO DS18B20**/

void WriteBit(unsigned char Dbit)
{
	IOPIN0 &= ~(D);// Pull bus LOW
	delay_us(1);//////////////1Us
	if(Dbit)// Check whether bit is 1
		IOPIN0 |= D; // Release bus HIGH
	delay_us(58);//////////////59Us
	IOPIN0 |= D;// Release data line HIGH
	delay_us(1);
}

/**READING A BYTE USING 1-WIRE PROTOCOL FROM DS18B20**/

unsigned char ReadByte(void)
{
	unsigned char i;
	unsigned char Din = 0;
	for (i=0;i<8;i++) // Read 8 bits
	{
		Din|=ReadBit()? 0x01<<i:Din;// Store received bit
		delay_us(45); //////////////46Us
	}
	return(Din);// Return received byte
}


/**WRITING A BIT USING 1-WIRE PROTOCOL INTO DS18B20**/

void WriteByte(unsigned char Dout)
{
	unsigned char i;
	for (i=0; i<8; i++) // Send 8 bits
	{	    
		WriteBit((Dout & 0x1)); // Send LSB bit
		Dout = Dout >> 1;// Shift next bit
		delay_us(1);
	}
	delay_us(98);//////////////100Us
}


/**READING TEMPERATURE FROM DS18B20 USING 1-WIRE PROTOCOL**/

int ReadTemp(void)
{
	unsigned char n,buff[2];
	int temp;
	ResetDS18b20();	  //RESET DS18B20
	if(	ResetDS18b20()) // Check sensor presence
	{
	return -1;// Return error if sensor not connected
	}
    WriteByte(0xcc);   // skip ROM
    WriteByte(0x44);   // perform temperature conversion
   while (ReadByte()==0xff)
   { // wait for conversion complete
   	timeout--;
	if(timeout==0)
	return -1;
   }	
	if(ResetDS18b20()) // Reset sensor again before reading 
	{
	return -1;
	}
	WriteByte(0xcc);   // skip ROM
	WriteByte(0xbe);    // read the result
    for (n=0; n<2; n++) // read 9 bytes but, use only one byte
    {
       buff[n]=ReadByte();  // read DS1820
    }
	temp=buff[1]; // Store MSB
	temp=temp<<8;// Shift MSB left by 8 bits
	temp=temp|buff[0];// Combine MSB and LSB
	return(temp);// Return final temperature value
}
