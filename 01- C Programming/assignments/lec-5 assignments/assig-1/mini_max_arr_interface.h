#ifndef _MINI_MAX_ARR_INTERFACE_H
#define _MINI_MAX_ARR_INTERFACE_H
/*
Function: Bubble_sort         		                         			  
parameters: Array and it's length                               		              
Returns: returns a sorted array                                           
*/
void Bubble_sort (int Copy_int_length,int Copy_int_arr[]);
/*
Function: swap                		                         			  
Parameters: int *first, int *second           			              
Returns:it returns index of the number if found or -1 if it is not found    
*/
void swap(int *Copy_int_first, int *Copy_int_second);
/*
Function: Mini_Max_arr         		                         			  
parameters: Array and it's length                               		              
Returns: returns Mimum & Maximum Values From array                                           
*/
void Mini_Max_arr (int Copy_int_length,int Copy_int_arr[]);

#endif