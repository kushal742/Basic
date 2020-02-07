/*
* Copyright (c) 2019, System Level Solutions (India) Pvt. Ltd.
*/

/*
P2. Develop following functionality:
    	And add functionality of dynamic memory allocation to create structure array.
    	Demonstrating the concept of call by value and call by reference.
    	Ex. Pass structure to the func and perform the operation on it (structure member) and print values in main func.

*/

/***********************************************************************
* INCLUDES
**********************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>		// It has malloc definition

/***********************************************************************
* TYPES
**********************************************************************/
typedef struct {	
	uint8_t u8v1;
	uint8_t u8v2;
}values_st;

/***********************************************************************
* PUBLIC FUNCTION PROTOTYPES
**********************************************************************/
void vStructToFuncCallByValue (values_st value_t);
void vStructToFuncCallByReference (values_st *pvalue_t);

uint8_t main(void) {

	uint8_t u8Count = 0;
	
	values_st *pvalues_st = (values_st*) malloc (2 * sizeof(values_st));
	
	if (pvalues_st == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    }  else {     
	// Memory has been successfully allocated 
    printf("Memory successfully allocated using malloc.\n"); 
  	
	pvalues_st->u8v1 = 25;
	pvalues_st->u8v2 = 10;
	
	(pvalues_st+1)->u8v1 = 50;
	(pvalues_st+1)->u8v2 = (uint8_t)260;
	
	printf(" Displaying Information:\n");
	for (u8Count = 0; u8Count < 2; u8Count++) {
		printf("\t Values are v1: %d\t v2: %d\n", (pvalues_st+u8Count)->u8v1, (pvalues_st+u8Count)->u8v2);
	}
		
	
	printf("\n Structure to function call by Value");
	vStructToFuncCallByValue(*(pvalues_st+0));
	printf("\n\tValues in main v1: %d\t v2: %d", (pvalues_st+0)->u8v1, (pvalues_st+0)->u8v2);
	
	
	printf ("\n Structure to function call by Reference");
	vStructToFuncCallByReference(pvalues_st+1);
	printf("\n\tValues in main v1: %d\t v2: %d", (pvalues_st+1)->u8v1, (pvalues_st+1)->u8v2);
	
	
	free(pvalues_st);

	return 0;
	}
}

/***********************************************************************
* PUBLIC FUNCTIONS
**********************************************************************/
void vStructToFuncCallByValue(values_st value_t) {
	value_t.u8v1 = value_t.u8v1 + 10;
	value_t.u8v2 = value_t.u8v2 + 10;
	printf ("\n\tValues in function data1: %d\t data2: %d", value_t.u8v1, value_t.u8v2);
}

void vStructToFuncCallByReference(values_st *pvalue_t){
	pvalue_t->u8v1 = pvalue_t->u8v1 + 10;
	pvalue_t->u8v2 = pvalue_t->u8v2 + 10;
	printf ("\n\tValues in function data1: %d\t data2: %d", pvalue_t->u8v1, pvalue_t->u8v2);
}

/***********************************************************************
* END OF FILE
***********************************************************************/



