/*
* Copyright (c) 2019, System Level Solutions (India) Pvt. Ltd.
*/

/*
P5. Implement above functionality using single link list and dynamic memory allocation. 
	Linked list must perform various operations like, insert (at first, at given nth location and end), delete (at first, at given nth location and end) search, print and update.
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
	char cName[16];  
    char cGrade; 
	struct Node1 *next;
} Node;

#define ADD_RECORD 1
#define DELETE_RECORD 2
#define UPDATE_RECORD 3
#define PRINT_RECORD 4
#define SORT_RECORD 5
#define SEARCH_RECORD 6
#define EXIT 7

#define MAX_TRY 3

/***********************************************************************
* PUBLIC FUNCTION PROTOTYPES
**********************************************************************/
void vDisplayMenu (void);
void vAddRecordFirst (Node **pphead);
void vAddRecordMiddle (Node *phead);
void vAddRecordLast (Node *phead);
void vPrintRecord (Node *phead);
void vSearchRecord (Node *phead);
void vDeleteRecordFirst (Node **pphead);
void vDeleteRecordMiddle (Node **pphead);
void vDeleteRecordLast (Node **pphead);
void vUpdateRecord (Node *phead);
void vSortRecord (Node *phead);
void swap(Node *a, Node *b); 
uint8_t u8ValidateMenuChoice (char cMenuChoice[2]);
uint8_t u8ValidateRollNo (char cRollNo[6], Node *phead);
uint8_t u8ValidateName (char cname[20]);
uint8_t u8ValidateGrade (char cgrade[2]);
uint8_t u8ValidateLocation (char cRollNo[6], Node *phead);

