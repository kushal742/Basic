/*
* Copyright (c) 2019, System Level Solutions (India) Pvt. Ltd.
*/

/*
P3. Add Static variables and function in program. 
	Modifications in program must demonstrate usage of static variable, static func, scope and life of static variable and func. 
*/

/***********************************************************************
* INCLUDES
**********************************************************************/
#include <stdio.h>
#include <stdint.h>

/***********************************************************************
* PUBLIC FUNCTION PROTOTYPES
**********************************************************************/
void vF1MainFunction(void);
void vFunction(void);

/***********************************************************************
* PRIVATE FUNCTION PROTOTYPES
**********************************************************************/
static void vStaticFunction(void);

uint8_t main(void) {
	printf("\n This is main file");
	uint8_t u8count=0;
	
	for(u8count = 0; u8count < 3; u8count++) {
		vFunction();
		vStaticFunction();
	}

	vF1MainFunction();
	
	return 0;
}

/***********************************************************************
* PUBLIC FUNCTIONS
**********************************************************************/
void vFunction(void) {
	static uint8_t u8StatVarFunc = 0;
	uint8_t u8VarFunc = 0;
	u8StatVarFunc++;
	u8VarFunc++;
	printf("\n\t The value of static variable of function is %d",u8StatVarFunc);
	printf("\n\t The value of variable of function is %d",u8VarFunc);
}

/***********************************************************************
* PRIVATE FUNCTIONS
**********************************************************************/
static void vStaticFunction(void)
{
	printf ("\n\t The is static function");
}

/***********************************************************************
* END OF FILE
***********************************************************************/


