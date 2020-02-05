/*  -----------------   Program Demonstrate Array of Structure ---------------------*/
#include <stdlib.h>
#include <stdio.h>


// MACRO Definations
#define ARR_SIZE  10




struct record1{

	char charvar;
	int intvar;
	long longvar;
	float floatvar;
};

/* ----------------  Normal Static Array ---------------------------*/

int main(void)
{	
	struct record1 teststruct1[ARR_SIZE];
	
	int Index;
	
	printf("\n Program Demonstrate Array of Structure \n");
	
	for(Index=0; Index<ARR_SIZE; Index++)
	{
		printf("\n Size of teststruct1 %ld\n", sizeof(teststruct1[Index]));
		
		printf("\n Address of i %p", &teststruct1[Index].charvar);
		printf(" \n Address of j = %p", &teststruct1[Index].intvar);
		printf(" \n Address of k = %p", &teststruct1[Index].longvar);
		printf(" \n Address of l = %p", &teststruct1[Index].floatvar);	
	}

	return 0;
}




/* --------------  Using Array Dynamic ------------------------*/
/*
int main(void)
{	
	struct record1 *teststruct1;
	int Index;
	
	teststruct1 = (struct record1*)malloc(ARR_SIZE * sizeof(struct record1));
	
	printf("\n Program Demonstrate Array of Structure \n");
	
	for(Index=0; Index<ARR_SIZE; Index++)
	{
		printf("\n Size of teststruct1 %ld\n", sizeof(teststruct1[Index]));
		
		printf("\n Address of i %p", &teststruct1[Index].charvar);
		printf(" \n Address of j = %p", &teststruct1[Index].intvar);
		printf(" \n Address of k = %p", &teststruct1[Index].longvar);
		printf(" \n Address of l = %p", &teststruct1[Index].floatvar);	
	}
	
	

	return 0;
}*/
