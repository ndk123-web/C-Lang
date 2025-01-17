#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

void insertLeft(struct tree **head, int data);
void insertRight(struct tree **head, int data);

void insertLeft(struct tree **head, int data)
{
    if (*head == NULL)
    {
        *head=(struct tree*) malloc(sizeof(struct tree));
        (*head)->data = data;
        (*head)->left = NULL;
        (*head)->right = NULL;
    } 
    else if ((*head)->left == NULL)
    {
        struct tree *new;
        new = (struct tree *)malloc(sizeof(struct tree));
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        (*head)->left = new;
    }
    else
    {
        struct tree *p = *head;
        while (1)
        {
            if (p->left == NULL)
            {
                struct tree *new = (struct tree *)malloc(sizeof(struct tree));
                new->data = data;
                new->left = NULL;
                new->right = NULL;
                p->left = new;
                break;
            }
            else
            {
                printf("Current Left Subtree is occupied\n");
                printf("1.Data for right side of left subtree\n");
                printf("Continue to grow left subtree");
                int ch;
                scanf("%d", &ch);
                if (ch == 1)
                {
                    insertRight(&(p->left), data);
                    break;
                }
                else
                {
                    p = p->left;
                }
            }
        }
    }
}

void insertRight(struct tree **head, int data)
{
    if ((*head) == NULL)
    {
        (*head)->data = data;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
    else if ((*head)->right == NULL)
    {
        struct tree *new;
        new = (struct tree *)malloc(sizeof(struct tree));
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        (*head)->right = new;
    }
    else
    {
        struct tree *p = *head;
        while (1)
        {
            if (p->right == NULL)
            {
                struct tree *new = (struct tree *)malloc(sizeof(struct tree));
                new->data = data;
                new->left = NULL;
                new->right = NULL;
                p->right = new;
                break;
            }
            else
            {
                printf("Current Right Subtree is Occupied\n");
                printf("1.Data for Left side of Right subtree\n");
                printf("2.Continue to Grow Right Subtree");
                int ch;
                scanf("%d", &ch);
                if (ch == 1)
                {
                    insertLeft(&(p->right), data);
                    break;
                }
                else
                {
                    p = p->right;
                }
            }
        }
    }
}

void displayIn(struct tree *head)
{
    if (head)
    {
        displayIn(head->left);
        printf("%d ", head->data);
        displayIn(head->right);
    }
}

void displayPre(struct tree *head)
{
    if(head){
    printf("%d ", head->data);
    displayPre(head->left);
    displayPre(head->right);
}
}

void displayPost(struct tree *head)
{     if(head){
    displayPost(head->left);
    displayPost(head->right);
    printf("%d ", head->data);
}
}

int main()
{
    int ch, ele;
    struct tree *head = NULL;
    while (1)
    {
        printf("1.InsertLeft\n2.InsertRight\n3.DisplayIn\n4.DisplayPre\n5.DisplayPost\n6.Exit\n");
        printf("Enter Choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Data for Left Subtree");
            scanf("%d", &ele);
            insertLeft(&head, ele);
            break;

        case 2:
            printf("Enter Data for Right Subtree");
            scanf("%d", &ele);
            insertRight(&head, ele);
            break;

        case 3:
            displayIn(head);
            break;

        case 4:
            displayPre(head);
            break;

        case 5:
            displayPost(head);
            break;

        case 6:
            exit(0);
        }
    }
    return 0;
}