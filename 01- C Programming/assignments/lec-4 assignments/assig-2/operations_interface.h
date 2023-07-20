#ifndef _OPERATIONS_INTERFACE_H
#define _OPERATIONS_INTERFACE_H

int menu();															// Function to ask user about operation and get operand from user
float add (float copy_intN1,float copy_intN2);						// Function to add two numbers
float sub (float copy_intN1,float copy_intN2);						// Function to substract two numbers
float multi (float copy_intN1,float copy_intN2);					// Function to Multiplication two numbers
float div (float copy_intN1,float copy_intN2);						// Function to divsion two numbers
int AND (int copy_intN1,int copy_intN2);							// Function to calculate And for two numbers
int OR (int copy_intN1,int copy_intN2);								// Function to calculate OR for two numbers
int XOR (int copy_intN1,int copy_intN2);							// Function to calculate XOR for two numbers
int remind (int copy_intN1,int copy_intN2);							// Function to calculate Reminder of two numbers
int Not (int copy_intN);											// Function to calculate Not for  number
float increment (float copy_intN);									// Function to increment number by 1
float decrement (double copy_intN);									// Function to decrement number by 1
void Take_Values_int(int *Copy_int_value);							// function to take Integer Vlue From user
void Take_Values_Float(float *Copy_float_value);					// function to take Float Vlue From use
#endif