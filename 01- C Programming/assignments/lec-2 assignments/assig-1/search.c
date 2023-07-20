#include<stdio.h>
void main(void){
	int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;			// define 10 variables
	int snum;									//define variable to search
	printf("Enter Number 1:");					// Ask user to Enter Number 1
	scanf("%d",&n1);								//Get Number 1 from user
	printf("Enter Number 2:");					// Ask user to Enter Number 2
	scanf("%d",&n2);								//Get Number 2 from user
	printf("Enter Number 3:");					// Ask user to Enter Number 3
	scanf("%d",&n3);								//Get Number 3 from user
	printf("Enter Number 4:");					// Ask user to Enter Number 4
	scanf("%d",&n4);								//Get Number 4 from user
	printf("Enter Number 5:");					// Ask user to Enter Number 5
	scanf("%d",&n5);								//Get Number 5 from user
	printf("Enter Number 6:");					// Ask user to Enter Number 6
	scanf("%d",&n6);								//Get Number 6 from user
	printf("Enter Number 7:");					// Ask user to Enter Number 7
	scanf("%d",&n7);								//Get Number 7 from user
	printf("Enter Number 8:");					// Ask user to Enter Number 8
	scanf("%d",&n8);								//Get Number 8 from user
	printf("Enter Number 9:");					// Ask user to Enter Number 9
	scanf("%d",&n9);								//Get Number 9 from user
	printf("Enter Number 10:");					// Ask user to Enter Number 10
	scanf("%d",&n10);							//Get Number 10 from user
	printf("Enter The Value To Search :");		// Ask user to Enter to search on ito
	scanf("%d",&snum);							//Get value from user
	if(snum==n1) 								//Check if search value equal to number 1
	{
		printf("Value Is Exist At Element Number 1\n");		// print The position of element
	}
	else if(snum==n2) 										//Check if search value equal to number 2
	{
		printf("Value Is Exist At Element Number 2\n");		// print The position of element
	}
	else if(snum==n3) 										//Check if search value equal to number 3
	{
		printf("Value Is Exist At Element Number 3\n");		// print The position of element
	}
	else if(snum==n4) 										//Check if search value equal to number 4
	{
		printf("Value Is Exist At Element Number 4\n");		// print The position of element
	}
	else if(snum==n5) 										//Check if search value equal to number 5
	{
		printf("Value Is Exist At Element Number 5\n");		// print The position of element
	}
	else if(snum==n6) 										//Check if search value equal to number 6
	{
		printf("Value Is Exist At Element Number 6\n");		// print The position of element
	}
	else if(snum==n7) 										//Check if search value equal to number 7
	{
		printf("Value Is Exist At Element Number 7\n");		// print The position of element
	}
	else if(snum==n8) 										//Check if search value equal to number 8
	{
		printf("Value Is Exist At Element Number 8\n");		// print The position of element
	}
	else if(snum==n9) 										//Check if search value equal to number 9
	{
		printf("Value Is Exist At Element Number 9\n");		// print The position of element
	}else if(snum==n10) 									//Check if search value equal to number 10
	{
		printf("Value Is Exist At Element Number 10\n");	// print The position of element
	}
	else													// if number not found in 10 elements
	{								
		printf("Number No Exist\n");						// print number not exeist
	}
}