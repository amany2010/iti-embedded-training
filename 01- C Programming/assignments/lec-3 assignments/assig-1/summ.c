#include<stdio.h>
void main(void){
	int n1,n2;												// define 2 variables
	while(1)												// using while to make infinity loop
	{
	printf("Enter Number 1:");								// Ask user to Enter Number 1
	scanf("%d",&n1);										//Get Number 1 from user
	printf("Enter Number 2:");								// Ask user to Enter Number 2
	scanf("%d",&n2);										//Get Number 1 from user
	printf("The Result Is %d\n",n1+n2);						// print summation  of two numbers
	}
}