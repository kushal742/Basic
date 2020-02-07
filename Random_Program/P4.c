/*
* Copyright (c) 2019, System Level Solutions (India) Pvt. Ltd.
*/

/*
P4. Develop a program to maintain student data recodes (Name, Rollnum, and Grade).
    Program should contain these functionality: input from the user, short the data based on rollnum, print the data, delete the recode and modify the recode.
*/

/***********************************************************************
* INCLUDES
**********************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>	//for atoi function
#include <string.h> //String related function

/***********************************************************************
* TYPES
**********************************************************************/
typedef struct { 
	uint32_t u32Roll_No;
	char cName[20];  
    char cGrade; 
} students_st;

#define ADD_RECORD 1
#define DELETE_RECORD 2
#define UPDATE_RECORD 3
#define PRINT_RECORD 4
#define SORT_RECORD 5
#define EXIT 6

#define MAX_TRY 3

/***********************************************************************
* GLOBAL VARIABLES
**********************************************************************/
uint8_t u8Rec_Count = 0;
students_st student_t[10];

/***********************************************************************
* PUBLIC FUNCTION PROTOTYPES
**********************************************************************/
void vDisplayMenu (void);
void vAddRecord (void);
void vPrintRecord (void);
void vDeleteRecord (void);
void vUpdateRecord (void);
int iCompareInt (const void *pvElement1, const void *pvElement2);
void vSortRecord (void);
uint8_t u8ValidateMenuChoice(char cMenuChoice[2]);
uint8_t u8ValidateRollNo(char cRollNo[6]);
uint8_t u8ValidateName(char cname[20]);
uint8_t u8ValidateGrade(char cgrade[2]);

