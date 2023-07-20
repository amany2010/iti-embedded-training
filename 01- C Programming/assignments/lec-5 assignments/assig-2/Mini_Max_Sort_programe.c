#include<stdio.h>
#include"?D:\Education\iti\lec-5 assignments\assig-2\Mini_Max_Sort_interface.h"
/* Immpelmentation of Array sorting Function*/
void Bubble_sort (int Copy_int_length,float Copy_float_arr[])
{
	 for (int i=0; i<Copy_int_length-1; i++)
    {
        for (int c = 0 ; c < Copy_int_length-1-i ; c++) 			// loop to found the minimum index
        {
            if (Copy_float_arr[c+1] <Copy_float_arr[c]) 				// check if c+1 element is less than the element at c
            {
                swap(&Copy_float_arr[c],&Copy_float_arr[c+1]); 			//swap the two numbers
            }
        }
    }
}
/* Immpelmentation of Swap two elements Function*/
void swap(float *Copy_float_first, float *Copy_float_second)
{
	*Copy_float_first=*Copy_float_first+*Copy_float_second;				// set first element equal summatiion of tw elements
	*Copy_float_second=*Copy_float_first-*Copy_float_second;				// set seconde element equal abstract of first element and second element(first value for first element)
	*Copy_float_first=*Copy_float_first-*Copy_float_second;				// set first element equal abstract of first element and second element(first value for second element)
}
/* Immpelmentation of Minimum two elements Function*/
float Mini_ARR(int Copy_int_length,float Copy_Float_arr[])
{
	if(Copy_int_length==1)											//check if Array just have one element
	{
		return Copy_Float_arr[0];												// return this element as minimum value
	}
	else if(Copy_int_length==2)										//check if Array just have two element
	{
		if(Copy_Float_arr[0]<Copy_Float_arr[1])					// check if first element smaller  than second element 
		{
			return Copy_Float_arr[0];								// return first element  as a minimum value
		}
		else														// second element is a smaller
		{
			return Copy_Float_arr[1];								//  return second element  as a minimum value
		}
	}
	else															// Array have more than 2 elements
	{
		Bubble_sort( Copy_int_length, Copy_Float_arr);			// calling bubble sorting function to sort array
		return Copy_Float_arr[0];									// return first element as a minimum
		
	}
}
/* Immpelmentation of Maxiimum two elements Function*/
float Max_ARR(int Copy_int_length,float Copy_Float_arr[])
{
	if(Copy_int_length==1)											//check if Array just have one element
	{
		return Copy_Float_arr[0];												// return this element as maximum value
	}
	else if(Copy_int_length==2)										//check if Array just have two element
	{
		if(Copy_Float_arr[0]>Copy_Float_arr[1])					// check if first element more   than second element 
		{
			return Copy_Float_arr[0];								// return first element  as a maximum value
		}
		else														// second element is a moreller
		{
			return Copy_Float_arr[1];								//  return second element  as a maximum value
		}
	}
	else															// Array have more than 2 elements
	{
		Bubble_sort (Copy_int_length, Copy_Float_arr);   // calling bubble sorting function to sort array
		return Copy_Float_arr[Copy_int_length-1];					// return last element as a maximum
		
	}
}
/* Immpelmentation of count Function*/
void Count(float Copy_float_val)
{
	if(Copy_float_val>=50)		//check if student passed
	{
		Global_int_passed++;	// incerement passed students by one
	}
	else						// student faild
	{
		Global_int_Failed++;	// incerement faild students by one
	}
}