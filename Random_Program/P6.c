/*
* Copyright (c) 2019, System Level Solutions (India) Pvt. Ltd.
*/

/*
P6. Change single linked list to double linked list. 
	And all features must be supported implemented in singly linked list and reverse print operation to check link connectivity.
*/

/***********************************************************************
* INCLUDES
**********************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // malloc, atoi 
#include <string.h>	// string related function
#include <error.h>

/***********************************************************************
* TYPES
**********************************************************************/
typedef struct Node1 { 
	uint32_t u32Roll_No;
	char cName[20];  
    char cGrade; 
	struct Node1 *next;
	struct Node1 *prev;
} Node;

#define ADD_RECORD 1
#define DELETE_RECORD 2
#define UPDATE_RECORD 3
#define PRINT_RECORD 4
#define SORT_RECORD 5
#define SEARCH_RECORD 6
#define EXIT 7

#define MAX_TRY 3
#define GIVE_EXISTING 2
#define GIVE_NEW 1

/***********************************************************************
* PUBLIC FUNCTION PROTOTYPES
**********************************************************************/
void vDisplayMenu (void);
void vAddRecordFirst (Node **pphead);
void vAddRecordMiddle (Node **pphead);
void vAddRecordLast (Node **pphead);
void vPrintRecord (Node *phead);
void vReversePrintRecord (Node *phead);
void vSearchRecord (Node *phead);
void vDeleteRecordFirst (Node **pphead);
void vDeleteRecordMiddle (Node **pphead);
void vDeleteRecordLast (Node **pphead);
void vUpdateRecord (Node *phead);
void vSortRecord (Node *phead);
void swap(Node *a, Node *b); 
uint32_t u32TakeRollNo (Node *phead, uint8_t u8GiveExisting);
char cTakeGrade (void);
uint8_t u8ValidateMenuChoice (char *pcMenuChoice);
uint32_t u32ValidateLocation (Node *phead) ;
void vDeleteAll(Node **pphead);

int32_t main(void) {
	
	uint8_t u8Menu_Choice = 0;
	char cMenu_Choice[4]; 

	Node *head = NULL;
	
	while (1) {
		vDisplayMenu ();
		printf("\n Enter your choice from menu :");
		scanf(" %[^\n]s",cMenu_Choice);
		u8Menu_Choice =  u8ValidateMenuChoice(cMenu_Choice);
		switch (u8Menu_Choice) {
			case ADD_RECORD:
				if (head == NULL) {
					vAddRecordFirst(&head);
					break;
				} else {
					printf("\n\t Where you want to Add Record");
					printf("\n\t 1.First 2.Middle 3.Last");
					printf("\n\t Enter your choice :");
					scanf(" %[^\n]s",cMenu_Choice);
					u8Menu_Choice =  u8ValidateMenuChoice(cMenu_Choice);
					switch (u8Menu_Choice) {
						case 1:
							vAddRecordFirst(&head);
						break;
						case 2:
							vAddRecordMiddle(&head);
						break;
						case 3:
							vAddRecordLast(&head);
						break;
						default:
							printf("\t Invalid Input");
						break;
					}
				}
			break;
			case DELETE_RECORD:
				if (head == NULL) {
					printf("\t No record to delete");
				} else {
					printf("\n\t Where you want to Delete Record");
					printf("\n\t 1.First 2.Middle 3.Last");
					printf("\n\t Enter your choice :");
					scanf(" %[^\n]s",cMenu_Choice);
					u8Menu_Choice =  u8ValidateMenuChoice(cMenu_Choice);
					switch (u8Menu_Choice) {
						case 1:
							vDeleteRecordFirst(&head);
						break;
						case 2:
							vDeleteRecordMiddle(&head);
						break;
						case 3:
							vDeleteRecordLast(&head);
						break;
						default:
							printf("\t Invalid Input");
						break;
					}	
				}
			break;
			case UPDATE_RECORD:
				if (head == NULL) {
					printf("\t No record to Update");
				} else {
					vUpdateRecord(head);
				}
			break;
			case PRINT_RECORD:
				if (head == NULL) {
					printf("\t No record to print");
				} else {
					printf("\n\t How you want to print the record");
					printf("\n\t 1.Forward 2.Reverse");
					printf("\n\t Enter your choice :");
					scanf(" %[^\n]s",cMenu_Choice);
					u8Menu_Choice =  u8ValidateMenuChoice(cMenu_Choice);
					switch (u8Menu_Choice) {
						case 1:
							vPrintRecord(head);
						break;
						case 2:
							vReversePrintRecord(head);
						break;
						default:
							printf("\t Invalid Input");
						break;
					}
				}
			break;
			case SORT_RECORD:
				if (head == NULL) {
					printf("\t No record to Sort");
				} else if (head->prev == NULL && head->next == NULL) {
					printf("\t Only one record to Sort");
				} else {
					vSortRecord(head);
				}			
			break;
			case SEARCH_RECORD:
				if (head == NULL) {
					printf("\t No record to Search");
				} else {
					vSearchRecord(head);
				}
			break;
			case EXIT:
				vDeleteAll(&head);	
				return 0;						
			default:
				printf("\t Invalid Input");
			break;
		}
	} 
}

