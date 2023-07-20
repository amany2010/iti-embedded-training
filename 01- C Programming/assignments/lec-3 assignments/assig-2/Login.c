#include<stdio.h>												/*include Output & input Library*/
#include"../STD_TYPES.h"										/* include data types header	*/

void main(void)													/* calling main function		*/
{/*open bracket of main function*/
	
	/************************************************************/
	/* Local_u16_ID		   : To take ID From user				*/
	/* Local_u16_password  : To take Passsworfd from user		*/
	/* Local_u16_count	   : To count number of password tries	*/
	/************************************************************/
	u16 Local_u16_ID,Local_u16_password,Local_u16_count=3;
	printf("PLease Enter ID :");								/* Ask user To Enter ID									*/
	scanf("%d",&Local_u16_ID);	     							/* Get ID from user										*/
	switch(Local_u16_ID)										/* Cheack Entered Id									*/
	{// open Bracket of switch
		case 1234:												/* if it's Ahmed ID										*/
			while(Local_u16_count!=0)							/* Loop to Count number of Password tries				*/
			{//open brackets of while loop
				printf("PLease Enter Password :");				/* Ask user To Enter Password							*/
				scanf("%d",&Local_u16_password);				/* Get Password from user								*/
				
				if(Local_u16_password==7788)					/* Check if it's Ahmed Password							*/
				{//open brackets of if
					printf("Welcome Ahmed \n");					/* Print Welcom Ahmed									*/
					break;										/* break from While Lof									*/
				}//close brackets of if
				
				else if(Local_u16_count!=1)						/* if Password Not correct & number of tries less than3	*/
				{//open brackets of else
					printf("try again ...\n");					/* Print Try again										*/
				}//close brackets of else
				
				--Local_u16_count;								/* Increment Counter By 								*/
			}//close brackets of while loop
		break;													/* End of Case 2										*/

		case 5678:												/* if it's Amr ID										*/
			while(Local_u16_count!=0)							/* Loop to Count number of Password tries				*/
			{//open brackets of while loop
				printf("PLease Enter Password :");				/* Ask user To Enter Password							*/
				scanf("%d",&Local_u16_password);				/* Get Password from user								*/
				
				if(Local_u16_password==5566)					/* Check if it's Amr Password							*/
				{//open brackets of if
					printf("Welcome Amr \n");					/* Print Welcom Amr										*/
					break;										/* break from While Lof									*/
				}//close brackets of if
				
				else if(Local_u16_count!=1)						/* if Password Not correct & number of tries less than3	*/
				{//open brackets of else
					printf("try again ...\n");					/* Print Try again										*/
				}//close brackets of else
				
				--Local_u16_count;								/* Increment Counter By 1								*/
			}//close brackets of while loop
		break;													/* End of Case 2										*/
		
		case 9870:												/* if it's Wael ID										*/
		while(Local_u16_count!=0)								/* Loop to Count number of Password tries				*/
		{//open brackets of while loop
			printf("PLease Enter Password :");					/* Ask user To Enter Password							*/
			scanf("%d",&Local_u16_password);					/* Get Password from user								*/
			
			if(Local_u16_password==1122)						/* Check if it's Wael Password							*/
			{//open brackets of if
				printf("Welcome Wael \n");						/* Print Welcom Wael									*/
				break;											/* break from While Lof									*/
			}//close brackets of if
			
			else if(Local_u16_count!=1)							/* if Password Not correct & number of tries less than3	*/
			{//open brackets of else
				printf("try again ...\n");						/* Print Try again										*/
			}//close brackets of else
			
			--Local_u16_count;									/* Increment Counter By 								*/
		
		}//close brackets of while loop
		break;													/* End of Case 3										*/

		default:												/* if ID Is Not Correct									*/
		printf("You are not registered\n");						/* Print Id Not Registered								*/
		break;													/* End of default										*/
	}// Close Bracket of switch
	
	if(Local_u16_count==0)											/* Check if number of tries equal 3						*/
	{//open brackets of if
		printf("Sorry No more tries...\n");							/* Print No more tries									*/
	}//close brackets of if
	
}/*close bracket of main function*/
	