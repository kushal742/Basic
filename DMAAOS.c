//Array of structure.
#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)//for exact memory ALlocation
struct one//struct having 3 data
{
    int n;
    char ch;
    float f;
};
main()
{
    typedef struct one A1;//A1 is struct one type.
    A1 *p[2],A[2];//A is array of two which is A1 type .
    int len;
    len=sizeof(A)/sizeof(A[0]);
    printf("len of structure element=%d\n",len);
    int i;
    printf("size of A=%d\n",sizeof(A));//each structure is of 9 bytes so total 2 array of structure so 18 bytes memory allocated
    for(i=0;i<2;i++)
    {
        printf("enter data for Array A[%d]:\n",i);
        scanf("%d %c %f",&A[i].n,&A[i].ch,&A[i].f);
        printf("\nmemory address ...\nA[%d].n=%u\tA[%d].ch=%u\tA[%d].f=%u\n",i,&A[i].n,i,&A[i].ch,i,&A[i].f);
    }
    for(i=0;i<2;i++)
    {

        printf("\nA[%d].n=%d\tA[%d].ch=%c\tA[%d].f=%f\n",i,A[i].n,i,A[i].ch,i,A[i].f);
    }
    printf("size of A=%d\n",sizeof(A));
    for(i=0;i<2;i++)
    {
        p[i]=(A1*)malloc(sizeof(A1));//Dynamic memory allocated to the structure members.
        printf("enter data for Array through pointer p[%d]:\n",i);
        scanf("%d %c %f",&p[i]->n,&p[i]->ch,&p[i]->f);
        printf("\np[%d].n=%u\tp[%d].ch=%u\tp[%d].f=%u\n",i,&p[i]->n,i,&p[i]->ch,i,&p[i]->f);
    }
    for(i=0;i<2;i++)
    {
        printf("\np[%d].n=%d\tp[%d].ch=%c\tp[%d].f=%f\n",i,p[i]->n,i,p[i]->ch,i,p[i]->f);
    }
}


