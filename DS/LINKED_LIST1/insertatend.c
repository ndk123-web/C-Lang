#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void traverse(struct node *ptr)
{
    while(ptr!=0)
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->link;
    }
}

struct node *atend(struct node *third,int data)
{
    struct node *p;
    p=(struct node *) malloc(sizeof(struct node));
    p->link=NULL;
    p->data=data;
    third->link=p;
    return third;
      
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head=(struct node *) malloc(sizeof(struct node ));
     second=(struct node *) malloc(sizeof(struct node ));
    third=(struct node *) malloc(sizeof(struct node ));
         
         head->data=10;
         head->link=second;

         second->data=20;
         second->link=third;

         third->data=30;
         third->link=NULL;

         traverse(head);
        third= atend(third,40);
        printf("Newly Inserted:\n");
        traverse(head);
         return 0;
}