#include<stdio.h>																									/* include input and Output Library 		*/
#include"LinkedList_Interface.h"																					/* include LinkedList File Header 			*/
#include<string.h>																									/* include String Library						*/
#include<stdlib.h>																									/* include std libraries						*/
s8 const *Global_Char_slots[5]={"2:00pm","2:30pm","3:00pm","4:00pm","4:30pm"};										/* Global Constant charchters array of poniters to store doctor Slots*/
u128 Global_reserved_Slot_ID[5]={0};																				/* Global Array Of integers to store patient reserved slot Id		*/
 //slotID+1="3:00";
 node head;																											/* object from Struct       		 	*/
u32 ListLength =0;																									/* Length of LinkedList					*/

/*-------------------------------------------------------------------------------------------------*/
/*Insert Nod Function Implemantation*/
void Insert()
{// open bracket of Function  		
	node *new = (node*) malloc(sizeof(node));																		/*Allocate new node in memory				*/
	printf("\n\n--------------- Patient Data ---------------\n\n");
	printf("Enter Name: ");	        				 																/* Ask user to Enter Name 	  				*/
	scanf("%[^\n]",new->Local_String_Name);																			/* Get Name From User		  				*/
	scanf("%c",&Global_char_temp); 																					/* temp statement to clear buffer           */

	printf("\nEnter Age: ");				     																	/* Ask user to Enter Age 	  				*/
	scanf("%d",&new->Local_Short_Age);																				/* Get Age From User		  				*/
	scanf("%c",&Global_char_temp); 																					/* temp statement to clear buffer           */

	printf("\nEnter Gender: ");																						/* Ask user to Enter Name 	  				*/
	scanf("%[^\n]",new->Local_String_Gender);																		/* Get Gender From User		  				*/
	scanf("%c",&Global_char_temp); 																					/* temp statement to clear buffer           */
	
	printf("\nEnter ID: ");				     																		/* Ask user to Enter ID 	  				*/
	scanf("%llu",&new->Local_LongLong_ID);																			/* Get ID From User			  				*/
	scanf("%c",&Global_char_temp); 																					/* temp statement to clear buffer           */
	
	if(Search_ID(new->Local_LongLong_ID)!=NULL)																		/* Cheak if patient already recordes		*/
	{// open bracket of if condition
			printf("\nID Already Exist...\n");
			return;																									/* go out from Function						*/
	}// Close bracket of if condition
	
	printf("\n\n------- Patient Recorded Succecfully -------\n\n");
	
	if (ListLength==0)																								/* Cheack if List Is Empty	 				*/
	{// open bracket of if condition
		
		/* 		copy new data on first node(head)	        */	
		strcpy(head.Local_String_Name,new->Local_String_Name);
		
		head.Local_Short_Age=new->Local_Short_Age;
		
		strcpy(head.Local_String_Gender,new->Local_String_Gender);
		
		head.Local_LongLong_ID=new->Local_LongLong_ID;
		
		head.Next=NULL;																								/* make head refer to NULL			 		*/
	
	}// Close bracket of if condition
	
	else																											/* if list have nodes				 		*/
	{// open bracket of else
		
		node *cur=&head;																							/* pointer to node equal first node	 		*/
		
		while(cur->Next!=NULL)																						/* Loop to reach to last node				*/
		{// open bracket of While
			cur=cur->Next;																							/* Move current to Next node			 	*/
		}// Close bracket of While
		
		new->Next=NULL;																								/*	  Make new node refer to NULL	      	*/
		cur->Next=new;																								/* Make Last node in list refer to new node	*/	
	
	}// Close bracket of else
	ListLength++;																									/* increment length of list by one   		*/

}// close bracket of Function

/*-------------------------------------------------------------------------------------------------*/
/*Print All Records in List Function Implemantation*/
void Print_All_Records()
{//open bracket of function
	if (ListLength == 0)							  																/* 			cheack if list is Empty			*/
	{//open bracket of if condition
		printf("\nNo recordes...........");			
	}//close bracket of if condition
	
	else
	{//open bracket of else
		node *cur = &head;
		u32 counter =1;
		while(cur!=NULL)
		{//open bracket of while
			printf("\n\n------------------------------------\n");
			printf("           Patient %d             ",counter);
			printf("\n------------------------------------");
			printf("\nPatient Name  : %s",cur->Local_String_Name);													/* 				Print patient Name				*/
			printf("\nPatient  Age  : %d",cur->Local_Short_Age);													/* 				Print patient Age				*/
			printf("\nPatient Gendr : %s",cur->Local_String_Gender);												/* 				Print patient Gender			*/
			printf("\nPatient ID    : %llu",cur->Local_LongLong_ID);												/* 				Print patient ID				*/
			printf("\n--------------------------------\n\n");
			counter++;
			cur=cur->Next;
		}//close bracket of while
	}//close bracket of else
}//close bracket of function

