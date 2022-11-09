//Array of structure.
#include<stdio.h>//Header File//comments
#pragma pack(1)//For exact memory allocation.
struct one//structure with different data.
{

    int n;
    char ch;
    float f;

};
main()
{
    typedef struct one A1;//A1 is struct one type.
    A1 A[5];//A is set of 5 array which is A1 type.

int i;
    printf("size of A=%d\n",sizeof(A));//each structure is of n bytes so total m array of structure so t bytes memory allocated

    for(i=0;i<5;i++)

    {
//entering data
        printf("enter data for Array A[%d]:\n",i);
        printf("enter number\n");
        scanf("%d",&A[i].n);
        printf("enter character\n");
        scanf(" %c",&A[i].ch);
        printf("enter the float\n");
        scanf("%f",&A[i].f);
    }

    for(i=0;i<5;i++)
    {
//printing data
        printf("A[%d].n=%d , A[%d].ch=%c , A[%d].f=%f",i,A[i].n,i,A[i].ch,i,A[i].f);
    }
}

