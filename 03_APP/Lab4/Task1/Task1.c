/*
 * main.c
 *
 * Created: 12/24/2023 4:18:34 PM
 *  Author: KimoStore
 */

#include "../../Tasks.h"
// Check if the selected lab is LAB2
#if (WANNTED_LAB == LAB4_Task1)

#include"../../../00_Lib/Bit_Math.h"
#include"../../../00_Lib/STD_TYPES.h"
#include "../../../02_HAL/LED/LED.h"
#include "../../../02_HAL/SW/SW.h"
#include "../../../02_HAL/_7_SEG/_7_SEG.h"
#include "../../../00_Lib/Delay.h"
#include "../../../01_MCAL/EXT-INT/Ext_Interrupts.h"
#include "../../../02_HAL/LCD/LCD.h"


int main(void)
{	
	/*Function Initialization*/
	LCD_init();
	
	
	/*Display a character*/
	LCD_enuWriteData('A');
	Delay(0.2);
	
	/*Move to a specific location */
	LCD_enuGotoDDRAM_XY(FIRST_LINE,2);
	Delay(0.3);
	
    /*Display a number*/
	LCD_enuWriteNumber(125);
    Delay(0.5);
	
	LCD_enuGotoDDRAM_XY(FIRST_LINE,5);
	
	/*Display a string*/
	LCD_enuWriteString("Fatma Ezzat",12);
	Delay(0.5);
	
	/*Display generic characters*/
	u8 arr1[8]= {0b00100,0b00100,0b00100,0b00100,0b10101,0b01110,0b00100,0b00100};
	u8 arr2[8]= {0b00000,0b00000,0b11011,0b10101,0b01110,0b00100,0b00000,0b00000};
	LCD_enuDisplaySpecialPattern(arr1,1,SECOND_LINE, 10);
	Delay(0.5);
	LCD_enuDisplaySpecialPattern(arr2,3,SECOND_LINE, 12);
	Delay(0.5);
	
    while (1)
    {		
    }	
}
#endif