/*-------------------------------------------------------------------------------------------------*/
/*search ID Function Implemantation*/
node *Search_ID(u128 Copy_LongLong_ID)
{//Open bracket of function
	node *cur=&head;																								/* pointer of node refer to head			 */
	while(cur!=NULL)																								/* While to loop on list           			 */
	{//Open bracket of while
		if(cur->Local_LongLong_ID==Copy_LongLong_ID)																/* Cheak if the enter ID equal to patient ID */
		{//Open bracket of if
			return cur;																								/* return patient data						 */
			break;																									/* Get out of the loop						 */	
		}//close bracket of if
		cur=cur->Next;																								/* move node by one							 */
	}//close bracket of while
	if(cur==NULL)																									/* cheack if list empty						 */	
	{//Open bracket of if
		return NULL;																								/*	return empty List						 */
	}//close bracket of if
}//close bracket of function

/*-------------------------------------------------------------------------------------------------*/
/* print_Patient_Record Function Implemantion */
void print_Patient_Record()
{//open bracket of function
	node *temp=(node*)malloc(sizeof(node));																			/* Pointer of node														*/
	printf("\nEnter ID :");																							/* Ask User To Enter His ID					*/
	scanf("%llu",&Global_LongLong_ID);																				/* Take ID From User						*/
	temp=Search_ID(Global_LongLong_ID);																				/* assign temp node to node that return from calling function search_ID	*/
	if(temp==NULL)																									/* Cheack if Function return NULL										*/
	{//open bracket of if
		printf("\nID NOt Found......\n");																			/* Print That ID Not Found												*/
	}//close bracket of if
	else																											/* ID Is Found															*/
	{//open bracket of else
		printf("\n\n------------------------------------\n");
		printf("\nPatient Name  : %s",temp->Local_String_Name);														/* Print Patient Name													*/
		printf("\nPatient  Age  : %d",temp->Local_Short_Age);														/* Print Patient Age													*/
		printf("\nPatient Gendr : %s",temp->Local_String_Gender);													/* Print Patient Gender													*/
		printf("\nPatient ID    : %llu",temp->Local_LongLong_ID);													/* Print Patient ID														*/
		printf("\n------------------------------------\n");
	}//close bracket of else
}//Close bracket of function

/*-------------------------------------------------------------------------------------------------*/
/*implemantion of function Edite_patient_Recordt()	*/
void Edite_patient_Record()
{
	node *temp=(node*)malloc(sizeof(node));																			/* Pointer of node														*/
	printf("\nEnter ID :");																							/* Ask User To Enter His ID					*/
	scanf("%llu",&Global_LongLong_ID);																				/* Take ID From User						*/
	temp=Search_ID(Global_LongLong_ID);																				/* assign temp node to node that return from calling function search_ID	*/	
	if(temp==NULL)																									/* Cheack if Function return NULL										*/
	{//open bracket of if
		printf("\nID NOt Found......\n");																			/* Print That ID Not Found												*/
	}//close bracket of if
	
	else																											/* ID Is Found															*/
	{//open bracket of else
		printf("\n%s",temp->Local_String_Name);
		printf("\n Enter Your Choose :");
		printf("\n1 : Edite Name ");
		printf("\n2 : Edite Age");
		printf("\n3 : Edite Gender");
		printf("\n4 : Edite ID\n");
		scanf("%d",&Global_Short_choose);
		scanf("%c",&Global_char_temp);
		switch(Global_Short_choose)
		{
			case 1:
				printf("Enter Name: ");					 															/* Ask user to Enter Name 	  				*/
				scanf("%[^\n]",temp->Local_String_Name);															/* Get Name From User		  				*/
				scanf("%c",&Global_char_temp);
				break;
			case 2:
				printf("\n\nEnter Age: ");				     														/* Ask user to Enter Age 	  				*/
				scanf("%d",&temp->Local_Short_Age);																	/* Get Age From User		  				*/
				printf("\n%d\n",temp->Local_Short_Age);
				scanf("%c",&Global_char_temp);
				break;
			case 3:										
				printf("\n\nEnter Gender: ");																		/* Ask user to Enter Name 	  				*/
				scanf("%[^\n]",temp->Local_String_Gender);															/* Get Gender From User		  				*/
				scanf("%c",&Global_char_temp);
				break;
			case 4:
				printf("\n\nEnter ID: ");				     														/* Ask user to Enter ID 	  				*/
				scanf("%llu",&temp->Local_LongLong_ID);																/* Get ID From User			  				*/			
				scanf("%c",&Global_char_temp);
				break;
			default:
				printf("\nInvalid Choose....\n");
				break;
		}
	}//close bracket of else

}

