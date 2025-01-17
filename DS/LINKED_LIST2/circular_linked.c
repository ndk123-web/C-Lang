#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct {
    node *last;
}LL;

void insertbegin(LL *l,int data)
{
    node *new;
    new=(node *)malloc(sizeof(node));
    new->data=data;
    if(l->last==NULL)
    {
        new->next=NULL;
        l->last=new;
        return;
    }
    
}

void main()
{
    int ch,ele;
    LL l;
    l.last=NULL;

    while(1)
    {
        printf("1.Insert at Begin\n2.Insert at End\n3.Delete Begin\n4.Delete End\n");
        printf("Enter choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&ele);
                    insertbegin(&l,ele);
                    break;

            case 2: printf("Enter data");
                    scanf("%d",&ele);
                    insertend(&l,ele);
                    break;

            default : printf("Invalid choice");
                      break;
        }
    }
}