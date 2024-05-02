
#include"APP_Select.h"

#if (APP_SELECT== MASTER_APP)

#include"../../01_MCAL/I2C/I2C.h"
#include"../../00_Lib/Delay.h"
#include"../../00_Lib/STD_TYPES.h"
#include<util/delay.h>

int main(void)
{

	u8 counter=0;
	I2C_MASTER_init(50000);

	while(counter<10)
	{
		_delay_ms(200);
		I2C_SendSTART(); // transmit start condition
		I2C_SendAddress(0b0000000,WRITE_OPERATION); // transmit SLA+W
		I2C_SendData(counter); // transmit data
		I2C_SendSTOP(); // transmit stop condition
		counter++;
	}
}



#endif
