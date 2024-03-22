
#include "../Tasks.h"

// Check if the selected lab is Lab5_Test
#if (WANNTED_LAB == ICU_TEST)

#include"../../00_Lib/Bit_Math.h"
#include"../../00_Lib/STD_TYPES.h"

#include "../../02_HAL/LCD/LCD.h"

#include "../../01_MCAL/TIMER/Timer0and2/TIMER.h"
#include "../../01_MCAL/TIMER/Timer1/TIMER1.h"
#include "../../01_MCAL/ICU/ICU.h"





int main(){
	u16 duty,freq;
	LCD_init();
	Icu_vidInit();

	TMR0_voidInitPreCompile();
	TMR0_enuSetDutyCycleFastPWM(40,INVERTING_MODE);
	TMR0_enuStart();

	Icu_vidCalculations(&duty,&freq);
	LCD_enuWriteString("Duty Cycle:",11);
	LCD_enuWriteNumber(duty);
	LCD_enuWriteString("%",1);
	LCD_enuGotoDDRAM_XY(2,1);
	LCD_enuWriteString("Frequency:",10);
	LCD_enuWriteNumber(freq);


while (1)
{

}


	return 0;
}

#endif



