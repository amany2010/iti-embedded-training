#include<stdio.h>															// include input & output Library
#include"operations_interface.h"												// include Minimum & Maximum Function
void main(void)																// calling main function
{	
	int Local_int_number1,Local_int_number2;								// define two local integer variables to Logical operations
	float Local_Float_number1,Local_Float_number2;							// define two local float variables to Arithemtic 

/*Warning ForUser*/
printf("If You Want To Close Programme Please Close Window....\n");	
	
	/* Loop To make user Calculate More Than One  */
while(1)
{
	/* Calling Menu Function ad check value that return from it */
 switch(menu())																
 {
	/* if menu value 1*/
	 case 1:	
		/*Caling Take_Values_Float function  to take two float Numbers from user*/
		Take_Values_Float(&Local_Float_number1);
		Take_Values_Float(&Local_Float_number2);
		/* calling printf function to print operation and summationvalue that returned from add function*/
		printf("%.2f + %.2f = %.2f\n",Local_Float_number1,Local_Float_number2,add(Local_Float_number1,Local_Float_number2));
	 break;		/* end of case 1 */
	 /* if menu value 2*/
	case 2:		
		/*Caling Take_Values_Float function  to take two float Numbers from user*/
		Take_Values_Float(&Local_Float_number1);
		Take_Values_Float(&Local_Float_number2);
		/* calling printf function to print operation and subtract value that returned from sub function*/
		printf("%.2f - %.2f = %.2f\n",Local_Float_number1,Local_Float_number2,sub(Local_Float_number1,Local_Float_number2));
		break;		/* end of case 2 */
	/* if menu value 3*/	
	case 3:		
		/*Caling Take_Values_Float function  to take two float Numbers from user*/
		Take_Values_Float(&Local_Float_number1);
		Take_Values_Float(&Local_Float_number2);
		/* calling printf function to print operation and multiplaction deviation value that returned from multi function*/
		printf("%.2f * %.2f = %.2f\n",Local_Float_number1,Local_Float_number2,multi(Local_Float_number1,Local_Float_number2));
		break;	/* end of case 3 */
	/* if menu value 4*/
	case 4:
		/*Caling Take_Values_Float function  to take two float Numbers from user*/
		Take_Values_Float(&Local_Float_number1);
		Take_Values_Float(&Local_Float_number2);
		/* calling printf function to print operation and deviation value that returned from div function*/
		printf("%.2f / %.2f = %.2f\n",Local_Float_number1,Local_Float_number2,div(Local_Float_number1,Local_Float_number2));
		break;	/* end of case 4 */
	/* if menu value 5*/
	case 5:
		/*Caling Take_Values_Float function  to take two integer Numbers from user*/
		Take_Values_int(&Local_int_number1);
		Take_Values_int(&Local_int_number2);
		/* calling printf function to print operation and Anding  value that returned from AND function*/
		printf("%d & %d = %d\n",Local_int_number1,Local_int_number2,AND(Local_int_number1,Local_int_number2));
		break;	/* end of case 5 */
	/* if menu value 6*/
	case 6:
		/*Caling Take_Values_Float function  to take two integer Numbers from user*/
		Take_Values_int(&Local_int_number1);
		Take_Values_int(&Local_int_number2);
		/* calling printf function to print operation and  Oring value that returned from OR function*/
		printf("%d & %d = %d\n",Local_int_number1,Local_int_number2,OR(Local_int_number1,Local_int_number2));
		break;	/* end of case 6 */
	/* if menu value 7*/
	case 7:
		/*Caling Take_Values_Float function  to take two integer Numbers from user*/
		Take_Values_int(&Local_int_number1);
		Take_Values_int(&Local_int_number2);
		/* calling printf function to print operation and Xoring value that returned from XOR function*/
		printf("%d ^ %d = %d\n",Local_int_number1,Local_int_number2,XOR(Local_int_number1,Local_int_number2));
		break;	/* end of case 7 */
	/* if menu value 8*/
	case 8:
		/*Caling Take_Values_Float function  to take two integer Numbers from user*/
		Take_Values_int(&Local_int_number1);
		Take_Values_int(&Local_int_number2);
		/* calling printf function to print operation and reminder value that returned from remind function*/
		printf("%d & %d = %d\n",Local_int_number1,Local_int_number2,remind(Local_int_number1,Local_int_number2));
		break;	/* end of case 8 */
	/* if menu value 9*/
	case 9:
		/*Caling Take_Values_Float function  to take one integer Numbers from user*/
		Take_Values_int(&Local_int_number1);
		/* calling printf function to print operation and negation value that returned from NOT function*/
		printf("~ %d = %d\n",Local_int_number1,Not(Local_int_number1));
		break;	/* end of case 9 */
	/* if menu value 10*/
	case 10:
		/*Caling Take_Values_Float function  to take one float Numbers from user*/
		Take_Values_Float(&Local_Float_number1);
		/* calling printf function to print operation and incerment value that returned from increment function*/
		printf("++ %.2f = %.2f\n",Local_Float_number1,increment(Local_Float_number1));
		break;	/* end of case 10 */
	/* if menu value 11*/
	case 11:
		/*Caling Take_Values_Float function  to take one float Numbers from user*/
		Take_Values_Float(&Local_Float_number1);
		/* calling printf function to print operation and decerment value that returned from decrement function*/
		printf("-- %.2f = %.2f\n",Local_Float_number1,decrement(Local_Float_number1));
		break;	/* end of case 11 */
	/* if user enter wrong operation  the menu function return -1 */
	default:		
		printf("Operation Not Found...\n");		/* print that operation Not Found*/
	}
}
	
}
