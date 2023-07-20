/****************************************************/
AS/* Library Directives							    */
/****************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/array_Search.h"
#include <util/delay.h>
/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"
/****************************************************/
/* UART Directives								    */
/****************************************************/
#include "../Include/MCAL/UART/UART_Interface.h"
#include "../Include/MCAL/UART/UART_Private.h"
#include "../Include/MCAL/UART/UART_Configuration.h"
/****************************************************/
/* TIMER Directives								    */
/****************************************************/
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configuration.h"

/****************Function To control on Home LEDS**********************/
/* function get LED number as a parameter 							 */
/* OPtuions:														 */
/* 1--> Turn on/off LED1											 */
/* 2--> Turn on/off LED2											 */
/* 3--> Turn on/off LED3											 */
/* 4--> Turn on/off All LEDS										 */
/* 5--> return														 */
/* Fuction Body:													 */
/* 1- defin 4 static local flags,3 to 3LED & 1 to control on all LEDS*/
/* 2- Check LED Number by Switch statement							 */
/* 3- Check LED Flag:												 */
/*						1- Flage Up->turn off LED	,make flag Down	 */
/*  					2- Flage Down->turn on LED ,,make flag UP	 */
/*********************************************************************/

void LIGHT_Controller()
{//open bracket of function
	static u8 LOCAL_u8_flag1=0, LOCAL_u8_flag2=0, LOCAL_u8_flag3=0, LOCAL_u8_flag4=0,Local_u8_x;
	UART_voidPrintf("1->LED1\n2->LED2\n3->LED3\n4->AllLEDS\n5->Return\n");
	while(1)																			        /* While Loop To user Choices													   */
	{//open bracket of while loop
		Local_u8_x=UART_RecieveData();															/* Calling UART Recive function To Recive Choice from user						   */
		switch(Local_u8_x)																		/* Check user choice  by switch													   */
		{//Open Bracket of Switch
			case '1':                                            								/* If user Choice To Turn On/Off LED1											   */
				if (LOCAL_u8_flag1==0)															/* Cheack if Flage1 is Down														   */
					{//open bracket of flag1 condition
						MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);				/* Set Pin0 from Port B to High To Turn On LED1									   */
						LOCAL_u8_flag1=1;														/* Set Falg1 UP																	   */
					}//close bracket of flag1 condition
					else                                                                         /*  if Flage1 is Up															   */
					{//open bracket of flag1 else condition
						MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);               /* Set Pin0 from Port B to LOW To Turn OFF LED1								   */
						LOCAL_u8_flag1=0,LOCAL_u8_flag4=0;                                       /* Set Falg1 DOWN																   */
					}//close bracket of flag1 condition
				break;/*	End Of Case 1	*/
			case '2':                                                                             /* If user Choice To Turn On/Off LED1											   */
					if (LOCAL_u8_flag2==0)                                                        /* Cheack if Flage2 is Down													   */
						{//open bracket of flag2 condition
                                                                                                  /* Set Pin1 from Port B to High To Turn On LED2								   */
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);           /* Set Falg2 UP																   */
							LOCAL_u8_flag2=1;
						}//close bracket of flag2 condition
						else                                                                      /*  if Flage2 is Up															   */
						{//open bracket of flag2 else condition
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);            /* Set Pin1 from Port B to LOW To Turn OFF LED2								   */
							LOCAL_u8_flag2=0,LOCAL_u8_flag4=0;                                    /* Set Falg2 DOWN																   */
						}//close bracket of flag2 else condition
					break;/*	End Of Case 2	*/
			case '3':                                                                             /* If user Choice To Turn On/Off LED3											   */
					if (LOCAL_u8_flag3==0)                                                        /* Cheack if Flage3 is Down													   */
						{//open bracket of flag3 condition
                                                                                                  /* Set Pin2 from Port B to High To Turn On LED3								   */
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);           /* Set Falg3 UP																   */
							LOCAL_u8_flag3=1;
						}//close bracket of flag2 condition
						else                                                                      /*  if Flage3 is Up															   */
						{//open bracket of flag3 else condition
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);            /* Set Pin2 from Port B to LOW To Turn OFF LED1								   */
							LOCAL_u8_flag3=0,LOCAL_u8_flag4=0;                                    /* Set Falg3 DOWN																   */
						}//close bracket of flag3 else condition
					break;/*	End Of Case 3	*/
			case '4':                                                                             /* If user Choice To Turn On/Off All LEDs										   */
					if (LOCAL_u8_flag4==0)                                                        /* Cheack if Flage4 is Down													   */
						{//open bracket of flag4 condition
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);           /* Set Pin0 from Port B to High To Turn On LED1								   */
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);           /* Set Pin1 from Port B to High To Turn On LED2								   */
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);			  /* Set Pin2 from Port B to High To Turn On LED3								   */
							LOCAL_u8_flag1=1,LOCAL_u8_flag2=1,LOCAL_u8_flag3=1,LOCAL_u8_flag4=1;  /* Set Falg1,Falg2,Falg3,Falg4 to UP											   */
						}//close bracket of flag4 condition
						else                                                                      /*  if Flage4 is UP															   */
						{//open bracket of flag4 else condition
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);            /* Set Pin0 from Port B to LOW To Turn OFF LED1								   */
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);            /* Set Pin1 from Port B to LOW To Turn OFF LED2								   */
							MDIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);            /* Set Pin2 from Port B to LOW To Turn OFF LED3								   */
							LOCAL_u8_flag4=0,LOCAL_u8_flag1=0,LOCAL_u8_flag2=0,LOCAL_u8_flag3=0;  /* Set Falg1,Falg2,Falg3,Falg4 to DOWN										   */
						}//close bracket of flag4 else condition
					break;/*	End Of Case 4	*/
			case'5':
				return;//Eixt from function
		}//close bracket of switch
	}//close bracket of While Loop

}//Close Bracket of function

