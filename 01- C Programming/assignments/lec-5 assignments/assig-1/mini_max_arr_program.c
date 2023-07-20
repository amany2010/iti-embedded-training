#include<stdio.h>
#include"mini_max_arr_interface.h"
/* Immpelmentation of Array sorting Function*/
void Bubble_sort (int Copy_int_length,int Copy_int_arr[])
{
	 for (int i=0; i<Copy_int_length-1; i++)
    {
        for (int c = 0 ; c < Copy_int_length-1-i ; c++) 			// loop to found the minimum index
        {
            if (Copy_int_arr[c+1] <Copy_int_arr[c]) 				// check if c+1 element is less than the element at c
            {
                swap(&Copy_int_arr[c],&Copy_int_arr[c+1]); 			//swap the two numbers
            }
        }
    }
}
/* Immpelmentation of Swap two elements Function*/
void swap(int *Copy_int_first, int *Copy_int_second)
{
	*Copy_int_first=*Copy_int_first+*Copy_int_second;				// set first element equal summatiion of tw elements
	*Copy_int_second=*Copy_int_first-*Copy_int_second;				// set seconde element equal abstract of first element and second element(first value for first element)
	*Copy_int_first=*Copy_int_first-*Copy_int_second;				// set first element equal abstract of first element and second element(first value for second element)

}
/* Immpelmentation of Mini and Maximum of array function*/
void Mini_Max_arr (int Copy_int_length,int Copy_int_arr[])
{	
	Bubble_sort (Copy_int_length,Copy_int_arr);				// call Bubble_sort function to sorting array
	printf("Maximum value is : %d\n",Copy_int_arr[Copy_int_length-1]);	// print maximum value equal last element in sorted array
	printf("Minimum value is : %d\n",Copy_int_arr[0]);					// print minimum value equal first element in sorted array
}
