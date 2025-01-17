#include<stdio.h>
#include<stdlib.h>

void main()
{
    int x=5;
    int *p=&x;
    int **p1=&p;
    int ***p2=&p1;

    *p=20;           //dereference ho rha hai p (p=&x) x ke location pe jaake accesss kr rha hai data 
    printf("%d\n",x);   

    **p1=30;
    printf("%d\n",x);

    ***p2=40;
     printf("%d\n",x);

}