/****************Function To control on Door Lock*********************/
/* function get LED number as a parameter  							 */
/* OPtuions:														 */
/* 1-->	Open Door													 */
/* 2--> Lock Door													 */
/* 3--> return														 */
/* Fuction Body:													 */
/* 1- Variables:										   			 */
/*  - 2 arrays of String for user Names and passwords				 */
/*  - 2 arrays of char to recive user Name and password from user	 */
/*  - char varibale to recive charchter data from user				 */
/*  - Integer variable for user name&password Attempts Number		 */
/*	- 2 integer variable to stor: 1-user Name postition in array	 */
/* 								  2- password postition	in array	 */
/*	 That returned from search Function								 */
/* 2- While Loop on attempts number									 */
/* 3-condition to cheack if userentered correct username and password*/
/* 		or Attempts Number are zero(Turn on Red Led as alarm)		 */
/* 4- While Loop on Door conroller	choice							 */
/* 5- Check user Choice:											 */
/*						1- Open->Servo Motor rotate 180 degree		 */
/*  					2- Lock->Servo Motor rotate 90 degree		 */
/*  					3- Return-> Exit From Function				 */
/*********************************************************************/

void Door_controller()
{//Open bracket of Door Controller Function
	u8 *Local_u8_userName[10]={"Ahmed","Amany","Amr","Assia","Aya","johan","joy","june","malak","Shorok"};
	u8 *Local_u8_Password[10]={"0000","1111","2222","3333","4444","5555","6666","7777","8888","9999"};
	u8 Local_u8_Recived_value=0,Local_u8_UserName[3],Local_u8_pass[5];
	u16 Local_u16Attemps_Number=3,Local_u16userName_Pos,Local_u16PassWord_Pos;

	 while(Local_u16Attemps_Number>0)
	 {// open bracket of attempets number loop

		 	UART_voidPrintf("Enter UserName Then #\n");										      /*Calling UART print function To Display This Sentence	on user Screen	       */
			UART_recieve_string(Local_u8_UserName);										          /*Calling UART Recive String function To Recive User Name from user		       */
			Local_u16userName_Pos=search(Local_u8_userName,Local_u8_UserName);			          /* Calling Search Function To get userName posintion in array				       */
			UART_voidPrintf("\nEnter Password Then #\n");                       		          /*Calling UART print function To Display This Sentence	on user Screen	       */
			UART_recieve_string(Local_u8_pass);                                 		          /*Calling UART Recive String function To Recive Password from user		       */
			Local_u16PassWord_Pos=search(Local_u8_Password,Local_u8_pass);				          /* Calling Search Function To get Password posintion in array				       */
			/********************************************************************/
			/* if condition To cheak:											*/
			/*	1-user Name and Password have The Sum Posion To be valid but	*/
			/* 	 Position Not Equal -1(Hint: -1 means Not Found in array)		*/
			/********************************************************************/
			if((((Local_u16userName_Pos!=-1)&&(Local_u16PassWord_Pos!=-1))&&
				(Local_u16userName_Pos==Local_u16PassWord_Pos)))
				{//open bracket of found Condition
					break;//Exit From While Loop
				}//Close bracket of found Condition
			else if(Local_u16Attemps_Number>1)											          /* cheack if user name and Password are Incorrect & There are attempets		   */
				{//open bracket of incorrect user name and password
					UART_voidPrintf("Incorrect username or password try again....\n");	          /* Calling UART print function To Display This Sentence	on user Screen		   */
					UART_Transmitnum(Local_u16Attemps_Number-1);						          /*Calling UART print Number function To Display attempts number	on user Screen */
					UART_voidPrintf(" attempts allwoed\n");								          /*Calling UART print function To Display This Sentence	on user Screen		   */
				}//Close bracket of incorrect user name and password
			Local_u16Attemps_Number--;													          /* Incerement attempts number by 1											   */
	 }// Close bracket of attempets number loop

	 if(Local_u16Attemps_Number==0)														          /* cheack if user name and Password are Incorrect & There are Not attempets		*/
	 {//open bracket of incorrect user name and password&No attempets
		 UART_voidPrintf("sorry, Attempts allowed are zero\n");							          /* Calling UART print function To Display This Sentence	on user Screen		   	*/
		 MDIO_voidSetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_HIGH);					          /* Turn On Red Led(by Set Pint2 value as High) As alarm							*/
		 _delay_ms(1000);																          /* Wait 1 Sec																		*/
		 MDIO_voidSetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);						          /* Turn Off Red Led (by Set Pint2 value as LOW)									*/
	 }//Close bracket of incorrect user name and password&No attempets
	 else																				          /* Correct user Name and Password condition										*/
	 {//open bracket of correct user name and password condition
		UART_voidPrintf("\n1->Open Door\n2->Loock Door\n3->Return\n");					          /* Calling UART print function To Display Choices Menu on user Screen	    	   	*/
		while(1)																		          /* While Loop To user Choices														*/
		{//oopen bracket of user Choices Loop
			Local_u8_Recived_value=UART_RecieveData();									          /* Calling UART Recive function To Recive Choice from user						*/
			switch(Local_u8_Recived_value)												          /* Check user choice  by switch													*/
			{//open bracjet of switch
				case '1':																          /* if user choice Open Door														*/
					MTIMERS_voidTimer1Init(180);										          /* Calling timer 1 intialize function with degree 180								*/
					break;//end of case 1
				case'2':                                                                          /* if user choice Lock Door														*/
					MTIMERS_voidTimer1Init(90);                                                   /* Calling timer 1 intialize function with degree 90								*/
					break;//end of case 1
				case '3':                                                                         /* if user choice Return															*/
					return; //end of case 1                                                       /* Exit from function																*/
			}//open bracjet of switch
		}//oopen bracket of user Choices Loop
	 }//Close bracket of correct user name and password condition
}//Close bracket of Door Controller Function