int8_t main(void) {

	uint8_t u8Menu_Choice = 0;
	char cMenu_Choice[2]; 
	while (1) {	
		vDisplayMenu ();
		printf("\n Enter your choice from menu :");
		scanf(" %[^\n]",&cMenu_Choice);
		u8Menu_Choice =  u8ValidateMenuChoice(cMenu_Choice);
		switch (u8Menu_Choice) {
			case ADD_RECORD:	
				if (u8Rec_Count < 100) {
					vAddRecord ();
				} else {
					printf("\t You have reached maximum record, cannot add any more data");
				}
			break;
			case DELETE_RECORD:
				if(u8Rec_Count>0) {
					vDeleteRecord ();
				} else {
					printf("\t No record to Delete");
				}
			break;
			case UPDATE_RECORD:
				if(u8Rec_Count>0) {
					vUpdateRecord ();
				} else {
					printf("\t No record to Update");
					}
			break;
			case PRINT_RECORD:	
				if(u8Rec_Count>0) {
				vPrintRecord ();
				} else {
				printf("\t No record to print");
				}
			break;
			case SORT_RECORD:
				if(u8Rec_Count>1) {
					vSortRecord ();
				} else {
					printf("\t No record to Sort or only one record is present");
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
void vDisplayMenu (void) {
	printf("\n\n MENU for student data record");
	printf("\n\t 1. Add student record");
	printf("\n\t 2. Delete student record");
	printf("\n\t 3. Update student record");
	printf("\n\t 4. Print student record");
	printf("\n\t 5. Sort student record");
	printf("\n\t 6. EXIT \n");
}

//Add new data to record
void vAddRecord (void) {
	
	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1, u8Name_Invalid = 1, u8Grade_Invalid = 1;
	char cBuffer[20];
	
	printf("\n Enter Data for New student ");
	while (u8Try != 0) {
		printf("\n\t Rollno : ");
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer);
		if (u8Rollno_Invalid == 0) {
			student_t[u8Rec_Count].u32Roll_No = atoi(cBuffer);
			u8Try = MAX_TRY;
			while (u8Try != 0) {
				printf("\t Name : ");
				scanf(" %[^\n]", &cBuffer);	
				u8Name_Invalid = u8ValidateName(cBuffer);
				if (u8Name_Invalid == 0) {
					strcpy(student_t[u8Rec_Count].cName,cBuffer);
					u8Try = MAX_TRY;
					while (u8Try != 0) {
						printf("\t Grade : ");
						scanf(" %[^\n]", &cBuffer);
						u8Grade_Invalid = u8ValidateGrade(cBuffer);
						if (u8Grade_Invalid == 0) {
							student_t[u8Rec_Count].cGrade = cBuffer[0];
							u8Rec_Count++;
							printf("\t Students Data has added sucessfully.");
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
}

//Print all the record
void vPrintRecord (void) {
	uint8_t u8Print_Record = 0;	
		printf("\n All Students Record is:\n"); 
		printf(" \tRollno \tName \tGrade \n");
		for (u8Print_Record = 0; u8Print_Record < u8Rec_Count; u8Print_Record++) {
			printf("\t%d", student_t[u8Print_Record].u32Roll_No); 
		    printf("\t%s", student_t[u8Print_Record].cName); 
		    printf("\t%c\n", student_t[u8Print_Record].cGrade); 
		}
}

//Update data in record
void vUpdateRecord(void) {
	
	uint8_t u8Try = MAX_TRY, u8Rollno_Invalid = 1, u8Name_Invalid = 1, u8Grade_Invalid = 1;
	uint32_t u32Update_Record_Rn = 0;
	uint8_t u8Update_Record = 0, u8Update_Record_Fd = 0;	
	char cBuffer[6], cFeild_Choice[2];
	
	while (u8Try != 0) {
		printf("\t Enter the student rollno to update data : ");
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer);
		if (u8Rollno_Invalid == 2) {
				u32Update_Record_Rn = atoi(cBuffer);
				while (student_t[u8Update_Record].u32Roll_No != u32Update_Record_Rn) { 
					u8Update_Record++;
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
								strcpy(student_t[u8Update_Record].cName,cBuffer);
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
							//printf("%s",cBuffer);
							u8Grade_Invalid = u8ValidateGrade(cBuffer);
							if (u8Grade_Invalid == 0) {
								student_t[u8Update_Record].cGrade = cBuffer[0];
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

//Delete data in record
void vDeleteRecord (void) {
	
	uint32_t u32Delete_Record_Rn = 0;
	uint8_t u8Try = MAX_TRY, u8Delete_Record = 0, u8Rollno_Invalid = 1;
	char cBuffer[6];
	
	while (u8Try != 0) {
		printf("\t Enter the student rollno to delete data : ");
		scanf(" %[^\n]",&cBuffer);
		u8Rollno_Invalid = u8ValidateRollNo(cBuffer);
		if (u8Rollno_Invalid == 2) {
			u32Delete_Record_Rn = atoi(cBuffer);
			while (student_t[u8Delete_Record].u32Roll_No != u32Delete_Record_Rn) { 
				u8Delete_Record++;
			}		
			if (u8Delete_Record==(u8Rec_Count)) {
				student_t[u8Delete_Record].u32Roll_No = 0; 
				u8Rec_Count--;
				printf("\t Students Data is Deleted Succesfully.");
			} else {
				while(u8Delete_Record < u8Rec_Count) {
					student_t[u8Delete_Record] = student_t[u8Delete_Record+1];
					u8Delete_Record++;
				}
				student_t[u8Delete_Record].u32Roll_No = 0;
				u8Rec_Count--;
				printf("\t Students Data is Deleted Succesfully.");
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

//comparison to sort the students based on rollno 
int iCompareInt (const void *pvElement1, const void *pvElement2) { 
	students_st *pcmp1_st = (students_st *)pvElement1;
    students_st *pcmp2_st = (students_st *)pvElement2;

    if (pcmp1_st->u32Roll_No < pcmp2_st->u32Roll_No) {
        return -1;  // Return -1 if you want ascending, 1 if you want descending order
	} else if (pcmp1_st->u32Roll_No > pcmp2_st->u32Roll_No) {
        return 1;   // Return 1 if you want ascending, -1 if you want descending order. 
	}
    return 0;	
}

//Sort the data based on the specified comparison function 
void vSortRecord (void) {
		qsort(student_t, u8Rec_Count, sizeof(students_st), iCompareInt);
		printf("\t Students Data has been sorted by RollNo Succesfully.");
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
uint8_t u8ValidateRollNo(char cRollNo[6]) {
	uint8_t u8Count = 0, u8Add_Record = 0;
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
		for (u8Add_Record = 0; u8Add_Record <= u8Rec_Count; u8Add_Record++) {
				if(u32RollNo == student_t[u8Add_Record].u32Roll_No) {
					return 2;	// Rollno already exists
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

/***********************************************************************
* END OF FILE
***********************************************************************/