int32_t main(void) {
	
	uint8_t u8Menu_Choice = 0, u8Sub_Menu_Choice = 0;
	char cMenu_Choice[2], cSub_Menu_Choice[2]; 

	Node *head = NULL;
	
	while (1) {
		vDisplayMenu ();
		printf("\n Enter your choice from menu :");
		scanf(" %[^\n]",&cMenu_Choice);
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
					scanf(" %[^\n]",&cSub_Menu_Choice);	
					u8Sub_Menu_Choice =  u8ValidateMenuChoice(cSub_Menu_Choice);
					switch (u8Sub_Menu_Choice) {
						case 1:
							vAddRecordFirst(&head);
						break;
						case 2:
							vAddRecordMiddle(head);
						break;
						case 3:
							vAddRecordLast(head);
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
					scanf(" %[^\n]",&cSub_Menu_Choice);	
					u8Sub_Menu_Choice =  u8ValidateMenuChoice(cSub_Menu_Choice);
					switch (u8Sub_Menu_Choice) {
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
					vPrintRecord(head);
				}
			break;
			case SORT_RECORD:
				if (head == NULL) {
					printf("\t No record to Sort");
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
	
	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1, u8Name_Invalid = 1, u8Grade_Invalid = 1;
	char cBuffer[20];

   	Node *first = (Node*) malloc (sizeof(Node)); 
	if (first == NULL) {
		perror("\n Malloc");
		return;
	}
	printf("\n Enter Data for New student ");
	while (u8Try != 0) {
		printf("\n\t Rollno : ");
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer, *pphead);
		if (u8Rollno_Invalid == 0) {
			first->u32Roll_No = atoi(cBuffer);
			u8Try = MAX_TRY;
			while (u8Try != 0) {
				printf("\t Name : ");
				scanf(" %[^\n]", &cBuffer);	
				u8Name_Invalid = u8ValidateName(cBuffer);
				if (u8Name_Invalid == 0) {
					strcpy(first->cName,cBuffer);		
					u8Try = MAX_TRY;
					while (u8Try != 0) {
						printf("\t Grade : ");
						scanf(" %[^\n]", &cBuffer);
						u8Grade_Invalid = u8ValidateGrade(cBuffer);
						if (u8Grade_Invalid == 0) {
							first->cGrade = cBuffer[0];
							first->next = *pphead;
							*pphead = first;
							printf("\t Students Data has been Added Succesfully.");
							break;
						} else {
							printf("\t Students Grade is Invalid.");
							u8Try--;
						}
					}
					break;
				} else if (u8Name_Invalid == 2 ) {
					printf("\t Student Name is more than maxminum length allowed ");
					u8Try--;
				} else {
					printf("\t Students Name is Invalid");
					u8Try--;
				}
			}
			break;		
		} else if (u8Rollno_Invalid == 2) {
			printf("\t Student Record with already present");
			u8Try--;
		} else {
			printf("\t Students RollNo is Invalid");
			u8Try--;
		}
	}
	if (u8Try == 0) {
		free(first);
	}
}

//Add new data at Middle record
void vAddRecordMiddle (Node *phead) {
	
	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1, u8Name_Invalid = 1, u8Grade_Invalid = 1, u8Location_Invalid = 1;
	char cBuffer[20];
	
	uint32_t u32Add_Middle_Location = 0, u32Add_Middle_Location_Previous = 1;
	
   	Node *prev_node = phead;
	
	while (u8Try != 0) {
		printf("\n\t Enter the location number : ");
		scanf(" %[^\n]",&cBuffer);
		u8Location_Invalid = u8ValidateLocation(cBuffer, phead);
		if (u8Location_Invalid == 0) {
			u32Add_Middle_Location = atoi(cBuffer);
				while (u32Add_Middle_Location_Previous < (u32Add_Middle_Location-1) ){
					prev_node = prev_node->next;
					u32Add_Middle_Location_Previous++;
				}			
				Node *new_node = (Node*) malloc (sizeof(Node));
				if (new_node == NULL) {
					perror("\n Malloc");
					return;
				}
				printf("\n Enter Data for New student ");
				u8Try = MAX_TRY;
				while (u8Try != 0) {
					printf("\n\t Rollno : ");
					scanf(" %[^\n]",&cBuffer);
					u8Rollno_Invalid = u8ValidateRollNo(cBuffer, phead);
					if (u8Rollno_Invalid == 0) {
						new_node->u32Roll_No = atoi(cBuffer);
						u8Try = MAX_TRY;
						while (u8Try != 0) {
							printf("\t Name : ");
							scanf(" %[^\n]", &cBuffer);	
							u8Name_Invalid = u8ValidateName(cBuffer);
							if (u8Name_Invalid == 0) {
								strcpy(new_node->cName,cBuffer);		
								u8Try = MAX_TRY;
								while (u8Try != 0) {
									printf("\t Grade : ");
									scanf(" %[^\n]", &cBuffer);
									u8Grade_Invalid = u8ValidateGrade(cBuffer);
									if (u8Grade_Invalid == 0) {
										new_node->cGrade = cBuffer[0];
										new_node->next = prev_node->next;
										prev_node->next = new_node;
										printf("\t Students Data has been Added Succesfully.");
										break;
									} else {
										printf("\t Students Grade is Invalid.");
										u8Try--;
									}
								}
								break;
							} else if (u8Name_Invalid == 2 ) {
								printf("\t Student Name is more than maxminum length allowed "); 
								u8Try--;
							} else {
								printf("\t Students Name is Invalid");
								u8Try--;
							}
						}
						break;
					} else if (u8Rollno_Invalid == 2) {
						printf("\t Student Record with already present");
						u8Try--;
					} else {
						printf("\t Students RollNo is Invalid");
						u8Try--;
					}
				}
				if (u8Try == 0) {
					free(new_node);
				}
				break;
		} else if (u8Location_Invalid == 2) {
			printf("\n\t Location is cannot be zero or first or more than total locations");
			u8Try--;
		} else {
			printf("\n\t Invalid Input");
			u8Try--;
		}

	}	
}

//Add new data at Last record
void vAddRecordLast (Node *phead) {

	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1, u8Name_Invalid = 1, u8Grade_Invalid = 1;
	char cBuffer[20];

   	Node *new_node = (Node*) malloc (sizeof(Node));
	Node *last = phead;
	if (new_node == NULL) {
		perror("\n Malloc");
		return;
	}
	printf("\n Enter Data for New student ");
	while (u8Try != 0) {
		printf("\n\t Rollno : ");
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer, phead);
		if (u8Rollno_Invalid == 0) {
			new_node->u32Roll_No = atoi(cBuffer);
			u8Try = MAX_TRY;
			while (u8Try != 0) {
				printf("\t Name : ");
				scanf(" %[^\n]", &cBuffer);	
				u8Name_Invalid = u8ValidateName(cBuffer);
				if (u8Name_Invalid == 0) {
					strcpy(new_node->cName,cBuffer);		
					u8Try = MAX_TRY;
					while (u8Try != 0) {
						printf("\t Grade : ");
						scanf(" %[^\n]", &cBuffer);
						u8Grade_Invalid = u8ValidateGrade(cBuffer);
						if (u8Grade_Invalid == 0) {
							new_node->cGrade = cBuffer[0];
							new_node->next = NULL;
							while (last->next != NULL) {
								last = last->next;
							}
							last->next = new_node;
							printf("\t Students Data has been Added Succesfully.");
							break;
						} else {
							printf("\t Students Grade is Invalid.");
							u8Try--;
						}
					}
					break;
				} else if (u8Name_Invalid == 2 ) {
					printf("\t Student Name is more than maxminum length allowed ");
					u8Try--;
				} else {
					printf("\t Students Name is Invalid");
					u8Try--;
				}
			}
			break;		
		} else if (u8Rollno_Invalid == 2) {
			printf("\t Student Record with already present");
			u8Try--;
		} else {
			printf("\t Students RollNo is Invalid");
			u8Try--;
		}
	}
	if (u8Try == 0) {
		free(new_node);
	}
}

//Print All record
void vPrintRecord (Node *phead) {
	printf("\n All Students Record is:\n"); 
	printf(" \tRollno \tName \t\tGrade \n");
	while ( phead != NULL) {
		printf("\t%u", phead->u32Roll_No); 
		printf("\t%s", phead->cName);
		printf("\t\t%c\n", phead->cGrade);
	    phead = phead->next;
	}
}

//Search record
void vSearchRecord (Node *phead) {
	
	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1;
	char cBuffer[20];
	
	uint32_t u32Search_Rn;
	while (u8Try != 0) {
		printf("\n\t Enter student Roll No to search : "); 
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer, phead);
		if (u8Rollno_Invalid == 2) {
			u32Search_Rn = atoi(cBuffer);
				while (phead != NULL) {
				if(phead->u32Roll_No == u32Search_Rn) {
					printf("\n\t Students Record is:\n");
					printf(" \tRollno \tName \t\tGrade \n");
					printf("\t%u", phead->u32Roll_No); 
					printf("\t%s", phead->cName);
					printf("\t\t%c\n", phead->cGrade);
					break;
				} else {
					phead = phead->next;
				}	
			}
			break;		
		} else if (u8Rollno_Invalid == 0) {
			printf("\t Student Record not present");
			u8Try--;
		} else {
			printf("\t Students RollNo is Invalid");
			u8Try--;
		}
	}
}

