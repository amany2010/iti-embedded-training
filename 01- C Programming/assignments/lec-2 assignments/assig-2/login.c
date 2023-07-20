#include<stdio.h>
void main(void){
	int id,pass;			//define ID &Password variables from type integers
	/*
		initial informations:
		id=2020
		password=1468
		user Name = Amany
	*/
	printf("Enter ID:");								 			 // Ask user to enter his Id
	scanf("%d",&id);												 // get id value from user
	if(id==2020)									  				  // check if id is correct
	{
		printf("Enter Password:"); 					  				// Ask user to enter his Password
		scanf("%d",&pass);											 // get password from user
		if(pass==1468)												//check if the Password is Correct
		{
			printf("The user Name is Amany\n");					   // print user name
		}
		else									  					// if password is incorrect
		{
			printf("Incorrect Password\n");		 					// print that password not correct
		}
	}
	else															//if id not valid
	{
		printf("Incorrect ID\n");			   						// print that ID is not correct
	}
}