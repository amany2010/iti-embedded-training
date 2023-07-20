/****************************************************/
/*   AUTHOR      : Amany Abdelfattah                */
/*   Description : clinic management system         */
/*   DATE        : 22 AGU 2021                      */
/****************************************************/

#include <stdio.h>													/* include Input and output Library 							*/
#include"LinkedList_Interface.h"									/* include LinkedList File Header 								*/
#include<stdlib.h>													/* include std libraries										*/
int main ()															/* calling Main Function										*/
 {																	/* open bracket of Main Function								*/

 Global_short_flag=0;												/*assign flag to 0												*/
u16 Local_Short_admin_Password;										/* Local Short variable for admin password						*/ 
u16  Local_short_attemptsNumber=0;									/* Local Short variable to count attempt's Number of Password 	*/

while(Global_short_flag==0)											/* Loop to repeat Programme menu								*/
{/* open bracket of prgramme while loop	*/
	printf("\nEnter Your Choose : ");								/* Ask user To Enter Choose										*/
	printf("\n1-> Admin Mode");										/* Ask user To Enter 1 for admine mode							*/
	printf("\n2-> User mode");										/* Ask user To Enter 2 for user mode							*/
	printf("\n3-> Exite\n");										/* Ask user To Enter 3 to Close Programme						*/
	
	scanf("%d",&Global_Short_choose);								/* Take Choose from user										*/
	
	switch(Global_Short_choose)										/* Cheack User Choose											*/		
	{/* open bracket of Switch	*/
		case 1:														/* If user Choose Admin mode									*/
			system("cls");											/* Clear Consol Screen											*/
			for(u16 i=0;i<3;i++)									/* Loop To Repeat Enter password								*/
			{/* open bracket of for loop	*/
				
				printf("\nEnter Admin Password : ");				/* Ask Admin To Enter Password									*/
				scanf("%d",&Local_Short_admin_Password);			/* Take Password from Admin										*/
				
				if(Local_Short_admin_Password!=1234)				/* Cheack if Enter Password Not Valid							*/
					{/* open bracket of if Condition	*/			
						printf("Invalid Password Try Again...\n");	/* Print That Password is invalid								*/
						Local_short_attemptsNumber+=1;				/* increment attempt's Number of Password by 1					*/					
					}/* Close bracket of if Condition	*/
					
					else											/* if Entered Password Is Valid									*/				
					{/* open bracket of else	*/
						break;										/* Exit from For Loop											*/
					}/* Close bracket of else	*/
				
			}/* Close bracket of for loop	*/
				
			if(Local_short_attemptsNumber==3)						/* Cheak if admin Enter incorrect password Three Times			*/
				{/* open bracket of if	*/
						break;										/* Exite From Admin Case										*/
				}/* close bracket of if	*/
			else													/* If Admine Enters Correct Password							*/
			{/* open bracket of else	*/
				while(Global_short_flag==0)							/* Loop To repeat Admin Menu									*/					
				{/* open bracket of while Loop	Admin menu */
					printf("\nEnter Your Choose : ");				/* Ask Admin To Enter Choose									*/
					printf("\n1-> Add new patient record");			/* Ask Admin To Enter 1 for new record							*/
					printf("\n2-> Edit patient record");			/* Ask Admin To Enter 2 to Edit record							*/
					printf("\n3-> Reserve a slot with the doctor");	/* Ask Admin To Enter 3 to Reserve slot							*/
					printf("\n4-> Cancel reservation");				/* Ask Admin To Enter 4 to Cancel record						*/
					printf("\n5-> Display All Patient Records");	/* Ask Admin To Enter 5 to Print All records					*/
					printf("\n6-> Exit From Admin Mode\n");			/* Ask Admin To Enter 6 to Exite From Menu						*/
					scanf("%d",&Global_Short_choose);				/* Take Choose from user										*/
					scanf("%c",&Global_char_temp); 					/* temp statement to clear buffer			            		*/
					
					switch(Global_Short_choose)						/* Cheack User Choose											*/
					{/* open bracket of Switch	*/
						case 1:										/* If admin Choose add patient									*/
							system("cls");							/* Clear Consol Screen											*/
							Insert();								/* Calling Function insert() to add new patient					*/
							break;									/* End of Case 1												*/
						
						case 2:										/* If admin Choose Edit patient record							*/
							system("cls");							/* Clear Consol Screen											*/
							Edite_patient_Record();					/* Calling Function Edite_patient_Record()to Edit patient record*/
							break;									/* End of Case 2												*/
						
						case 3:										/* If admin Choose rserve slot									*/
							system("cls");							/* Clear Consol Screen											*/
							Reserve_slot();							/* Calling Function Reserve_slot() to rserve slot				*/
							break;									/* End of Case 3												*/
						
						case 4:										/* If admin Choose cancel Reservation							*/
							system("cls");							/* Clear Consol Screen											*/
							Cancel_reservation();					/* Calling Function Cancel_reservation() to cancel Reservation	*/
							break;									/* End of Case 4												*/
						
						case 5:										/* If admin Choose display All Records							*/
							system("cls");							/* Clear Consol Screen											*/
							Print_All_Records();					/* Calling Function Print_All_Records() to isplay All Records	*/
							break;									/* End of Case 5												*/
						
						case 6:										/* If admin Choose to Exit from menu							*/
							system("cls");							/* Clear Consol Screen											*/
							Global_short_flag=1;					/* assign flag to 1												*/
							break;									/* End of Case 6												*/
						
						default:									/* If admin Enter Invalid Choose 								*/
							system("cls");							/* Clear Consol Screen											*/
							printf("\nInvalid Choose....\n");		/*Print Invalid Choose											*/
							break;									/* End of default												*/
					}/* Close bracket of Switch	*/
				}/* Close bracket of while Loop	Admin menu*/
				
				Global_short_flag=0;								/* return flage value to zero									*/
				
			}/* Close bracket of else	*/
		break;														/* End of Case 1 in switch of programme menu					*/
		
		case 2:														/* If user Choose User mode										*/
			system("cls");											/* Clear Consol Screen											*/
			while(Global_short_flag==0)								/* Loop To repeat Admin Menu									*/					
				{/* open bracket of while Loop	user menu	*/
					printf("\nEnter Your Choose : ");				/* Ask user To Enter Choose										*/
					printf("\n1-> View patient record");			/* Ask user To Enter 1 to View patient record					*/
					printf("\n2-> View today’s reservations");		/* Ask user To Enter 2 to View today’s reservations				*/
					printf("\n3-> Exit From User Mode\n");			/* Ask user To Enter 3 to Exit From User Mode					*/
					scanf("%d",&Global_Short_choose);				/* Take Choose from user										*/
					switch(Global_Short_choose)						/* Cheack User Choose											*/
					{/* open bracket of Switch	*/
						case 1:										/* If user Choose View patient record							*/
							print_Patient_Record();					/* Calling Function print_Patient_Record()						*/
							break;									/* End of Case 1												*/
						
						case 2:										/* If user Choose View today’s reservations						*/
							today_reservations();					/* Calling Function today_reservations()						*/
							break;									/* End of Case 2												*/
						
						case 3:										/* If user Choose Exit											*/
							Global_short_flag=1;					/* assign flag to 1												*/
							break;									/* End of Case 3												*/
						default:									/* If user Enter Invalid Choose 								*/
							printf("\nInvalid Choose....\n");		/*Print Invalid Choose											*/
							break;									/* End of default												*/
					}/* open bracket of Switch	*/
			
				}/* Close bracket of while Loop user menu	*/
				Global_short_flag=0;								/* return flage value to zero									*/
		break;														/* End of Case 2 in switch of programme menu					*/
		
		case 3:														/* If user Choose Exit	From Programme							*/														
			system("cls");											/* Clear Consol Screen											*/
			Global_short_flag=1;									/* assign flag to 1												*/
		break;														/* End of Case 3 in switch of programme menu					*/
		
		default:													/* If user Enter Invalid Choose 								*/
			system("cls");											/* Clear Consol Screen											*/
			printf("Invalid Choose Try Again......\n");				/*Print Invalid Choose											*/
		break;														/* End of defult in switch of programme menu					*/
		
	 } /* Close bracket of switch That cheack Program meanu	*/
  }/* Close bracket of while Loop That Repeat Program meanu	*/
}/* Close bracket of Main Function	*/