/***********************************************************************
* PUBLIC FUNCTIONS
**********************************************************************/
//Diplay Menu
void vDisplayMenu (void) {
	printf("\n\n MENU for student data record");
	printf("\n\t 1. Add student record");
	printf("\n\t 2. Delete student record");
	printf("\n\t 3. Update student record");
	printf("\n\t 4. Print student record");
	printf("\n\t 5. Sort student record");
	printf("\n\t 6. Search student record");
	printf("\n\t 7. EXIT \n");
}

//Add new data at First record
void vAddRecordFirst (Node **pphead) {
	uint32_t u32Rollno_Invalid = 0;
	char cGrade_Invalid = '\0';
   	Node *new_node = (Node*) malloc (sizeof(Node)); 
	if (new_node == NULL) {
		perror("\n Malloc");
		return;
	}
	printf("\n Enter Data for New student ");
	u32Rollno_Invalid = u32TakeRollNo(*pphead, GIVE_NEW);
	if (u32Rollno_Invalid > 0) {
		new_node->u32Roll_No = u32Rollno_Invalid;
		printf("\t Name : ");
		scanf(" %[^\n]s", new_node->cName);
		cGrade_Invalid = cTakeGrade ();
		if (cGrade_Invalid != '\0') {
			new_node->cGrade = cGrade_Invalid;
			new_node->next = *pphead;
			new_node->prev = NULL;
			if ((*pphead) != NULL) {
				(*pphead)->prev = new_node;
			}
			*pphead = new_node;
			printf("\t Students Data has been Added Succesfully.");
		}
	}
	if ( (u32Rollno_Invalid == 0) || (cGrade_Invalid == '\0') ){
		free(new_node);
		new_node = NULL;
	}	
}

//Add new data at Middle record
void vAddRecordMiddle (Node **pphead) {
	uint32_t u32Rollno_Invalid = 0,u32Add_Middle_Location = 0, u32Add_Middle_Location_Previous = 1;
	char cGrade_Invalid = '\0';
	Node *middle = *pphead;
	u32Add_Middle_Location = u32ValidateLocation(*pphead);
	if (u32Add_Middle_Location > 0) {
		while (u32Add_Middle_Location_Previous < (u32Add_Middle_Location-1) ){
			middle = middle->next;
			u32Add_Middle_Location_Previous++;
		}			
		Node *new_node = (Node*) malloc (sizeof(Node));
		if (new_node == NULL) {
			perror("\n Malloc");
			return;
		}
		printf("\n Enter Data for New student ");
		u32Rollno_Invalid = u32TakeRollNo(*pphead, GIVE_NEW);
		if (u32Rollno_Invalid > 0) {
			new_node->u32Roll_No = u32Rollno_Invalid;
			printf("\t Name : ");
			scanf(" %[^\n]s", new_node->cName);
			cGrade_Invalid = cTakeGrade ();
			if (cGrade_Invalid != '\0') {
				new_node->cGrade = cGrade_Invalid;
				new_node->next = middle->next;
				middle->next = new_node;
				new_node->prev = middle;
				new_node->next->prev = new_node;
				printf("\t Students Data has been Added Succesfully.");
			}
		}
		if ( (u32Rollno_Invalid == 0) || (cGrade_Invalid == '\0') ){
			free(new_node);
			new_node = NULL;
		}	
	}
}

