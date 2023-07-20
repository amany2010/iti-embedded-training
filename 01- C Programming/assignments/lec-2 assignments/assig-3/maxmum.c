#include<stdio.h>
void main(void){
	int n1,n2,n3;										// define 3 variables
	printf("Enter Number 1:");								// Ask user to Enter Number 1
	scanf("%d",&n1);										//Get Number 1 from user
	printf("Enter Number 2:");								// Ask user to Enter Number 2
	scanf("%d",&n2);										//Get Number 2 from user
	printf("Enter Number 3:");								// Ask user to Enter Number 3
	scanf("%d",&n3);										//Get Number 3 from user
	if(n1==n2&&n2==n3)										//check if three numbers are equal
	{
		printf("3 Numbers Are Equal\n");						// print 3 numbers are equal
	}
	else if(n1>=n2&& n1>=n3) 								//Check if Number 1 are mor than number2&number 3
	{
		printf("Maximum Number is %d\n",n1);									// print Number 1
	}
	else if(n2>=n1&& n2>=n3) 								//Check if Number 2 are mor than number1&number 3
	{
		printf("Maximum Number is %d\n",n2);									// print Number 2
	}
	else if(n3>=n1&& n3>=n2) 								//Check if Number 3 are mor than number1&number 2
	{
		printf("Maximum Number is %d\n",n3);				// print Number 3
	}
}