#include<lpc21xx.h>
#include "mp_declarations.h"
#include "mp_defines.h"

void WRITE_LCD(char data)
{
IOCLR0=1<<RW;   // Set RW = 0 -> Write operation
	// Clear previous data bits and place new 8-bit data on LCD data pins
 IOCLR0 = (255 << LCD_DATA_PINS);   // Clear data pins
    IOSET0 = (data << LCD_DATA_PINS);  // Set new data
IOSET0=1<<EN;  // Enable pin HIGH ? LCD reads data
delay_us(1);   // Small enable pulse width
IOCLR0=1<<EN;   // Enable pin LOW ? latch data into LCD
delay_ms(2);
}

// Function to send command to LCD
void CMD_LCD(char cmd)
{
IOCLR0=1<<RS;
WRITE_LCD(cmd);  // Send command to LCD
}

void INIT_LCD(void)
{
        IODIR0|=(255<<LCD_DATA_PINS);  // Configure LCD data pins as OUTPUT
        IODIR0|=(1<<RS)|(1<<EN)|(1<<RW);  // Configure RS, EN, RW as OUTPUT
          delay_ms(15);   //delay of 15 ms for the power on of lcd
          CMD_LCD(0x30); //8bit mode 1st line pos0
    delay_ms(5);   //delay 5ms
    CMD_LCD(0x30);  //8 bit mode 1st line pos0
    delay_us(100); //delay 100us
    CMD_LCD(0x30); //8 bit mode 1st line pos0
    CMD_LCD(0x38); //8 bit mode 2nd line pos0
    CMD_LCD(0x0F); //display on cursor blink
    CMD_LCD(0x01); //clear lcd
    CMD_LCD(0x06); //SHIFT CURSOR RIGHT
}

//for displaying characters on lcd
void CHAR_LCD(char ascii)
{
         IOSET0=1<<RS;
         WRITE_LCD(ascii);
}

//displaying string on lcd
void STR_LCD(char *p)
{
    while(*p)
    {
                CHAR_LCD(*p++);
    }
}

//displaying integer values on lcd
void INT_LCD(int num)
{
    char arr[10];
    int i=0;
    if(num==0)// Check zero condition
    {
                CHAR_LCD('0');
        return;
    }
    while(num>0)// Extract digits
    {
        arr[i++] = num%10 + '0';// Convert digit into ASCII
        num/=10;
    }
		for(--i;i>=0;i--) // Print digits in correct order
                CHAR_LCD(arr[i]);// Display digit
}

// Function to display floating point number
void FLOAT_LCD(float fnum,char nDP)
{
	int n;
	int i;
	if(fnum<0)// Check negative number
	{
		CHAR_LCD('-');
	}
		n=fnum;// Extract integer part
		INT_LCD(n); // Display integer part
		CHAR_LCD('.');// Display decimal point
		for(i=0; i<nDP; i++) // Display decimal digits
		{
			fnum=(fnum-n)*10; // Shift next decimal digit
			n=fnum;// Extract decimal digit
			CHAR_LCD(n+48); // Convert into ASCII and display
		}
}

// Function to create custom LCD characters
void BuildCGRAM(char* p,char location)
{
	int i;
	CMD_LCD(0x40+(location*8)); // Select CGRAM location
	for(i=0; i<8; i++)// Store 8-byte custom pattern
	{
		CHAR_LCD(p[i]);// Write custom pattern byte
	}
}
