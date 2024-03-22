/*
 * Task2.c
 *
 * Created: 1/3/2024 10:09:30 AM
 *  Author: Fatma Ezzat
 */ 

#include "../../Tasks.h"

// Check if the selected lab is LAB2
#if (WANNTED_LAB == LAB4_Task2)

#include"../../../00_Lib/Bit_Math.h"
#include"../../../00_Lib/STD_TYPES.h"
#include "../../../00_Lib/Delay.h"
#include "../../../01_MCAL/EXT-INT/Ext_Interrupts.h"
#include "../../../02_HAL/LED/LED.h"
#include "../../../02_HAL/SW/SW.h"
#include "../../../02_HAL/_7_SEG/_7_SEG.h"
#include "../../../02_HAL/LCD/LCD.h"

extern LED_StrCfg LEDs[NUM_Of_LEDs];
void Tog_LED1(void){
    DIO_enumSetPin(LEDs[LED1].port,LEDs[LED1].pin,LogicHigh);
	Delay(2);
	DIO_enumSetPin(LEDs[LED1].port,LEDs[LED1].pin,LogicLow);
	Delay(1);
}
void Tog_LED2(void){
	DIO_enumSetPin(LEDs[LED2].port,LEDs[LED2].pin,LogicHigh);
	Delay(2);
	DIO_enumSetPin(LEDs[LED2].port,LEDs[LED2].pin,LogicLow);
	Delay(1);
}
void Tog_LED3(void){
	DIO_enumSetPin(LEDs[LED3].port,LEDs[LED3].pin,LogicHigh);
	Delay(1);
	DIO_enumSetPin(LEDs[LED3].port,LEDs[LED3].pin,LogicLow);
	Delay(1);
}

int main(void){
	
	/*Function Initialization*/
	SW_enumInit();
	_7SEG_init();
	LED_enumInit();
	EXT_INT_enumInit();
	
	/*Assign the application function to ISR*/
	setcallback_INT0(Tog_LED1);
	setcallback_INT1(Tog_LED2);
	setcallback_INT2(Tog_LED3);
	
	/*Switch variables to store their readings */
	u8 Loc_u8SwValue1 = LogicHigh;
	u8 Loc_u8SwValue2 = LogicHigh;
	u8 Loc_u8SwValue3 = LogicHigh;
	u8 Loc_u8SwValue4 = LogicHigh;
	u8 Loc_u8SwValue5 = LogicHigh;
	
	/*These flags will be used to ensure the switch press counts once only*/
	u8 Loc_u8SwFlag1 = 0;
	u8 Loc_u8SwFlag2 = 0;
    u8 counter =0;
	while (1)
	{
		/*Read Switches state*/
		SW_enumReadSWState(SW1,&Loc_u8SwValue1);
		SW_enumReadSWState(SW2,&Loc_u8SwValue2);
		SW_enumReadSWState(SW3,&Loc_u8SwValue3);
		SW_enumReadSWState(SW4,&Loc_u8SwValue4);
		SW_enumReadSWState(SW5,&Loc_u8SwValue5);
		
		/*For Switch1*/
		if ((Loc_u8SwValue4 ==LogicLow )&&(Loc_u8SwFlag1==0))
		{
			Loc_u8SwFlag1 = 1;
			counter++;
			_7SEG_enuSetValue(_7_SEG1,counter);
				
		}else if(Loc_u8SwValue4 ==LogicHigh ){
			Loc_u8SwFlag1 = 0;
		}
		/*For Switch2*/
		if ((Loc_u8SwValue5 ==LogicLow )&&(Loc_u8SwFlag2==0))
		{
			Loc_u8SwFlag2 = 1;
			counter--;
			_7SEG_enuSetValue(_7_SEG1,counter);
			
			}else if(Loc_u8SwValue5 ==LogicHigh ){
			Loc_u8SwFlag2 = 0;
		}
		
		/*To limit the counter value between 0 and 1*/
		if((counter > 9) ||(counter < 0)){
			counter = 0;
		}		
	}
	return 0;
}
#endif