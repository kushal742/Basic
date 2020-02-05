#include <stdlib.h>
#include <stdio.h>


typedef char OneByte;


//#pragma pack(1)	// char		// Working
//#pragma pack(2)	// short	// Working
//#pragma pack(4)	// int		// Default
//#pragma pack(8)	// long		// working


struct record1{
	
	OneByte charvar;
	short  shortvar;
	int  intvar;
	long longvar;
	float floatvar;
};


typedef struct record2{
	
	OneByte charvar;
	short  shortvar;
	int  intvar;
	long longvar;
	float floatvar;
	
}TestStruct;



int main()
{	
	struct record1 teststruct1;		// Normal Struct Defination
		
	TestStruct teststruct2;				// typedef Struction Defination
	
	printf("\n Program Demonstrate Structure variables with and without typedef \n");
	
	printf("\n Size of teststruct1 %ld\n", sizeof(teststruct1));
	printf("\n Address of charvar %p", &teststruct1.charvar);
	printf("\n Address of shortvar = %p", &teststruct1.shortvar);
	printf("\n Address of intvar = %p", &teststruct1.intvar);
	printf("\n Address of longvar = %p", &teststruct1.longvar);	
	printf("\n Address of floatvar = %p", &teststruct1.floatvar);
	
	printf("\n Size of Engineer %ld\n", sizeof(teststruct2));
	printf("\n Address of charvar %p", &teststruct2.charvar);
	printf("\n Address of shortvar = %p", &teststruct2.shortvar);
	printf("\n Address of intvar = %p", &teststruct2.intvar);
	printf("\n Address of longvar = %p", &teststruct2.longvar);	
	printf("\n Address of floatvar = %p", &teststruct2.floatvar);
	
	/* Writing Data to Engineer Structure */
	teststruct2.charvar = 'A';
	teststruct2.shortvar = 100;
	teststruct2.intvar = 5000;
	teststruct2.longvar = 1000000;
	teststruct2.floatvar = 10.34;
	
	printf("\n Data in Structure \n");
	printf("\n data of charvar = %c", teststruct2.charvar);
	printf("\n data of shortvar = %d", teststruct2.shortvar);
	printf("\n data of intvar = %d", teststruct2.intvar);
	printf("\n data of longvar = %ld", teststruct2.longvar);
	printf("\n data of floatvar = %f", teststruct2.floatvar);
	
	
	
	

	return 0;
}
