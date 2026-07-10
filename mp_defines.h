//defines.h

//SWITCHS defines
#define SWITCH1 1 //p0.1
#define SWITCH2 3 //p0.3
#define SWITCH3 7 //p0.7


//LCD defines
#define LCD_DATA_PINS 8 //p0.0
#define RS            18 //p0.18
#define RW            20 //p0.20
#define EN            19 //p0.19


//LED defines
#define LED 20 //0.20


//DEFINING EINT0 and EINT1
#define EINT0_INPUT_PIN 0x0000000C //P0.1
#define EINT0_VIC_CHNO 14

#define EINT1_INPUT_PIN 0x000000C0 //P0.3
#define EINT1_VIC_CHNO 15

#define EINT2_INPUT_PIN 0x0000C000 //P0.7
#define EINT2_VIC_CHNO 16

//can
//defines required for C1BTR in can_defines.h

#define RD1_PIN 0x00040000

#define PCLK       60000000  //Hz
#define BIT_RATE   125000    //Hz
#define QUANTA     16
#define BRP        (PCLK/(BIT_RATE*QUANTA))
#define SAMPLE_POINT  (0.7 * QUANTA)
#define TSEG1        ((int)SAMPLE_POINT-1)  //TSEG1=prop_seg+Tph1_seg
#define TSEG2        (QUANTA-(1+TSEG1))   //TSEG2=Tph2_seg
#define SJW          ((TSEG2 >= 5)   ?   4 : (TSEG2-1))
#define SAM          0 //0 or 1 ,sample bus 1 or 3 time(s)
#define BTR_LVAL    (SAM<<23|(TSEG2-1)<<20|(TSEG1-1)<<16|(SJW-1)<<14|(BRP-1))
//defines for C1CMR bit set
#define TR_BIT_SET   1<<0
#define RRB_BIT_SET  1<<2
#define STB1_BIT_SET 1<<5

//defines for C1GSR bit check
#define RBS_BIT_READ  1<<0
#define TBS1_BIT_READ 1<<2
#define TCS1_BIT_READ 1<<3

//defines for C1CMR bit set
#define TR_BIT_SET   1<<0
#define RRB_BIT_SET  1<<2
#define STB1_BIT_SET 1<<5
//defines for C1GSR bit check
#define RBS_BIT_READ  1<<0
#define TBS1_BIT_READ 1<<2
#define TCS1_BIT_READ 1<<3						    


//utlrasonic
#define trr_pin 21
#define echo_pin 22
