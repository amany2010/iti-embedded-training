#include<stdio.h>															// include input & output Library
#include"max_Mini_interface.h"												// include Minimum & Maximum Function
void main(void)																// Main Function
{
	int Local_int_N1,Local_int_N2,Local_int_N3,Local_int_N4;
	printf("Enter Number 1 :");												// ask user to Enter number 1 value
	scanf("%d",&Local_int_N1);												// get value from user
	printf("Enter Number 2 :");												// ask user to Enter number 2 value
	scanf("%d",&Local_int_N2);												// get value from user
	printf("Enter Number 3 :");												// ask user to Enter number 3 value
	scanf("%d",&Local_int_N3);												// get value from user
	printf("Enter Number 4 :");												// ask user to Enter number 4 value
	scanf("%d",&Local_int_N4);												// get value from user
	printf("Maximum Value Is %d\n",max(Local_int_N1,Local_int_N2,Local_int_N3,Local_int_N4));	// calling maxmum function and print vlaue that it returned
	printf("Minimum Value Is %d\n",min(Local_int_N1,Local_int_N2,Local_int_N3,Local_int_N4));	// calling maxmum function and print vlaue that it returned
}