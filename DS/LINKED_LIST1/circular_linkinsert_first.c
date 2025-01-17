#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->link;
    } while (ptr != head);
}

struct node *insertbegin(struct node *head, int data)
{
    struct node *ptr;
    struct node *p;
    ptr=(struct node *) malloc(sizeof(struct node) );
    ptr->data=data;
    p=head->link;
    
    while(p->link!=head)
    {
        p=p->link;
    }
     ptr->link=head;
     p->link=ptr;
     head=ptr;
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 20;
    head->link = second;

    second->data = 30;
    second->link = third;

    third->data = 40;
    third->link = fourth;

    fourth->data = 50;
    fourth->link = head;

    traverse(head);
    head = insertbegin(head, 10);
    printf("After inserted : \n");
    traverse(head);
    return 0;
}