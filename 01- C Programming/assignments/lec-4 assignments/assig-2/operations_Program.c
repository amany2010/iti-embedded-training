#include<stdio.h>															// include input & output Library
#include"operations_interface.h"											// include Minimum & Maximum Function
/*
Function: menu to Print Avilable operations and get it's Id from user
Return : Operation Id
*/
int menu()
{
	int Local_int_opID;													// define Local integer variable to operation ID
/* Ask user to Enter Operation that he need From This menue */
	printf("1- Add\n");
	printf("2- Subtract\n");
	printf("3- Multiply\n");
	printf("4- Divide\n");
	printf("5- And\n");
	printf("6- Or\n");
	printf("7- xor\n");
	printf("8- Reminder\n");	
	printf("9- Not\n");
	printf("10- Increment\n");
	printf("11- Decrement\n");
	scanf("%d",&Local_int_opID);									// take operation Id from user
	/* using switch to Check opertaion id that entered from user*/
	switch(Local_int_opID)							
	{
		/*if operation id =  1 the function will return 1*/
		case 1:
			return 1;
			break;/* End of case 1*/
		/*if operation id =  2 the function will return 2*/
		case 2:
			return 2;
			break;/* End of case 2*/
		/*if operation id =  3 the function will return 3*/
		case 3:
			return 3;
			break;/* End of case 3*/
		/*if operation id =  4 the function will return 4*/
		case 4:
			return 4;
			break;/* End of case 4*/
		/*if operation id =  5 the function will return 5*/	
		case 5:
			return 5;
			break;/* End of case 5*/
		/*if operation id =  6 the function will return 6*/
		case 6:
			return 6;
			break;/* End of case 6*/
		/*if operation id =  7 the function will return 7*/
		case 7:
			return 7;
			break;/* End of case 7*/
		/*if operation id =  8 the function will return 8*/
		case 8:
			return 8;
			break;/* End of case 8*/
		/*if operation id =  9 the function will return 9*/
		case 9:
			return 9;
			break;/* End of case 9*/
		/*if operation id =  10 the function will return 10*/
		case 10:
			return 10;
			break;/* End of case 10*/
		/*if operation id =  11 the function will return 11*/
		case 11:
			return 11;
			break;/* End of case 11*/
		/*if operation id is Invalid the function will return -11*/
		default:
		return -1;
	}

}
/*
 Function:  add two numbers
 parameter : Two Float Numbers
 returned : Summation of two numbers
 */
float add (float copy_intN1,float copy_intN2)
{
	return  copy_intN1+ copy_intN2;
}
/*
 Function:  sub two numbers
 parameter : Two Float Numbers
 returned : Subtract of two numbers
 */
float sub (float copy_intN1,float copy_intN2)
{
	return  copy_intN1- copy_intN2;
}
/*
 Function:  multiplicate two numbers
 parameter : Two Float Numbers
 returned : multiplication of two numbers
 */
float multi (float copy_intN1,float copy_intN2)
{
	return  copy_intN1* copy_intN2;
}					
/*
 Function:  divied two numbers
 parameter : Two Float Numbers
 returned : divsion of two numbers
 */
float div (float copy_intN1,float copy_intN2)
{
	return copy_intN1/copy_intN2;
}					
/*
 Function:  And
 parameter : Two integer Numbers
 returned :  number1 And number2
 */
int AND (int copy_intN1,int copy_intN2)
{
	return copy_intN1& copy_intN2;
}					
/*
 Function:  OR
 parameter : Two integer Numbers
 returned :  number1 OR number2
 */
int OR (int copy_intN1,int copy_intN2)
{
	return copy_intN1| copy_intN2;
}					
/*
 Function:  XOR
 parameter : Two integer Numbers
 returned :  number1 XOR number2
 */
int XOR (int copy_intN1,int copy_intN2)		
{
	return copy_intN1^ copy_intN2;
}
/*
 Function:  remind
 parameter : Two integer Numbers
 returned :  result of number1 % number2
 */
 int remind (int copy_intN1,int copy_intN2)
{
	return copy_intN1% copy_intN2;
}
/*
 Function:  Not
 parameter : one integer Numbers
 returned :  Negation of number1 
 */
 int Not (int copy_intN)
{
	return ~copy_intN;
}
/*
 Function:  icerement(++)
 parameter : one integer Number
 returned :   number encermented by 1
 */
float increment (float copy_intN)
{
	return ++copy_intN;
}
/*
 Function:  decrement(--)
 parameter : one integer Number
 returned :   number decermented by 1
 */
float decrement (double copy_intN)
{
	return --copy_intN;
}
/*
 Function:  take integer value from user
 parameter : one integer pointer 
 */
 void Take_Values_int(int *Copy_int_value)
{
	printf("Enter  Nummber :");
	scanf("%d",*&Copy_int_value);
}	
/*
 Function:  take float value from user
 parameter : one float pointer 
 */		
void Take_Values_Float(float *Copy_float_value)
{
	printf("Enter  Nummber :");
		scanf("%f",*&Copy_float_value);
}							