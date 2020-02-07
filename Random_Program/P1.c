/*
* Copyright (c) 2019, System Level Solutions (India) Pvt. Ltd.
*/

/*
P1. Develop a program demonstrating various concepts of structure in C.
    Program must demonstrate:
		Structure Padding and structure alignment
		Array of Structure
		Structure variables with and without typedef

For 32bit complier
	uint8_t         1 byte 
	uint16_t	    2 bytes 
	uint32_t 		4 bytes 
	float			4 bytes
	double       	8 bytes 
	
*/
/***********************************************************************
* INCLUDES
**********************************************************************/
#include <stdio.h>
#include <stdint.h>

/***********************************************************************
* TYPES
**********************************************************************/
typedef uint8_t u8_td;
//shows structure variables with and without typedef
typedef struct {	
	u8_td var_f_u8_td;
	double var_f_d;
	uint8_t var_f_u8;	
}f_st;

uint8_t main(void) {
	
	uint8_t u8Count = 0;
	
	//shows padding
	struct c_st	{
		uint32_t var_c_u32;
		uint8_t var_c_u8;
		double var_c_d;
	};
	struct c_st c_t;
	printf("\n Size of c_st : %d \n",sizeof(c_t));
	printf ("\t Size of var_c_u32 : %d \n", sizeof(c_t.var_c_u32));
	printf ("\t Size of var_c_u8 : %d \n", sizeof(c_t.var_c_u8));
	printf("\t Size of var_c_d : %d \n",sizeof(c_t.var_c_d));

	//shows alignment
	struct d_st {	
		uint8_t var_d_u8;
		double var_d_d;
		uint32_t var_d_u32;	
	};
	struct d_st d_t;
	printf ("\n Size of d_st : %d \n", sizeof(d_t));
	printf ("\t Size of var_d_u8 : %d \n", sizeof(d_t.var_d_u8));
	printf ("\t Size of var_d_d : %d \n", sizeof(d_t.var_d_d));
	printf ("\t Size of var_d_u32 : %d \n", sizeof(d_t.var_d_u32));
	
	//shows how to avoid padding
	#pragma pack(push,1)
	struct d_nopadding_st {	
		uint8_t var_d_nopadding_u8;
		double var_d_nopadding_d;
		uint32_t var_d_nopadding_u32;	
	};
	#pragma pack(pop)
	
	struct d_nopadding_st d_nopadding_t;
	printf ("\n Size of d_nopadding_st : %d \n", sizeof(d_nopadding_t));
	printf ("\t Size of var_d_nopadding_u8 : %d \n", sizeof(d_nopadding_t.var_d_nopadding_u8));
	printf ("\t Size of var_d_nopadding_d : %d \n", sizeof(d_nopadding_t.var_d_nopadding_d));
	printf ("\t Size of var_d_nopadding_u32 : %d \n", sizeof(d_nopadding_t.var_d_nopadding_u32));

	
	
	//shows array of structure
	struct e_st{	
		uint8_t var_e_u8;
		double var_e_d;
		uint32_t var_e_u32;	
	};
	struct e_st e_t[2];
	e_t[0].var_e_u8 = 1;
	e_t[0].var_e_d = 25.11;
	e_t[0].var_e_u32 = 78;
	e_t[1].var_e_u8 = 2;
	e_t[1].var_e_d = 99.45;
	e_t[1].var_e_u32 = 759;
	printf("\n Size of e_st : %d ", sizeof(e_t)); 
	for(u8Count = 0; u8Count < 2; u8Count++) {
		printf ("\n\t Value of var_e_u8[%d] is : %d, Address of var_e_u8[%d] is : %p", u8Count, e_t[u8Count].var_e_u8, u8Count, &(e_t[u8Count].var_e_u8));
		printf ("\n\t Value of var_e_d[%d] is : %f, Address of var_e_d[%d] is : %p", u8Count, e_t[u8Count].var_e_d, u8Count, &(e_t[u8Count].var_e_d));
		printf ("\n\t Value of var_e_u32[%d] is : %d, Address of var_e_u32[%d] is : %p \n", u8Count, e_t[u8Count].var_e_u32, u8Count, &(e_t[u8Count].var_e_u32));
	}
	
	f_st f_t;
	f_t.var_f_u8_td = 3;
	f_t.var_f_d = 75.63;
	f_t.var_f_u8 = 102;
	printf ("\n Size of f_st : %d ", sizeof(f_t)); 
	printf ("\n\t Value of var_f_u8_td is : %d", f_t.var_f_u8_td);
	printf ("\n\t Value of var_f_d is : %f", f_t.var_f_d);
	printf ("\n\t Address of var_f_u8 is : %d", f_t.var_f_u8);

	return 0;	
}
