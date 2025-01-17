#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int *p=(int*) malloc(sizeof(int));
    *p=10;
    printf("Address in Heap : %p\nData On Address of Heap : %d\n",p,*p);
    return 0;
}