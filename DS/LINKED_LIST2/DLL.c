#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct {
    node *start;
}LL;

void insertbegin(LL *l,int data)
{
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    l->start=new;
}

void display(LL *l)
{
    node *p,*q;
    if(l->start==NULL)
    {
        printf("Linked Empty");
        return;
    }
    p=l->start;
    while(p->next!=NULL)
    {
        printf("%d\t",p->data);
    }
}

void main()
{
    int ch,data;
    LL l;
    l.start=NULL;
    while(1)
    {
        printf("1.Insert at beggining\n2.Insert at End\n3.Delete at begin\n4.Delete at End\n5.Reverse\n6.sort\n7.Display\n");
        printf("Enter choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&data);
                    insertbegin(&l,data);
                    break;

            case 7: display(&l);
                    break;
        }
    }
}