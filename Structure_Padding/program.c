/*  ----------------  Structure Padding  -----------------  */

#include <stdlib.h>
#include <stdio.h>


//#pragma pack(1)	// char		// Working
//#pragma pack(2)	// short	// Working
//#pragma pack(4)	// int		// Default
//#pragma pack(8)	// long			// Working



/* Structure Declaration */

#pragma pack(push,2)
struct record1{

	char charvar;
	short shortvar;
	int intvar;
	long longvar;
	float floatvar;
};
#pragma pack(pop)



struct record2{
	
	char charvar;
	short shortvar;
	int intvar;
	long longvar;
	float floatvar;
};


/* main Function */
int main(void)
{	
	struct record1 teststruct1;
	struct record2 teststruct2;
	
	printf(" Program Demonstrate Struct Padding \n");
	printf("Size of teststruct1 %ld\n", sizeof(teststruct1));

	printf("\n Size of charvar = %ld Address of charvar = %p", sizeof(teststruct1.charvar) , &teststruct1.charvar);
	printf("\n Size of shortvar = %ld Address of shortvar = %p", sizeof(teststruct1.shortvar) , &teststruct1.shortvar);
	printf("\n Size of intvar = %ld Address of intvar %p", sizeof(teststruct1.intvar) , &teststruct1.intvar);
	printf("\n Size of longvar = %ld Address of longvar = %p", sizeof(teststruct1.longvar) , &teststruct1.longvar);
	printf("\n Size of floatvar = %ld Address of floatvar = %p", sizeof(teststruct1.floatvar) , &teststruct1.floatvar);
	
	printf(" Program Demonstrate Struct Padding \n");
	printf("Size of teststruct1 %ld\n", sizeof(teststruct2));

	printf("\n Size of charvar = %ld Address of charvar = %p", sizeof(teststruct2.charvar) , &teststruct2.charvar);
	printf("\n Size of shortvar = %ld Address of shortvar = %p", sizeof(teststruct2.shortvar) , &teststruct2.shortvar);
	printf("\n Size of intvar = %ld Address of intvar %p", sizeof(teststruct2.intvar) , &teststruct2.intvar);
	printf("\n Size of longvar = %ld Address of longvar = %p", sizeof(teststruct2.longvar) , &teststruct2.longvar);
	printf("\n Size of floatvar = %ld Address of floatvar = %p", sizeof(teststruct2.floatvar) , &teststruct2.floatvar);
	
	
	return 0;
}