//Add new data at Last record
void vAddRecordLast (Node **pphead) {
	uint32_t u32Rollno_Invalid = 0;
	char cGrade_Invalid = '\0';
   	Node *new_node = (Node*) malloc (sizeof(Node));
	Node *last = *pphead;
	if (new_node == NULL) {
		perror("\n Malloc");
		return;
	}
	printf("\n Enter Data for New student ");
	u32Rollno_Invalid = u32TakeRollNo(*pphead, GIVE_NEW);
	if (u32Rollno_Invalid > 0) {
		new_node->u32Roll_No = u32Rollno_Invalid;
		printf("\t Name : ");
		scanf(" %[^\n]s", new_node->cName);
		cGrade_Invalid = cTakeGrade ();
		if (cGrade_Invalid != '\0') {
			new_node->cGrade = cGrade_Invalid;
			new_node->next = NULL;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = new_node;
			new_node->prev = last;
			printf("\t Students Data has been Added Succesfully.");
		}
	}
	if ( (u32Rollno_Invalid == 0) || (cGrade_Invalid == '\0') ){
		free(new_node);
		new_node = NULL;
	}	
}

//Print All record
void vPrintRecord (Node *phead) {
	printf("\n All Students Record from forward direction is:\n"); 
	printf(" \tRollno \tName \t\t\tGrade \n");
	while ( phead != NULL) {
		printf("\t%u", phead->u32Roll_No); 
		printf("\t%-20s", phead->cName);
		printf("\t%c\n", phead->cGrade);
	    phead = phead->next;
	}
}

//Print All record in Reverse 
void vReversePrintRecord (Node *phead) {
	while ( phead != NULL) {
		if (phead->next == NULL) {
			break;
		} else {
			phead = phead->next;
		}
	}
	printf("\n All Students Record from reverse direction is:\n"); 
	printf(" \tRollno \tName \t\t\tGrade \n");
	while ( phead != NULL) {
		printf("\t%u", phead->u32Roll_No); 
		printf("\t%-20s", phead->cName);
		printf("\t%c\n", phead->cGrade);
	    phead = phead->prev;
	}
}

//Search record
void vSearchRecord (Node *phead) {
	uint32_t u32Rollno_Invalid = 0;
	printf("\n\t Enter student Roll No to Search"); 
	u32Rollno_Invalid = u32TakeRollNo(phead, GIVE_EXISTING);
	if (u32Rollno_Invalid > 0) {
		while (phead != NULL) {
			if(phead->u32Roll_No == u32Rollno_Invalid) {
				printf("\n\tStudent Record is : \n");
				printf(" \tRollno \tName \t\t\tGrade \n");
				printf("\t%u", phead->u32Roll_No); 
				printf("\t%-20s", phead->cName);
				printf("\t%c\n", phead->cGrade);
				break;
			} else {
				phead = phead->next;
			}	
		}
	}
}

//Delete First record
void vDeleteRecordFirst (Node **pphead) {
	Node *first = *pphead;
	if ((first->prev == NULL) && (first->next == NULL)) {	//head is only the data make head null
		*pphead = NULL;
	} else {
		*pphead = first->next;	//reference of first is now head
		first->next->prev = NULL;
	}
	printf("\n\t First Record has been deleted succesfully.");	
	free(first);	// free the space
	first = NULL;
}

//Delete Middle record
void vDeleteRecordMiddle (Node **pphead) {
	uint32_t u32Rollno_Invalid = 0;
	Node *middle = *pphead;
	printf("\n\t Enter Student Roll No to delete data ");
	u32Rollno_Invalid = u32TakeRollNo(*pphead, GIVE_EXISTING);
	if (u32Rollno_Invalid > 0) {
		while (middle != NULL) {
			if(middle->u32Roll_No == u32Rollno_Invalid) {
				if ((middle->prev == NULL) && (middle->next == NULL)) {	// if record to delete is only record left
					*pphead = NULL;
				} else if (middle->prev == NULL) {	// data to delete is head
					*pphead = middle->next;
					middle->next->prev = NULL;
				} else if (middle->next == NULL) {	// data to delete is last
					middle->prev->next = NULL;
				} else {	// data to delete is not first nor last
					middle->prev->next = middle->next;
					middle->next->prev = middle->prev;
				}
				free(middle);
				middle = NULL;
				printf("\n\t Student Record has been deleted sucessfully.");
				break;
			} else {					   
				middle = middle->next;
			}	
		}
	}
}

