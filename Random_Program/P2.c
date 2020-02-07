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

/***********************************************************************
* GLOBAL VARIABLES
**********************************************************************/
struct values_st {	
	uint8_t u8v1;
	uint8_t u8v2;
};

/***********************************************************************
* PUBLIC FUNCTION PROTOTYPES
**********************************************************************/
void vCallByValue (uint8_t u8data1, uint8_t u8data2);
void vCallByReference (uint8_t *pu8data1, uint8_t *pu8data2);

uint8_t main(void) {
	
	uint8_t u8Count = 0;

	struct values_st value_t[2];
	
	value_t[0].u8v1 = 25;
	value_t[0].u8v2 = 10;
	
	value_t[1].u8v1 = 50;
	value_t[1].u8v2 = (uint8_t)260;

	printf (" Displaying Information:\n");
	for (u8Count = 0; u8Count < 2; u8Count++) {
		printf("\t Values are v1: %d\t v2: %d\n", value_t[u8Count].u8v1, value_t[u8Count].u8v2);
	}
	
	printf("\n Call by Value");
	vCallByValue (value_t[0].u8v1, value_t[0].u8v2);
	printf("\n\tValues in main v1: %d\t v2: %d\n", value_t[0].u8v1, value_t[0].u8v2);

  
 	printf("\n Call by Reference");
	vCallByReference (&value_t[1].u8v1, &value_t[1].u8v2);
	printf("\n\tValues in main v1: %d\t v2: %d\n", value_t[1].u8v1, value_t[1].u8v2);
	
	return 0;
}

/***********************************************************************
* PUBLIC FUNCTIONS
**********************************************************************/
void vCallByValue (uint8_t u8data1, uint8_t u8data2) {
	u8data1 = u8data1 + 10;
	u8data2 = u8data2 + 10;
	printf("\n\tValues in function data1: %d \t data2: %d", u8data1, u8data2); 
}

void vCallByReference (uint8_t *pu8data1, uint8_t *pu8data2) {
	*pu8data1 = *pu8data1 + 10;
	*pu8data2 = *pu8data2 + 10;
	printf("\n\tValues in function data1: %d \t data2: %d", *pu8data1, *pu8data2); 
}

/***********************************************************************
* END OF FILE
***********************************************************************/
