#include<stdio.h>																	// input & Output Library
#include"Buble_Sort_interface.h"													// header of Buble Sort Functions
void main(void)																		// main Function
{
	int Local_float_arr[3]={0};													// define Local Float array
	int Local_int_arrSize=sizeof(Local_float_arr)/sizeof(Local_float_arr[0]);		// calculate length of array
	for(int i=0;i<Local_int_arrSize;i++)
	{
		printf("Enter Element %d : ",i+1);
		scanf("%f",&Local_float_arr[i]);
	}
	Buble_sort(Local_float_arr);
	for(int i=0;i<Local_int_arrSize;i++)
	{
		printf(" Element %d is %f \n",i+1,Local_float_arr[i]);
	}	
	
}