//Delete Last record
void vDeleteRecordLast (Node **pphead) {
	Node *last = *pphead;
	if ((last->prev == NULL) && (last->next == NULL)) {	// last record is only record left to delete make head null
		*pphead = NULL;
	} else {
		while (last->next != NULL) {	// traverse till last record	
			last = last->next;
		}
		last->prev->next = NULL;	
	}
	printf("\n\t Last Record has been deleted succesfully.");
	free(last);
	last = NULL;
}	

//Update data in record
void vUpdateRecord(Node *phead) {
	uint32_t u32Rollno_Invalid = 0;
	char cGrade_Invalid = '\0', cUpdate_Record_Fd[4];	
	uint8_t u8Update_Record_Fd = 0;
	
	printf("\t Enter the student rollno to Update data ");
	u32Rollno_Invalid = u32TakeRollNo(phead, GIVE_EXISTING);
	if (u32Rollno_Invalid > 0) {
		while (phead->u32Roll_No != u32Rollno_Invalid) {
			phead = phead->next;
		}	
		printf("\t\t Feild choice 1.Name 2.Grade ");
		printf("\n\t\t Enter feild choice : ");
		scanf(" %[^\n]s",cUpdate_Record_Fd);
		u8Update_Record_Fd =  u8ValidateMenuChoice(cUpdate_Record_Fd);
		switch (u8Update_Record_Fd) {
			case 1:
				memset(phead->cName, 0, sizeof(phead->cName));
				printf("\t Name : ");
				scanf(" %[^\n]", phead->cName);
				printf("\t Students Data is updated Succesfully.");
			break;
			case 2:
				cGrade_Invalid = cTakeGrade ();
				if (cGrade_Invalid != '\0') {
					phead->cGrade = cGrade_Invalid;
					printf("\t Students Data is updated Succesfully.");
				}		
			break;
			default:
					printf("\t\t Invalid Input");
			break;
		}
	}
}

//Sort the data based on Roll Number
void vSortRecord (Node *phead) {
					
	uint8_t swapped = 0;
	Node *currentptr;
//	currentptr = phead;
//	while (currentptr->next != NULL) { 	 
//		while (currentptr->u32Roll_No > currentptr->next->u32Roll_No) { 
//			temp = currentptr;
//			currentptr->next = temp->next->next;
//			if(temp->next->next != NULL) {
//				currentptr->prev = temp->next->next->prev;
//			}
//			if(currentptr->prev->prev != NULL )	
//			currentptr->prev->prev = 
			 
		
	
	do { 
    	swapped = 0; 
        currentptr = phead; 
        while (currentptr->next != NULL) { 
            if (currentptr->u32Roll_No > currentptr->next->u32Roll_No) {  	
				swap(currentptr,currentptr->next);
				swapped = 1; 
            } 
            currentptr = currentptr->next; 
        } 
    }  while (swapped);  
	printf("\t Students Data has been sorted by RollNo Succesfully.");
} 

// Swap the data
void swap(Node *a, Node *b) { 

	uint32_t temp_u32Roll_No;
	char temp_cName[8];  
    char temp_cGrade; 

	temp_u32Roll_No = a->u32Roll_No; 
	strcpy(temp_cName,a->cName);
	temp_cGrade = a->cGrade;
	
	a->u32Roll_No = b->u32Roll_No;
	strcpy(a->cName,b->cName);
	a->cGrade = b->cGrade;
	
    b->u32Roll_No = temp_u32Roll_No;
	strcpy(b->cName,temp_cName); 
	b->cGrade = temp_cGrade;

} 

//Validate Menu Choice
uint8_t u8ValidateMenuChoice(char *pcMenuChoice) {
	uint8_t u8Count = 0;
	while (pcMenuChoice[u8Count] != '\0') {
		if (u8Count == 2) {		// not allowed more than 2 charatcter entry
			return 0;	// Invalid Input
		} else if ((pcMenuChoice[u8Count] < '0') || (pcMenuChoice[u8Count] > '9')) { // if character entered is not number
			return 0;	// Invalid Input
		} else {
			u8Count++;
		}
	}
	//printf("\n %ld",atoi(cMenuChoice));
	return (uint8_t)(atoi(pcMenuChoice));	// ASCII to integer(uint8_t)
}

