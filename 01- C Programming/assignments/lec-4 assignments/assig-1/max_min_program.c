#include<stdio.h>															// include input & output Library
#include"max_Mini_interface.h"												// include Minimum & Maximum Function
//this function will get 4 Numbers and return th maximum Value of them
int max(int copy_intN1,int copy_intN2,int copy_intN3,int copy_intN4)		// Scop of maximum function
{
	
	if(copy_intN1>=copy_intN2&&copy_intN1>=copy_intN3&&copy_intN1>=copy_intN4)	//check if the Number 1 is maximum
	{
		return copy_intN1;													// return Number 1
	}
	else if(copy_intN2>=copy_intN1&&copy_intN2>=copy_intN3&&copy_intN2>=copy_intN4)//check if the Number 2 is maximum
	{
		return 	copy_intN2;													// return Number 2
	}
	else if(copy_intN3>=copy_intN1&&copy_intN3>=copy_intN2&&copy_intN3>=copy_intN4)//check if the Number 3 is maximum
	{
		return 	copy_intN3;													// return Number 3
	}
	else																	// the muximum number will be number4
	{
		return 	copy_intN4;													// return Number 4
	}
}


//this function will get 4 Numbers and return th minimum Value of them
int min(int copy_intN1,int copy_intN2,int copy_intN3,int copy_intN4)		// Scop of minimum function
{
	if(copy_intN1<=copy_intN2&&copy_intN1<=copy_intN3&&copy_intN1<=copy_intN4)	//check if the Number 1 is minimum
	{
		return copy_intN1;													// return Number 1
	}
	else if(copy_intN2<=copy_intN1&&copy_intN2<=copy_intN3&&copy_intN2<=copy_intN4)//check if the Number 2 is minimum
	{
		return 	copy_intN2;													// return Number 2
	}
	else if(copy_intN3<=copy_intN1&&copy_intN3<=copy_intN2&&copy_intN3<=copy_intN4)//check if the Number 3 is minimum
	{
		return 	copy_intN3;													// return Number 3
	}
	else																	// the minimum number will be number4
	{
		return 	copy_intN4;													// return Number 4
	}
}