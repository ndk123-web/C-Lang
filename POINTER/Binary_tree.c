#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

void insertRight(struct tree **head,int data);
void insertLeft(struct tree **head,int data);

void insertLeft(struct tree **head, int data)
{
    if (*head == NULL)
    {
        *head = (struct tree *)malloc(sizeof(struct tree));
        (*head)->data = data;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
    else if ((*head)->left == NULL)
    {
        struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        (*head)->left = newNode;
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
                printf("Current Left subtree is Occupied\n");
                printf("1.Right Side of Left subtree\n");
                printf("2.Continue to grow left subtree\n");
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
    if (*head == NULL)
    {
        *head = (struct tree *)malloc(sizeof(struct tree));
        (*head)->data = data;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
    else if ((*head)->right == NULL)
    {
        struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        (*head)->right = newNode;
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
                printf("Current Right Subtree is occupied\n");
                printf("1.Left Side of Right Subtree\n");
                printf("2.Continue to Grow Right subtree");
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

void display(struct tree *head)
{
    if (head != NULL)
    {
        display(head->left);
        printf("%d ", head->data);
        display(head->right);
    }
}

void displaypre(struct tree *head)
{
    if (head != NULL)
    {
        printf("%d ", head->data);
        displaypre(head->left);
        displaypre(head->right);
    }
}

void displaypost(struct tree *head)
{
    if (head != NULL)
    {
        displaypost(head->left);
        displaypost(head->right);
        printf("%d ", head->data);
    }
}

int main()
{
    int ch, ele;
    struct tree *head = NULL;

    while (1)
    {
        printf("\n1. Insert Left\n2. Insert Right\n3. Display\n4. DisplayPRE\n5. DisplayPOST\n6.Exit\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Data for left: ");
            scanf("%d", &ele);
            insertLeft(&head, ele);
            break;
        case 2:
            printf("Enter Data for right: ");
            scanf("%d", &ele);
            insertRight(&head, ele);
            break;
        case 3:
            printf("Tree elements in In-Order: ");
            display(head);
            printf("\n");
            break;

        case 4:
            printf("Tree elements in Pre-Order : ");
            displaypre(head);
            break;

        case 5:
            printf("Tree elements in Post-Order : ");
            displaypost(head);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