/*-------------------------------------------------------------------------------------------------*/
/*implemantion of function Print_avilable_slot()	*/
void Print_avilable_slot()
{//open bracket of function
	printf("\n\n-------------------\n");
	printf("  Avaliable Slots");
	printf("\n-------------------\n");
	for(u16 i=0;i<5;i++)																							/*	loop on slots &Id array	*/
	{//open bracket of for loop
		if(Global_reserved_Slot_ID[i]==0)																			/* Cheack if slot is Not reserved	*/ 
		{//open bracket of if
			printf("%d -> %s\t\n",i+1,Global_Char_slots[i]);														/* print Avilable Slots*/
		}//close bracket of if
	}//close bracket of for loop
}//close bracket of function

/*-------------------------------------------------------------------------------------------------*/
/*implemantion of function Reserve_slot()			*/
void Reserve_slot()
{//open bracket of function
	Print_avilable_slot();																							/* calling function to Print Avilable Slots				*/
	printf("\nEnter Your Slot : \n");																				/* Ask user To Enter slot			*/
	scanf("%d",&Global_Short_choose);																				/* Take Choose from user			*/
	printf("\n\nEnter Patient ID: ");				     															/* Ask user to Enter ID 	  		*/
	scanf("%llu",&Global_LongLong_ID);																				/* Get ID From User					*/
	switch(Global_Short_choose)																						/* Cheak user Choose				*/
	{
		case 1:																										/* if user choose slot Number 1		*/
			Global_reserved_Slot_ID[0]=Global_LongLong_ID;															/* stor patient ID in first element */
			break;																									/* End Of case 1					*/
		
		case 2:																										/* if user choose slot Number 2		*/
			Global_reserved_Slot_ID[1]=Global_LongLong_ID;															/* stor patient ID in second element*/
			break;																									/* End Of case 2					*/
		
		case 3:																										/* if user choose slot Number 3		*/
			Global_reserved_Slot_ID[2]=Global_LongLong_ID;															/* stor patient ID in three element */
			break;																									/* End Of case 3					*/
		
		case 4:																										/* if user choose slot Number 4		*/
			Global_reserved_Slot_ID[3]=Global_LongLong_ID;															/* stor patient ID in four  element */
			break;																									/* End Of case 4					*/
		
		case 5:																										/* if user choose slot Number 5		*/
			Global_reserved_Slot_ID[4]=Global_LongLong_ID;															/* stor patient ID in five  element */
			break;																									/* End Of case 5					*/
		default:																									/* if user choose is incorrect		*/
			printf("\nInvalid Slot....\n");																			/* print invalid choose		   	    */
			break;																									/* End Of defaulte					*/
	}
	
	}//close bracket of function

/*-------------------------------------------------------------------------------------------------*/
/*implemantion of function Cancel_reservation()		*/
void Cancel_reservation()
{//open bracket of function
	Global_short_flag=0;																							/*assign flag to 0					*/
	printf("\n\nEnter Patient ID: ");				     															/* Ask user to Enter ID 	  		*/
	scanf("%llu",&Global_LongLong_ID);																				/* Get ID From User					*/
	for(u16 i=0;i<5;i++)																							/*	loop on patient slots Id array	*/
	{//open bracket of for loop
		if(Global_reserved_Slot_ID[i]==Global_LongLong_ID)															/* Cheack if patient Id Is Reserved	*/ 
		{//open bracket of if
			Global_reserved_Slot_ID[i]=0;																			/* Cancel Patient Reservatio		*/
			printf("\nReservatio Canceled Succecfully \n");															/* print that Reservatiois canceled	*/
			Global_short_flag=1;																					/*assign flag to 1					*/
		}//close bracket of if
	}//close bracket of for loop
	if(Global_short_flag==0)																						/* Cheack if flag =0				*/
	{//open bracket of if
		printf("\nNo Reservatio For This ID\n");																	/* Id not found and print that No Reservatio For This ID*/
	}//close bracket of if
}//close bracket of function

/*-------------------------------------------------------------------------------------------------*/
/*implemantion of function today’s_reservations()		*/
void today_reservations()
{//open bracket of function
	Global_short_flag=0;																							/*assign flag to 0					*/
	printf("\n\n-----------------------\n");
	printf("  Today's Reservation  ");
	printf("\n-----------------------\n");
	for(u16 i=0;i<5;i++)																							/*	loop on slots &Id array	*/
	{//open bracket of for loop
		if(Global_reserved_Slot_ID[i]!=0)																			/* Cheack if slot is Not reserved	*/ 
		{//open bracket of if
			printf("patient ID : %llu -> Reservation Slot : %s\n",Global_reserved_Slot_ID[i],Global_Char_slots[i]);/* today’s_reservations*/
			Global_short_flag=1;
		}//close bracket of if
	}//close bracket of for loop
	if(Global_short_flag==0)																						/* Cheack if flag =0				*/
	{//open bracket of if
		printf("\nNo Reservatio Today\n");																			/* Id not found and print that No Reservatio For This ID*/
	}//close bracket of if
}//close bracket of function
