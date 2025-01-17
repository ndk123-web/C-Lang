#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

typedef struct {
    node *start;
}LL;

void enqueue(LL *l,int data)
{
    node *new,*p;
    p=l->start;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    if(l->start==NULL)
    {
        new->next=NULL;
        l->start=new;
        return;
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=new;
    new->next=NULL;
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

void top(LL *l)
{
    node *p;
    p=l->start;
    printf("Queue Top %d\n",p->data);
}

void dequeue(LL *l)
{
    node *p;
    p=l->start;
    printf("Dequeue %d\n",p->data);
    l->start=l->start->next;
}

void main()
{
    LL l;
    l.start=NULL;
    int ch,ele;
    while(1)
    {
        printf("1.Enqueue\n2.Display\n3.Queue Top\n4.Dequeue\n");
        printf("Enter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter Data");
                    scanf("%d",&ele);
                    enqueue(&l,ele);
                    break;

            case 2: display(&l);
                    break;

            case 3: top(&l);
                    break;

            case 4: dequeue(&l);
                    break;

            default: printf("Invalid choice");
                     break;

        }
    }
}