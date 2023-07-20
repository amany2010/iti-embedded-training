#include<avr/io.h>
#define F_CPU 8000000UL
#include<avr/delay.h>
#include"Headers/STD_TYPES.h"
#include"Headers/Bit_Math.h"
#include"Headers/Number_Segment.h"

void main(void)																	/* Calling main Function						                     */
{//open bracket of main function
	u8 Local_int_Arr[10]={Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine};	/* LOCAL u8 Array to Stor binary Numbers from 0 to 9                 */
	u16 Local_u16_Count;														/* Local unsigned short Counter						                 */
		DDRA=0xFF;																/* Configuring All PORTA Output					                     */
		DDRB=0xFF;																/* Configuring All PORTB Output					                     */
		DDRC=0xFF;																/* Configuring All PORTC Output					                     */
		while(1)																/* Loop To  make program repeat froever			                     */
		{//open bracket of while loop                                                                                                                */
			for(Local_u16_Count=10;Local_u16_Count>0;Local_u16_Count--)			/* Loop to to turn on green led for 10 second		                 */
			{//open bracket of for Loop
				PORTC=PORTC_PIN0;												/* Configure Pin C0 in Output mode(Green LED)			             */
				if(Local_u16_Count<10)											/*  Check if counter is smaller than 10				                 */
				{//open bracket of if Condition
				PORTA=Local_int_Arr[Local_u16_Count];							/* Configuring PORTA[0](digit1 from counter) as  Output			     */
				PORTB=0x00;														/* Configuring PORTB[counter](digit2 from counter)as Output		     */
				}//Close bracket of if Condition                                                                                                     */

				else															/* If time more than 9 (Two digit)					                 */
				{//open bracket of else                                                                                                              */
					PORTA=Local_int_Arr[Local_u16_Count/10];					/* Configuring PORTA[counter/10](digit1 from counter) as  Output	 */
					PORTB=Local_int_Arr[Local_u16_Count%10];					/* Configuring PORTB[counter%10](digit2 from counter) as  Output	 */
				}//Close bracket of else
				_delay_ms(1000);												/* Wait for 1sec   													 */
			}//Close bracket of for Loop

			for(Local_u16_Count=3;Local_u16_Count>0;Local_u16_Count--)          /* Loop to to turn on Yellow led for 3 second					   	 */
			{//open bracket of for loop

				PORTC=PORTC_PIN1;                                                /* Configure Pin C1 in Output mode	(yellow LED)				 	 */
				PORTA=Local_int_Arr[Local_u16_Count];                            /* Configuring PORTA[0] as  Output			                 */
				PORTB=0x00;								                         /* Configuring PORTB[counter] as  output						                 */
				_delay_ms(1000); 												 /* Wait for 1sec													 */

			}//Close bracket of for loop

			for(Local_u16_Count=10;Local_u16_Count>0;Local_u16_Count--)          /* Loop to to turn on Red led for 10 second		                 */
			{//open bracket of for function
				PORTC=PORTC_PIN2;												 /* Configure Pin C2 in Output mode(RED LED)			             */
				if(Local_u16_Count<10)                                           /*  Check if counter is smaller than 10				             */
				{ //open bracket of if condition
					PORTA=Local_int_Arr[Local_u16_Count];						/* Configuring PORTA[0](digit1 from counter) as  Output			     */
					PORTB=0x00;													/* Configuring PORTB[counter](digit2 from counter)as Output		     */
				}  //open bracket of if condition
				else                                                             /* If time more than 9 (Two digit)					                 */
				{  //open bracket of else
					PORTA=Local_int_Arr[Local_u16_Count/10];                     /* Configuring PORTA[counter/10](digit1 from counter) as  Output	 */
					PORTB=Local_int_Arr[Local_u16_Count%10];                     /* Configuring PORTB[counter%10](digit2 from counter) as  Output	 */
				}//Close bracket of else
				_delay_ms(1000);                                                  /* Wait for 1sec   												 */
			}  //Close bracket of for loop
	}      //Close bracket of While loop
}//Close bracket of main Function
