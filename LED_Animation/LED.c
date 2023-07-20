#include<avr/io.h>					/* include LED Drive		      */
#define FCPU 800000000ul			/* define CPU				      */
#include<util/delay.h>				/* include delay Library	      */
#include"Bit_Math.h"				/* include BIT MAth Library       */
#include"STD_TYPES.h"				/* include Standard Types Library */
void main()
{//opene bracket of main function
DDRA=0xff;	  /*	Configure DDRA as OUTPUT	*/
DDRB=0xff;	  /*	Configure DDRB as OUTPUT	*/
PORTB=0x00;	  /*	Clear PORTB					*/
u16 Lcal_u16_arrPINS[4]={0b10000001,PORTA=0b01000010,0b00100100,0b00011000};	/* Array to Stor PORTA PIN values	*/
while(1)		//super Loop
{//open bracket of super loop

	/* check if switch 1 is pressed */
	if( GET_BIT(PINB,0)==0)
	{//Open bracket of switch 1 conidation

		/******************************************************/
		/*	applay Flashing on LEDS As follwing				  */
		/*	1--> turn on all LEDS	and Waite 500 msec		  */
		/*	2--> turn OFF all LEDS	and Waite 500 msec		  */
		/******************************************************/
			PORTA=0xff;
			_delay_ms(500);
			PORTA=0x00;
			_delay_ms(500);
	}//close bracket of switch 1 condition

	/* check if switch 2 is pressed */
	if( GET_BIT(PINB,1)==0)
		{	//Open bracket of switch 2 conidation
			/******************************************************/
			/*	applay Shifting Left on LEDS As follwing		  */
			/*	1--> using for Loop to loop on all 8 LEDS		  */
			/*	2--> Assign PORTA to valu of shifting left 1 by i */
			/*	3--> Wiate for 250 msec 						  */
			/* LEDS will Light Sequentially from Left to Right	  */
			/******************************************************/
			for(u16 i=0;i<8;i++)
			{//open bracket of loop
				PORTA=0x01<<i;
				_delay_ms(250);
			}// close bracket of loop
		}	//close bracket of switch 2 Condition


	/* check if switch 3 is pressed */
	if( GET_BIT(PINB,2)==0)
		{	//Open bracket of switch 3 conidation
			/******************************************************/
			/*	applay Shifting Right on LEDS As follwing		  */
			/*	1--> using for Loop to loop on all 8 LEDS		  */
			/*	2--> Assign PORTA to valu of shifting right 8 by i*/
			/*	3--> Wiate for 250 msec 						  */
			/* LEDS will Light Sequentially from Right to Left	  */
			/******************************************************/
			for(u16 i=0;i<8;i++)
			{//open bracket of loop
				PORTA=0x80>>i;
				_delay_ms(250);
			}// close bracket of loop
		}	//close bracket of switch 3 Condition


	/* check if switch 4 is pressed */
	if( GET_BIT(PINB,3)==0)
	{	//Open bracket of switch 4 conidation
		/******************************************************/
		/*	applay s Converging on LEDS As follwingP:  	 	  */
		/*	1--> using for Loop to loop on all 8 LEDS		  */
		/*	loop is from 0 to 3 becouse light 2 LED every loop*/
		/*	2--> Assign PORTA to valu Enable Pins Array[i]	  */
		/*	3--> Wiate for 300 msec 						  */
		/* loop  LEDS Light one from Right and one from Left  */
		/******************************************************/
		for(int i=0;i<4;i++)
		{//open bracket of loop
			PORTA=Lcal_u16_arrPINS[i];
			_delay_ms(300);
		}// close bracket of loop
	}	//close bracket of switch 4 condiation


	/* check if switch 5 is pressed */
	if( GET_BIT(PINB,4)==0)
	{	//Open bracket of switch 4 conidation
		/******************************************************/
		/*	applay Diverging on LEDS As follwingP:  	 	  */
		/*	1--> using for Loop to loop on all 8 LEDS		  */
		/*	loop is from 3 to 0 becouse light 2 LED every loop*/
		/*	2--> Assign PORTA to valu Enable Pins Array[i]	  */
		/*	3--> Wiate for 300 msec 						  */
		/* loop  LEDS Light one from Right and one from Left  */
		/* Note: Lighting will start from 2-LEDS in the center*/
		/******************************************************/
		for(int i=3;i>=0;i--)
		{//open bracket of loop
			PORTA=Lcal_u16_arrPINS[i];
			_delay_ms(300);
		}// close bracket of loop
	}	//Close bracket of switch 5 conidation



	/* check if switch 6 is pressed */
	if( GET_BIT(PINB,5)==0)
	{	//Open bracket of switch 6 conidation
		/******************************************************/
		/*	applay Ping Pong effect on LEDS As follwing: 	  */
		/*	1-->applay Shifting Left on LEDS Like first case2 */
		/*	2-- applay Shifting Right on LEDS Like first case3*/
		/* LEDS will Light Sequentially from Left to Right	  */
		/* Then from Right to Left							  */
		/******************************************************/

		for(int i=0;i<8;i++)
		{//open bracket of shift left loop
			PORTA=0x01<<i;
			_delay_ms(250);
		}//Close bracket of shift left loop
		for(int i=0;i<8;i++)
		{//open bracket of shift right loop
			PORTA=0x80>>i;
			_delay_ms(250);
		}//Close bracket of shift right loop
	}//Close bracket of switch 6 conidation


	/* check if switch 7 is pressed */
	if( GET_BIT(PINB,6)==0)
	{	//Open bracket of switch 7 conidation
		/******************************************************/
		/*	applay Snake effect on LEDS As follwing: 	 	  */
		/*	1--> using for Loop to loop on all 8 LEDS		  */
		/*	loop is from 3 to 0 becouse light 2 LED every loop*/
		/*	2--> incerment PORTA value by 1					  */
		/*	3--> Wiate for 250 msec 						  */
		/******************************************************/
		for(int i=0;i<8;i++)
		{//open bracket of loop
			PORTA++;
			_delay_ms(250);
		}//close bracket of loop

	}//Close bracket of switch 7 conidation



	/* check if switch 8 is pressed */
	if( GET_BIT(PINB,7)==0)
	{	//OPen bracket of switch 8 conidation
		/******************************************************/
		/*	applay s case4&case5 effect on LEDS As follwing:  */
		/*	1-->applay  Converging on LEDS Like  case4		  */
		/*	2-- applay  Diverging  on LEDS Like  case5		  */
		/* loop  LEDS Light one from Right and one from Left  */
		/* loop  LEDS Light one from Right and one from Left  */
		/* Note: Lighting will start from 2-LEDS in the center*/
		/******************************************************/
		for(int i=0;i<4;i++)
			{//open bracket of Converging loop
				PORTA=Lcal_u16_arrPINS[i];
				_delay_ms(300);
			}//close bracket of Converging loop
		for(int i=3;i>=0;i--)
			{//open bracket of diverging loop
				PORTA=Lcal_u16_arrPINS[i];
				_delay_ms(300);
			}//Close bracket of diverging loop

	}//Close bracket of switch 8 conidation
	if(PORTB==0x00)
	{

	PORTA=0x00;
	}
 }//Close bracket of super loop
}//close bracket of main function
