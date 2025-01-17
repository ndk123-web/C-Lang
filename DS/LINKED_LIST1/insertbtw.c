#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void traverse(struct node *ptr)
{
    while (ptr != 0)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->link;
    }
}
struct node *atbtw(struct node *head, struct node *second, int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
   head->link=p;
   p->data=data;
   p->link=second;
    return p;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->link = second;

    second->data = 30;
    second->link = third;

    third->data = 40;
    third->link = NULL;

    traverse(head);
    second = atbtw (head, second, 20);
    printf("Newly Inserted : \n");
    traverse(head);
    return 0;
}