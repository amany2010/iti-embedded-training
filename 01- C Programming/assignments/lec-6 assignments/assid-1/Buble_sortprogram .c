#include<stdio.h>													// input & Output Library
#include"Buble_Sort_interface.h"									// header of Buble Sort Functions
/* implemntation of Buble_sort Function*/
void Buble_sort(int Copy_float_arr[])
{	int Local_int_Lenght=sizeof(Copy_float_arr)/sizeof(Copy_float_arr[0]);
	for (int i=0; i<Local_int_Lenght; i++)
    {
        for (int j = 0 ; j < Local_int_Lenght-1-i ; j++) 						// loop to found the minimum index
        {
            if (Copy_float_arr[j+1] < Copy_float_arr[j]) 			// check if c+1 element is less than the element at j
            {
				//swap the two numbers
                Copy_float_arr[j]+=Copy_float_arr[j+1]; 	
				Copy_float_arr[j+1]=Copy_float_arr[j]-Copy_float_arr[j+1];
				Copy_float_arr[j]-=Copy_float_arr[j+1]; 	
            }
        }
    }
}
