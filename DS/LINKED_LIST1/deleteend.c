#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};
void traverse(struct node *ptr);

struct node *atend(struct node *head)
{
    struct node *p=head;
    struct node *q=head->link;
    while(q->link!=NULL)
    {
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node*) malloc(sizeof(struct node));
    second=(struct node*) malloc(sizeof(struct node));
    third=(struct node*) malloc(sizeof(struct node));
    fourth=(struct node*) malloc(sizeof(struct node));
      
       head->data=5;
       head->link=second;

       second->data=6;
       second->link=third;

       third->data=7;
       third->link=fourth;

       fourth->data=8;
       fourth->link=NULL;

       traverse(head);
       head=atend(head);
       printf("At end : \n");
       traverse(head);
       return 0;
}

 void traverse(struct node *ptr)
 {
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->link;
    }
 }

