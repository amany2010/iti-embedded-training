/*
 * main.c
 *
 *  Created on: Sep 27, 2021
 *      Author: bahgat
 */
#include<avr/io.h>					/* include LED Drive		      */
#include "util/delay.h"
#define FCPU 800000000ul			/* define CPU				      */
#include"Bit_Math.h"				/* include BIT MAth Library       */
#include"STD_TYPES.h"				/* include Standard Types Library */
void UP()
{

	PORTA=0xFF;
	PORTB=0xFE;
	_delay_ms(20);
	PORTB=0xFD;
	_delay_ms(20);
	PORTB=0xFB;
	_delay_ms(20);
	PORTB=0xF7;
	_delay_ms(20);
	PORTB=0xEF;
	_delay_ms(20);
	PORTB=0xDF;
	_delay_ms(20);
	PORTB=0xBF;
	_delay_ms(20);
	PORTB=0x7F;
	_delay_ms(20);
}
void DOWN()
{
			PORTA=0xFF;
			PORTB=0x7F;
			_delay_ms(20);
			PORTB=0xBF;
			_delay_ms(20);
			PORTB=0xDF;
			_delay_ms(20);
			PORTB=0xEF;
			_delay_ms(20);
			PORTB=0xF7;
			_delay_ms(20);
			PORTB=0xFB;
			_delay_ms(20);
			PORTB=0xFD;
			_delay_ms(20);
			PORTB=0xFE;
			_delay_ms(20);

}
void Right()
{
	PORTB=0x00;
	PORTA=0x80;
	_delay_ms(20);
	PORTA=0x40;
	_delay_ms(20);
	PORTA=0x20;
	_delay_ms(20);
	PORTA=0x10;
	_delay_ms(20);
	PORTA=0x08;
	_delay_ms(20);
	PORTA=0x04;
	_delay_ms(20);
	PORTA=0x02;
	_delay_ms(20);
	PORTA=0x01;
	_delay_ms(20);
}
void LEFT()
{
	PORTB=0x00;
	PORTA=0x01;
	_delay_ms(20);
	PORTA=0x02;
	_delay_ms(20);
	PORTA=0x04;
	_delay_ms(20);
	PORTA=0x08;
	_delay_ms(20);
	PORTA=0x10;
	_delay_ms(20);
	PORTA=0x20;
	_delay_ms(20);
	PORTA=0x40;
	_delay_ms(20);
	PORTA=0x80;
	_delay_ms(20);
}
void main (void)
{
	DDRA=0xff;
	PORTA=0x00;
	DDRB=0xff;
	PORTB=0x00;
	while(1)
	{

		DOWN();
		UP();
		Right();
		LEFT();
	}

}
