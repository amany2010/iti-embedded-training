#ifndef _MINI_MAX_SORT_INTERFACE_H
#define _MINI_MAX_SORT_INTERFACE_H
/*define two global variables to count passed and failed student*/
int Global_int_Failed,Global_int_passed;							
/*
Function: Bubble_sort         		                         			  
parameters: Array and it's length                               		              
Returns: returns a sorted array                                           
*/
void Bubble_sort (int Copy_int_length,float Copy_float_arr[]);
/*
Function: swap                		                         			  
Parameters: int *first, int *second           			              
Returns:it returns index of the number if found or -1 if it is not found    
*/
void swap(float *Copy_float_first, float *Copy_float_second);
/*
Function: Minimum of array element        		                         			  
parameters: Array and it's length                               		              
Returns: returns Mimum  Values From array                                           
*/
float Mini_ARR(int Copy_int_length,float Copy_Float_arr[]);
/*
Function: maximum of array element        		                         			  
parameters: Array and it's length                               		              
Returns: returns Maximum Value From array                                           
*/
float Max_ARR(int Copy_int_length,float Copy_Float_arr[]);
/*
Function : coun passed & failed student
parameter : one float parameter
return : No return values
*/
void Count(float Copy_float_val);
#endif