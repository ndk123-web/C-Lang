#include<stdio.h>
#include<string.h>

void main()
{
    int a[2][2]={{1,2},{4,5}};
    int (*p)[2];
    p=a;

    printf("%d\n",p); 
    printf("%d\n",*p);
    printf("%d\n",*p[0]); 
    printf("%d",*(*(p+1)+1));
    printf("%d\n",*p);
    printf("%d\n",*p+1);
}