//Delete First record
void vDeleteRecordFirst (Node **pphead) {
	Node *first = *pphead;
	*pphead = first->next;	//reference of first is now head
	if (first->next == NULL) {	//head is only the data make head null
		*pphead = NULL;
	}
	printf("\n\t First Record has been deleted succesfully.");
	free(first);	// free the space
}

//Delete Middle record
void vDeleteRecordMiddle (Node **pphead) {
	
	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1;
	char cBuffer[20];
	
	uint32_t u32Delete_Record_Rn = 0;
	Node *middle = *pphead;
	Node *previous = *pphead;
	printf("\n\t Enter Student Roll No to delete data ");
	while (u8Try != 0) {
		printf("\n\t Rollno : ");
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer, *pphead);
		if (u8Rollno_Invalid == 2) {
			u32Delete_Record_Rn = atoi(cBuffer);
			while (middle != NULL) {
				if(middle->u32Roll_No == u32Delete_Record_Rn) {
					if ((previous->u32Roll_No == middle->u32Roll_No) && (middle->next == NULL)) { // if record to delete is only one record left 
						*pphead = NULL;
					} else if (previous->u32Roll_No == middle->u32Roll_No) { // data to delete is head
						*pphead = middle->next;
					} else if (middle->next == NULL) { // data to delete is last
						previous->next = NULL;
					} else { // data to delete is not first nor last
						previous->next = middle->next;
					}
					free(middle);
					printf("\n\t Student Record has been deleted sucessfully.");
					break;
				} else {
					previous = middle;
					middle = middle->next;
				}	
			}
			break;
		} else if (u8Rollno_Invalid == 0) {
			printf("\t Students Record doesnot exists ");
			u8Try--;
		} else {
			printf("\t Students RollNo is Invalid");
			u8Try--;
		}
	}
}

