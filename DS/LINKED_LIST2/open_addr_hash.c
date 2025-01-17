#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct node
{
    int data;
    struct node *next;
};

struct hsh
{
    struct node *start;
};

struct hash
{
    int hash[MAX] = {0};
    int loc;
    struct node *location;
};

void insert(struct hash *h, int data)
{
    h->loc = data % MAX;
    struct node *new, *p;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    if (h->hash[h->loc] != 0)
    {
        h->location = h->loc;
        p = h->location;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
        new->next = NULL;
        }
    h->hash[h->loc] = data;
}

void search(struct hash *h)
{
}

void main()
{
    int ch, ele;
    struct hash h;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n");
        printf("Enter Choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Data");
            scanf("%d", &ele);
            insert(&h, ele);
            break;

        
        }
    }
}