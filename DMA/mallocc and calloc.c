#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *ptr;
    int n,c;
    printf("Enter size of n and c");
    scanf("%d %d",&n,&c);

    ptr=(int * ) malloc(n*sizeof(int));
    printf("Using malloc\n");
    for(int i=0;i<n;i++)
    {
        printf(" %d \n"&ptr[i]);
    }
    free(ptr);
    ptr=(int *) calloc(c,sizeof(int));
    printf("Using calloc \n");
    for(int i=0;i<c;i++)
    {
        printf("%d\n",&ptr[i]);
    }


}