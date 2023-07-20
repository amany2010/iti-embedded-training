#include<stdio.h>							// input & Output Library
#include"mini_max_arr_interface.h"			// header of miniMax Function
void main (void)							// calling main Function
{
	int Local_int_arr[10];					// Local Integer variable array of size 10
	for(int i=0;i<10;i++)					// loop to take array elements from user
	{
		printf("Enter Number %d :",i+1);	// ask user to Enter element i of array
		scanf("%d",&Local_int_arr[i]);		// take element i of array frome user
	}
	Mini_Max_arr(10,Local_int_arr);			// calling functio Mini_Max_arr to print the minimum & Maximum Values of array
}