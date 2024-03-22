/*
 * Task1.c
 *
 * Created: 12/18/2023 9:23:23 AM
 *  Author: FatmaEzzat
 */ 
#include "../../Tasks.h"

// Check if the selected lab is LAB1
#if (WANNTED_LAB == LAB3_Task1)

#include"../../../00_Lib/Bit_Math.h"
#include"../../../00_Lib/STD_TYPES.h"
#include "../../../01_MCAL/DIO/DIO.h"
#include "../../../02_HAL/LED/LED.h"
#include "../../../02_HAL/SW/SW.h"
#include "../../../02_HAL/_7_SEG/_7_SEG.h"

int main(void)
{
	_7SEG_init();
	_7SEG_enuSetValueForAllSegs(353);
	
}

#endif