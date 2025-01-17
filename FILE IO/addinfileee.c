#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *ptr;
    int i;
    ptr=fopen("test.txt","w");

    int *p;
    p=(int *) malloc(3*sizeof(int));
    for(i=0;i<3;i++)
    {
        printf("Enter %d value",i);
        scanf("%d",&p[i]);
    }
    for(i=0;i<3;i++)
    {
        fprintf(ptr,"%d\n",p[i]);
    }
    fclose(ptr);
    return 0;
}