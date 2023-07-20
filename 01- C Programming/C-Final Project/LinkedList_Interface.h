#ifndef _LINKED_LIST_INTERFACE_H
#define _LINKED_LIST_INTERFACE_H
#include"STD_TYPES.H"
# define NameSize	30									/* define macros object to Name Size	*/
# define GenderSize	5									/* define macros object to Gender Size	*/
u128 Global_LongLong_ID;								/* Global Long Long int Variable		*/
u8 Global_char_temp;									/* Global charchter Variable			*/
u16 Global_Short_choose;								/* Global short Variable to Enter choose*/
u16 Global_short_flag;									/* Global short Variable to using as a flag*/
/*-------------------------------------------------------*/
/* structure to creat LinkedList to stor patient records */
/* Struct data:patient name, age, gender and ID			 */
/*-------------------------------------------------------*/
typedef struct Node_type node;
struct Node_type 					 		/* Struct definiation									  */			
{											/* open bracket of Struct								  */ 
	u8 Local_String_Name[NameSize];		  	/* pointer of charchter to make String for patient Name	  */ 
	u16 Local_Short_Age;					/* Short integer variable for patient Age 				  */
	u8 Local_String_Gender[GenderSize];		/* pointer of charchter to make String for patient Gender */ 
	u128 Local_LongLong_ID;					/* Short integer variable for patient ID				  */
	node *Next;								/* pointer of Struct to refer to next pointer			  */
};											/* Close bracket of Struct								  */

/*-------------------------------------------------------*/
/* Function:Insert()to Add New Node In LinkedList		 */
/*-------------------------------------------------------*/
void Insert();

/*-------------------------------------------------------*/
/*Function:Print_All_Records() toPrint All Records in List*/
/*-------------------------------------------------------*/
void Print_All_Records();

/*-------------------------------------------------------*/
/* Function: Search_ID() 								 */
/* Argument: patinet ID from type Long Long				 */
/* return:   node that have this ID						 */ 
/*-------------------------------------------------------*/
node *Search_ID();

/*-------------------------------------------------------*/
/* Function: print_Patient_Record	 					 */
/* to print one Patient Records							 */
/* Argument: NO Arguments								 */
/*-------------------------------------------------------*/
void print_Patient_Record();

/*-------------------------------------------------------*/
/* Function: Edite_Patient_Record	 					 */
/* to edite  Patient data								 */
/* Argument: NO Arguments								 */
/*-------------------------------------------------------*/
void Edite_patient_Record();

/*-------------------------------------------------------*/
/* Function: print_avilable_slots	 					 */
/* to print avilable_slots with doctor					 */
/* Argument: NO Arguments								 */
/*-------------------------------------------------------*/
void Print_avilable_slot();

/*-------------------------------------------------------*/
/* Function: Reserve_slot			 					 */
/* Reserve a slot with the doctor						 */
/* Argument: NO Arguments								 */
/*-------------------------------------------------------*/
void Reserve_slot();

/*-------------------------------------------------------*/
/* Function: Cancel_reservation							 */
/* Cancel_reservation with the doctor					 */
/* Argument: NO Arguments								 */
/*-------------------------------------------------------*/
void Cancel_reservation();

/*-------------------------------------------------------*/
/* Function: void today’s_reservations					 */
/* Print today’s_reservations							 */
/* Argument: NO Arguments								 */
/*-------------------------------------------------------*/
void today_reservations();
#endif