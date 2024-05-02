#include"APP_Select.h"
#if( APP_SELECT	==	SLAVE_APP)

#include"../../01_MCAL/I2C/I2C.h"
#include"../../00_Lib/STD_TYPES.h"

int main(void)
{
	u8 x;

	I2C_SetSlaveAddress(0b0000100,GENERAL_CALL_ENABLE);

	DDRA =0xff;


    while(1)
    {
    	I2C_SlaveReadData(&x);
    	PORTA = x;
    }
}

#endif



