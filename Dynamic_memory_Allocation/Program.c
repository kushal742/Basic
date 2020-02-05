/*  ------------------------------------------ Program Description ------------------------------------------------  */
// Make changes to program created for 1. And add functionality of dynamic memory allocation to create structure array. 
// Implement separate function performing addition operation on member of Structure. 		// Arthmetic = Add.
// Two functions must be implemented one must work on pass by value and another must on pass by reference.


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Structure Padding 
//#pragma pack(1)	// char		// Working
//#pragma pack(2)	// short	// Working
#pragma pack(4)	// int		// Default
//#pragma pack(8)	// long		// Working


// Structure Definations 
struct AdditionStruct{

int Num1;
int Num2;
int Num3;
int Num4;
int Ans;

};


/* 
 *  Call by value
 *  This method copies the actual value of an argument into the formal parameter of the function. 
 *  In this case, changes made to the parameter inside the function have no effect on the argument.
 */
long Fun_CallByValue_AdditionOperation(int num1, int num2, int num3, int num4)
{
	return (num1+num2+num3+num4);
}


/*
 * This method copies the address of an argument into the formal parameter. 
 * Inside the function, the address is used to access the actual argument used in the call.
 * This means that changes made to the parameter affect the argument.
 */
long Fun_CallByReference_AdditionOperation(struct AdditionStruct *AdditionOperation , int StructNumber)
{
	// return (AdditionOperation[StructNumber].Num1 + AdditionOperation[StructNumber].Num2 + AdditionOperation[StructNumber].Num3 + AdditionOperation[StructNumber].Num4);
	
	AdditionOperation[StructNumber].Ans = (AdditionOperation[StructNumber].Num1 + AdditionOperation[StructNumber].Num2 + AdditionOperation[StructNumber].Num3 + AdditionOperation[StructNumber].Num4);

	return 1;
}

/*
 * main function 
 */
int main(void)
{	 
	struct AdditionStruct *StrPtr;
	
	int NumOfAdditionOperation , Index = 0, UserInputStructNo=0;
	
	long AdditionResult=0;
	
	fflush(stdin);
	
	printf("Program Demonstrate Structure Malloc Operation \n");
	
	printf("Enter No of Structure to Addition Operation = ");
	scanf("%d", &NumOfAdditionOperation);
	printf(" \n Total to Add in Structure %d", NumOfAdditionOperation);
	
	
	/*---------------------------------------------   Dynamic Memory allocation to Structure ------------------------------------------------*/
	
	StrPtr = (struct AdditionStruct *) malloc(NumOfAdditionOperation * sizeof(struct AdditionStruct));
	
	
	
	/*---------------------------------------------   Data fill By User in Structure  -------------------------------------------------------*/
	
    for(Index=0; Index<NumOfAdditionOperation; Index++)
    {
		printf("\n Enter Value for Struct %d", Index+1);
	
		printf("\n Enter Number 1 = ");
		scanf(" %d", &StrPtr[Index].Num1);
		printf("\n Enter Number 2 = ");
		scanf(" %d", &StrPtr[Index].Num2);
		printf("\n Enter Number 3 = ");
		scanf(" %d", &StrPtr[Index].Num3);
		printf("\n Enter Number 4 = ");
		scanf(" %d", &StrPtr[Index].Num4);	
	}
	
	
	printf("Data Inside  Structure \n");
    for(Index=0; Index<NumOfAdditionOperation; Index++)
    {
		printf("\n  value in Struct %d" , Index+1);
		printf("\n  Number 1 = %d \n", StrPtr[Index].Num1);
		printf("\n  Number 2 = %d \n", StrPtr[Index].Num2);
		printf("\n  Number 3 = %d \n", StrPtr[Index].Num3);
		printf("\n  Number 4 = %d \n", StrPtr[Index].Num4);
	}
	
	
	/*--------------------------------------------------- Addition operation for call by value ---------------------------------------------------*/
	
	printf(" \n\n ---------------  Call by value ----------------------\n\n");
	printf("Enter Structure Number For Addition Operation = ");
	scanf("%d", &UserInputStructNo);
	printf("UserInputStructNo %d ", UserInputStructNo);
	UserInputStructNo = UserInputStructNo - 1;
	
	if(UserInputStructNo >= NumOfAdditionOperation)
	{
		printf(" Invalid Operation");
	}
	else
	{	
		//AdditionResult = Fun_CallByValue_AdditionOperation(StrPtr[UserInputStructNo].Num1, StrPtr[UserInputStructNo].Num2, StrPtr[UserInputStructNo].Num3, StrPtr[UserInputStructNo].Num4);
		printf(" Addition Result for Structure variable %ld", AdditionResult);
		
		StrPtr[UserInputStructNo].Ans = Fun_CallByValue_AdditionOperation(StrPtr[UserInputStructNo].Num1, StrPtr[UserInputStructNo].Num2, StrPtr[UserInputStructNo].Num3, StrPtr[UserInputStructNo].Num4);
		
		printf(" Addition Result for Structure variable %d", StrPtr[UserInputStructNo].Ans);
	
	}
	
	
	/*--------------------------------------------------- Addition operation for call by reference  ---------------------------------------------------*/
	
	printf(" \n\n ---------------  Call by reference ----------------------\n\n");
	
	printf("Enter Structure Number For Addition Operation = ");
	scanf("%d", &UserInputStructNo);
	printf("UserInputStructNo %d ", UserInputStructNo);
	UserInputStructNo = UserInputStructNo - 1;
	
	if(UserInputStructNo >= NumOfAdditionOperation)
	{
		printf(" Invalid Operation");
	}
	else
	{
		//AdditionResult = Fun_CallByReference_AdditionOperation(StrPtr, UserInputStructNo);
		//printf("Addition Result for Structure variable %ld", AdditionResult);	
	
		Fun_CallByReference_AdditionOperation(StrPtr, UserInputStructNo);
		printf(" Addition Result for Structure variable %d", StrPtr[UserInputStructNo].Ans);	
		
	}
	
	
	
	free(StrPtr);

	return 0;
}
