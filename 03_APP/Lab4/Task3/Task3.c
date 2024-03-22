/*
 * Task3.c
 *
 * Created: 1/3/2024 12:38:33 PM
 *  Author: Fatma Ezzat
 */ 
#include "../../Tasks.h"

// Check if the selected lab is LAB2
#if (WANNTED_LAB == LAB4_Task3)

#include"../../../00_Lib/Bit_Math.h"
#include"../../../00_Lib/STD_TYPES.h"
#include "../../../00_Lib/Delay.h"
#include "../../../01_MCAL/EXT-INT/Ext_Interrupts.h"
#include "../../../02_HAL/LED/LED.h"
#include "../../../02_HAL/SW/SW.h"
#include "../../../02_HAL/_7_SEG/_7_SEG.h"
#include "../../../02_HAL/LCD/LCD.h"
#define NUM_OF_CHAR 12
int main(void){
	
	/*Function Initialization*/
	LCD_init();
	
	/*Display a string*/
	u8 name [NUM_OF_CHAR]="Fatma Ezzat";
	
	LCD_enuWriteString(name,NUM_OF_CHAR);
	
	while(1){
		/*String Movement*/
		for (u8 counter = 0;counter< NO_OF_Columns ;counter++)
		{
			LCD_enuWriteCommand(SHIFT_ENTIRE_DISPLAY_RIGHT);
			Delay(0.3);
		}
		
		for (u8 counter = 0; counter< NO_OF_Columns +NUM_OF_CHAR ;counter++)
		{
			LCD_enuWriteCommand(SHIFT_ENTIRE_DISPLAY_LEFT);
			Delay(0.3);
		}
		/* Return to the initial position */
		for (u8 counter = 0; counter<  NUM_OF_CHAR ;counter++)
		{
			LCD_enuWriteCommand(SHIFT_ENTIRE_DISPLAY_RIGHT);
			Delay(0.3);
		}
	}
}
#endif