//Validate Location
uint32_t u32ValidateLocation (Node *phead) {
	uint8_t u8Try = MAX_TRY, u8Count;
	uint32_t u32Location , u32Location_Count;
	char cBuffer[10];
	Node *last = phead;
	while (u8Try != 0) {
		u8Count = 0;
		u32Location = 0;
		u32Location_Count = 0;
		last = phead;
		memset(cBuffer, 0, sizeof(cBuffer));
		printf("\n\t Enter Location : ");
		scanf(" %[^\n]s",cBuffer);
		while (cBuffer[u8Count] != '\0') {	// to validate all entered char are digits
			if (u8Count == 5) {	// no more than 5 character entry
				break;
			} else 	if ((cBuffer[u8Count] < '0') || (cBuffer[u8Count] > '9')) {  
				break;
			} else {
				u8Count++;
			}
		}
		if (cBuffer[u8Count] == '\0') {
			u32Location = atoi(cBuffer); // returns 0 if conversion is not possible
			 while (last != NULL) { 
				last = last->next;
				u32Location_Count++;
			}
			if((u32Location > 1) && (u32Location <= u32Location_Count)){
				return u32Location;	// Valid entry
			} else {
				printf("\t Location cannot be zero or first or more than total locations");
				u8Try--;
			}
		} else {
			printf("\t Invalid Input");
			u8Try--;
		}
	}				
	return 0;
}

//Delete all records
void vDeleteAll(Node **pphead) {
	Node *temp;
	while (*pphead != NULL) {
		temp = *pphead;
		if ((temp->prev == NULL) && (temp->next == NULL)) {	//head is only the data make head null
			*pphead = NULL;
		} else {
			*pphead = temp->next;
			temp->next->prev = NULL;
		}
	free(temp);
	temp = NULL;
	}
}

//Take RollNo
uint32_t u32TakeRollNo (Node *phead, uint8_t u8GiveExisting) {
	uint8_t u8Try = MAX_TRY, u8Count;
	uint32_t u32RollNo;
	char cBuffer[10];
	Node *temp;
	while (u8Try != 0) {
		u8Count = 0;
		u32RollNo = 0;
		temp = phead;
		memset(cBuffer, 0, sizeof(cBuffer));
		printf("\n\t Rollno : ");
		scanf(" %[^\n]s",cBuffer);
		while (cBuffer[u8Count] != '\0') {	// to validate all entered char are digits
			if (u8Count == 5) {	// no more than 5 character entry
				break;
				//return 1;	// Invalid Input
			} else 	if ((cBuffer[u8Count] < '0') || (cBuffer[u8Count] > '9')) {  
				break;
				//return 1;	// Invalid Input
			} else {
				u8Count++;
			}
		}
		if (cBuffer[u8Count] == '\0') {
			u32RollNo = atoi(cBuffer); // returns 0 if conversion is not possible
			//printf("d",u32RollNo);
			if ((u32RollNo > 0) && (u32RollNo < 50000)) {
				while(temp != NULL) {
					if(u32RollNo == temp->u32Roll_No) {
						if (u8GiveExisting == GIVE_EXISTING) {
							return u32RollNo;	// Return existing Rollno
						} else {
							printf("\t Student Record for RollNo is present");
							u8Try--;
							break;	
						}
					} else {
						temp = temp->next;
					}
				}
				if ((temp == NULL) && (u8GiveExisting == GIVE_EXISTING)) {
					printf("\t Student Record not present");	// checked all number then Return 0
					u8Try--;
				} else if ((temp == NULL) && (u8GiveExisting == GIVE_NEW)) {
					return u32RollNo;	// checked all number then Return new Roll Number
				} else {
					//Nothing
				}
			} else {
				printf("\t Students RollNo is out of Range");
				u8Try--;
			}
		} else {
			printf("\t Students RollNo is Invalid");
			u8Try--;	
		}
	}
	return 0;
}

// Take Grade
char cTakeGrade (void) {
	uint8_t u8Try = MAX_TRY, u8Count;
	char cBuffer[10];
	while (u8Try != 0) {
		u8Count = 0;
		memset(cBuffer, 0, sizeof(cBuffer));
		printf("\t Grade : ");
		scanf(" %[^\n]s", cBuffer);
		while (cBuffer[u8Count] != '\0') {
			if (u8Count == 1) {	// no more than 1 character entry
				break;	// Invalid Input
			} else if ((cBuffer[u8Count] < 'A') || (cBuffer[u8Count] > 'D')) {
				break;	// Invalid Input
			} else {
				u8Count++;
			}
		}
		if (cBuffer[u8Count] == '\0') {
			return cBuffer[0];	// checked all number then new Return Number
		} else {
			printf("\t Students Grade is Invalid.");
			u8Try--;
		}
	}
	return '\0';
}



