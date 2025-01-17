#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct {
    node *start;
}LL;

void insert(LL *l,int data)
{
    node *new;
    new=(node *)malloc(sizeof(node));
    if(l->start==NULL)
    {
        new->data=data;
        new->prev=NULL;
        new->next=NULL;
        l->start=new;
        return;
    }
    new->next=l->start;
    new->prev=NULL;
    new->data=data;
    l->start->prev=new;
    l->start=new;

}

void display(LL *l)
{
    node *p;
    p=l->start;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

void reverse(LL *l)
{
    node *p;
    p=l->start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->prev;
    }
}

void main()
{
    int ch,ele;
    LL l;
    l.start=NULL;

    while(1)
    {
        printf("1.Insert\n2.Display\nReverse\n");
        printf("Enter choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&ele);
                    insert(&l,ele);
                    break;

            case 2: display(&l);
                    break;

            case 3: reverse(&l);
                    break;

            default : printf("Invalid choice\n");
                      break;
        }
    }
}