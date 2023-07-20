#include<stdio.h>
void main(void){
	int a,b; 							//define two integer variables
	printf("Please Enter Number 1 :");	//ask user to Enter number 1 
	scanf("%d",&a); 					//get number 1 from user
	printf("Please Enter Number 2 :");	//ask user to Enter number 1 
	scanf("%d",&b);						//get number 1 from user
	printf("a + b = %d",a+b);			// Print summation of(number 1 & number 2)
	printf("\na - b = %d",a-b);			// Print subtraction of(number 1 & number 2)
	printf("\na & b = %d",a&b);			// Print anding of(number 1 & number 2)
	printf("\na | b = %d",a|b);			// Print oring of(number 1 & number 2)
	printf("\na ^ b = %d",a^b);			// Print Xoring of(number 1 & number 2)
	
}