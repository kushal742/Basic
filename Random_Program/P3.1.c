/*
* Copyright (c) 2019, System Level Solutions (India) Pvt. Ltd.
*/

/*
P3.1.  Add Static variables and function in program. 
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

/***********************************************************************
* PUBLIC FUNCTIONS
**********************************************************************/
void vF1MainFunction(void)
{
	printf("\n This is file1");
	
	vFunction();
	vStaticFunction();
}

/***********************************************************************
* PRIVATE FUNCTIONS
**********************************************************************/
static void vStaticFunction(void)
{
	printf("\n\t The is file1 static function");
}
