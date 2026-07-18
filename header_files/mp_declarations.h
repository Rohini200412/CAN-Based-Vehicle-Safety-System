//declarations.h

//DELAY
void delay_us(unsigned int dlyus); //for micro seconds
void delay_ms(unsigned int dlyms); //for milli seconds
void delay_s(unsigned int dlys);   //for seconds

//LCD
void INIT_LCD(void);
void CMD_LCD(char cmd);
void DATA_LCD(char data);
void CHAR_LCD(char ascii);
void STR_LCD(char *p);
void INT_LCD(int num);
void FLOAT_LCD(float fnum,char nDP);
void BuildCGRAM(char* p,char location);


//ds18b20
unsigned char ResetDS18b20(void);
unsigned char ReadBit(void);
void WriteBit(unsigned char Dbit);
unsigned char ReadByte(void);
void WriteByte(unsigned char Dout);
int ReadTemp(void);



//EINT0 & EINT1 Interrupts
void EINT0_ISR(void)__irq;
void EINT1_ISR(void)__irq;
void EINT2_ISR(void)__irq;
void INTERRUPT_INIT(void);
void LEFT_indicator(void);
void RIGHT_indicator(void);

//LED
void LED_ON(void);
void LED_OFF(void);


//can
#ifndef __CAN_H__
#define __CAN_H__
typedef struct CAN_Frame
{
	int ID;
	struct BitField
	{
		char RTR : 1;
		char DLC : 4;
	}vbf;
	int Data1,Data2;//8-bytes
}CANF;
void Init_CAN1(void);
void CAN1_Tx(CANF txFrame);
void CAN1_Rx(CANF *rxFrame);
#endif


//ultrasonic
void delay_us(unsigned int us);
void INIT_Ultrasonic(void);
void send_pulse(void);
unsigned int read_echo(void);
unsigned int dist_cal(void);

