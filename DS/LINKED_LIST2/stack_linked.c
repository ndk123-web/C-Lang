#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct {
    node *start;
}DLL;

void main()
{
    DLL l;
    l.start=NULL;
    int ch,ele;

    while(1)
    {
        printf("1.insertatbegin\n")
    }
}