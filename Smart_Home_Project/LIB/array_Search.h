#ifndef LIB__ARRAY_SEARCH_H_
#define LIB_ARRAY_SEARCH_H_
#define array_Length		10
#include "../LIB/STD_TYPES.h"
#include<string.h>
/*function to sequentially search on array of string		*/
int search( u8 *Copy_u8_array[], u8 *Copy_u8_value)
{//open bracket of function
	u16 Local_u8_x=-1;//variable to be returned to caller
    for(u16 i=0;i<array_Length;i++)//loop for searching
    {//open bracket of loop
    	if(strcmp(Copy_u8_array[i],Copy_u8_value)==0)//check if two strings are equal
    	{//open bracket of if condition
    		Local_u8_x=i;//if number is found, set i index to return value
    		break; // exit from loop
    	}//close bracket of if condition
    }//close bracket of loop
    return Local_u8_x;//return the result
}
#endif
