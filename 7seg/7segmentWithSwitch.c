#include<avr/io.h>
#define F_CPU 8000000UL
#include<avr/delay.h>
#include"../../Headers/STD_TYPES.h"
#include"../../Headers/Bit_Math.h"
#include"../../Headers/Number_Segment.h"
void main(void)
{
	u8 Local_int_Arr[10]={Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine};
		DDRA=0xFF;
		DDRB=0xFF;
		while(1)
		{
				for(u16 i=0;i<30;i++)
				{
						if(i<10)
						{
						PORTA=Local_int_Arr[i];
						PORTB=0x00;
						}
						else
						{
							PORTA=Local_int_Arr[i/10];
							PORTB=Local_int_Arr[i%10];
						}
				}
		}
}