//Delete Last record
void vDeleteRecordLast (Node **pphead) {
	Node *last = *pphead;
	Node *previous = *pphead;
	if (last->next == NULL) {
		*pphead = NULL;
		printf("\n\t Last Record has been deleted succesfully.");
		return;
	}
	
	while (last->next != NULL) {	// traverse till last record
			previous = last;
		    last = last->next;
		}
	previous->next = last->next ;
	printf("\n\t Last Record has been deleted succesfully.");
	free(last);
}	

//Update data in record
void vUpdateRecord(Node *phead) {
	
	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1, u8Name_Invalid = 1, u8Grade_Invalid = 1;
	char cBuffer[6], cFeild_Choice[2];
	
	uint32_t u32Update_Record_Rn = 0;		
	uint8_t u8Update_Record_Fd = 0;
	
	while (u8Try != 0) {
		printf("\t Enter the student rollno to update data : ");
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer, phead);
		if (u8Rollno_Invalid == 2) {
			u32Update_Record_Rn = atoi(cBuffer);
			while (phead->u32Roll_No != u32Update_Record_Rn) {
				phead = phead->next;
			}	
			printf("\t\t Feild choice 1.Name 2.Grade ");
			printf("\n\t\t Enter feild choice : ");
			scanf(" %[^\n]", &cFeild_Choice);
			u8Update_Record_Fd =  u8ValidateMenuChoice(cFeild_Choice);		
			switch(u8Update_Record_Fd) {
				case 1:	
					u8Try = MAX_TRY;
					while (u8Try != 0) {
						printf("\t\t Enter student name to update : ");
						scanf(" %[^\n]", &cBuffer);
						u8Name_Invalid = u8ValidateName(cBuffer);
						if (u8Name_Invalid == 0) {
							strcpy(phead->cName,cBuffer);
									printf("\t Students Data is updated Succesfully.");
									break;
								} else if (u8Name_Invalid == 2 ) {
									printf("\t Student Name is more than maxminum length allowed "); 
								} else {
									printf("\t Students Name is Invalid");
									u8Try--;
								}
							}						
						break;
						case 2:
							u8Try = MAX_TRY;
							while (u8Try != 0) {
								printf("\t\t Enter student grade to update : ");
								scanf(" %[^\n]", &cBuffer);
								u8Grade_Invalid = u8ValidateGrade(cBuffer);
								if (u8Grade_Invalid == 0) {
									phead->cGrade = cBuffer[0];
									printf("\t Students Data is updated Succesfully.");
									break;
								} else {
									printf("\t Students Grade is Invalid.");
									u8Try--;
								}
							}		
						break;
						default:
								printf("\t\t Invalid Input");
						break;
					}
			break;
		} else if (u8Rollno_Invalid == 0) {
			printf("\t Students Record doesnot exists ");
			u8Try--;
		} else {
			printf("\t Students RollNo is Invalid");
			u8Try--;
		}
	}
}

