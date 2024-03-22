/*
 * Task2.c
 *
 * Created: 12/19/2023 9:23:23 AM
 *  Author: FatmaEzzat
 */ 
#include "../../Tasks.h"
// Check if the selected lab is LAB2
#if (WANNTED_LAB == LAB3_Task2)

#include"../../../00_Lib/Bit_Math.h"
#include"../../../00_Lib/STD_TYPES.h"
#include "../../../00_Lib/Delay.h"
#include "../../../02_HAL/LED/LED.h"
#include "../../../02_HAL/SW/SW.h"
#include "../../../02_HAL/_7_SEG/_7_SEG.h"

int main(void)
{
    /*Function Initialization*/
	LED_enumInit();
	SW_enumInit();
	_7SEG_init();
	
	/*Switch variables to store their readings */
	u8 SW1_Value = LogicHigh;
    u8 SW2_Value = LogicHigh;
    u8 SW3_Value = LogicHigh;
	s8 counter =0;
	
	/*These flags will be used to ensure the switch press counts once only*/
	u8 SW1_Flag = 0;
	u8 SW2_Flag = 0;
	u8 SW3_Flag = 0;
	
	while(1){
		/*****************Read Swiches values*****************/
		SW_enumReadSWState(SW1 ,&SW1_Value);
		SW_enumReadSWState(SW2 ,&SW2_Value);
		SW_enumReadSWState(SW3 ,&SW3_Value);
		
		/*
		*@brief : For Switch 1 ---> Increment the timer value	
		*/
		if((SW1_Value == LogicLow)&& (SW1_Flag == 0)){
			SW1_Flag=1;
			counter++;
		
		/*******Display the counter value**********/
			_7SEG_enuSetValueForAllSegs(counter); 
		}else if(SW1_Value == LogicHigh){
			SW1_Flag = 0;
		}	
		
		/*
		*@brief : For Switch 2 ---> Decreament the timer value
		*/
		if ((SW2_Value == LogicLow)&&(SW2_Flag == 0)){
			SW2_Flag = 1;
			
		/*Limits the counter value to zero, preventing it from reaching negative values*/	
			if(counter >= 0){
			counter--;
			}else{
				counter = 0;
			}
			
		/*******Display the counter value**********/
		_7SEG_enuSetValueForAllSegs(counter);
			
		}else if(SW2_Value == LogicHigh){
			SW2_Flag = 0;
		}
		
		/*
		*@brief : For Switch 3 ---> Start the countdown of the timer
		*/
		if ((SW3_Value == LogicLow)&&(SW3_Flag == 0)){
			SW3_Flag = 1;
			
			while(counter >= 0){
				
				counter--;
				_7SEG_enuSetValueForAllSegs(counter);
				Delay(0.5);
			}
			/*When the counter value reaches to zero ,LED will turn on*/
			LED_enumSetValue(LED1,DIO_enumOutputHIGH);
			Delay(1);
			LED_enumSetValue(LED1,DIO_enumOutputLOW);
			
		}else if (SW3_Value == LogicHigh){
			SW3_Flag = 0 ;
		}
		
		//Delay(0.25);
	}	
}

#endif