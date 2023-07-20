#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/delay.h>
#include"../../Headers/STD_TYPES.h"
#include"../../Headers/Bit_Math.h"
void main(void)
{
	u8 Local_int_Arr[10]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
	DDRA=0xFF;
	DDRB=0x00;
	PORTB=0x01;
	while(1)
	{
		for(u8 i=0;i<10;i++)
			{
			if(GET_BIT(PINB,0)==0)
				{
					PORTA=Local_int_Arr[i];
					_delay_ms(1000);
				}
			else
				{
					PORTA=0x00;
				}
			}
	}
}