//Sort the data based on Roll Number
void vSortRecord (Node *phead) {

	uint8_t swapped = 0;
	Node *currentptr;
		
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
uint8_t u8ValidateMenuChoice(char cMenuChoice[2]) {
	if (cMenuChoice[1] != '\0') {	// no more than one character entry
		return 0;
	} else {
	return (uint8_t)(atoi(cMenuChoice));	// ASCII to integer(uint8_t)
	}
}

//Validate RollNo
uint8_t u8ValidateRollNo(char cRollNo[6], Node *phead) {
	uint8_t u8Count = 0;
	uint32_t u32RollNo = 0;
	//printf("%s",cRollNo);
	while (cRollNo[u8Count] != '\0') {	// to validate all entered char are digits
		if (u8Count == 6) {	// no more than 5 character entry
			return 1;	// Invalid Input
		} else 	if ((cRollNo[u8Count] < '0') || (cRollNo[u8Count] > '9')) {  
			return 1;	// Invalid Input
		} else {
			u8Count++;
		}
	}	
	u32RollNo = atoi(cRollNo); // returns 0 if conversion is not possible
	//printf("d",u32RollNo);
	if ((u32RollNo > 0) && (u32RollNo < 100000)) {
		while(phead != NULL) {
				if(u32RollNo == phead->u32Roll_No) {
					return 2;	// Rollno already exists
				} else {
					phead = phead->next;
				}
		}
		return 0;	// Valid entry
	} else {
		return 1;	// Invalid Input
	}	
}

//Validate Name
uint8_t u8ValidateName(char cname[20]) {
	uint8_t u8Count = 0;
	while (cname[u8Count] != '\0') {
		if (u8Count == 20) {
			return 2; // Input more than 20 Maximum length
		} else {
			if (((cname[u8Count] < 'A') || (cname[u8Count] > 'Z')) && ((cname[u8Count] < 'a') || (cname[u8Count] > 'z'))) {
				if (cname[u8Count] != ' ') {
					return 1;	// Invalid Input
				}
			}
			u8Count++;
		}
	}
	return 0;	// Valid Input
}

//Validate Garde
uint8_t u8ValidateGrade(char cgrade[2]) {
	//printf("%s",cgrade);
	if (cgrade[1] != '\0') {	// no more than one character entry
		return 1;	// Invalid Input
	} else if (cgrade[0] >= 'A' && cgrade[0] <= 'D') {
		return 0;	// Valid Input
	} else {
		return 1; // Invalid Input
	}
}

//Validate Location
uint8_t u8ValidateLocation (char cLocation[6], Node *phead) {
		
	uint8_t u8Count = 0;
	uint32_t u32Location = 0, u32Location_Count = 0;
	//printf("%s",cRollNo);
	while (cLocation[u8Count] != '\0') {	// to validate all entered char are digits
		if (u8Count == 6) {	// no more than 5 character entry
			return 1;	// Invalid Input
		} else 	if ((cLocation[u8Count] < '0') || (cLocation[u8Count] > '9')) {  
			return 1;	// Invalid Input
		} else {
			u8Count++;
		}
	}	
	u32Location = atoi(cLocation); // returns 0 if conversion is not possible
	
	Node *last = phead;
	
   	while (last != NULL) { 
	    last = last->next;
	    u32Location_Count++;
	}

	if((u32Location > 1) && (u32Location <= u32Location_Count)){
		return 0;	// Valid entry
	} else {
		return 2;	// cannot add at zero or first or more than record locations
	}	
}

	

