#include<stdio.h>															// input & Output Library
#include"Mini_Max_Sort_interface.h"											// header of mini & Max & Sort Functions
void main(void)																// main Function
{
	float Local_Float_Class1[10],Local_Float_Class2[10],Local_Float_Class3[10];//Local_Float_mini[3],Local_Float_max[3],
	float Local_int_Sum;
	for(int i=0;i<10;i++)													// Loop to set Students data
	{
		/* this three Equations are randomly tp set students grade*/
		Local_Float_Class1[i]=i*10+5;
		Local_Float_Class2[i]=(2+i)*8;
		Local_Float_Class1[i]=(i+6)*(50/8);
		Count(Local_Float_Class1[i]);																// calling count function to count Passed & failed students of class 1
		Count(Local_Float_Class2[i]);																// calling count function to count Passed & failed students of class 4
		Count(Local_Float_Class3[i]);																// calling count function to count Passed & failed students of class 3
		Local_int_Sum=Local_Float_Class1[i],Local_Float_Class2[i],Local_Float_Class3[i];			// Calculate The Summation of all grades to calculate grades average
	}
	Bubble_sort(10,Local_Float_Class1);																// callin function buble sort to sor studeent grades of class 1
	Bubble_sort(10,Local_Float_Class2);																// callin function buble sort to sor studeent grades of class 2
	Bubble_sort(10,Local_Float_Class3);																// callin function buble sort to sor studeent grades of class 3
	float Local_Float_mini[3]={Local_Float_Class1[0],Local_Float_Class2[0],Local_Float_Class2[0]}; 	//Stor minimum grade for three class in New Mini arreay
	float Local_Float_max[3]={Local_Float_Class1[9],Local_Float_Class2[9],Local_Float_Class2[9]};	//Stor minimum grade for three class in New Max arreay
	
	
	printf("Number of Passed Studens : %d\n",Global_int_passed);									// print Number of passed students	
	printf("Number of Failed Studens : %d\n",Global_int_Failed);									// print  Number of Failed students	
	printf("Lower grade : %.2f\n",Mini_ARR(3,Local_Float_mini));									//Print minimum grade between three class by calling Mini_function(Minum Grades of every class)
	printf("Higher grade : %.2f\n",Max_ARR(3,Local_Float_max));										//Print maximum grade between three class by calling Maxi_function(Maxi Grades of every class)
	printf("Grade Average  : %.2f\n",Local_int_Sum/300);											// Print Average grade by divided Total grades on 300

	
}