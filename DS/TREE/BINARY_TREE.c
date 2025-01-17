#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

void insertLeft(struct tree **head,int data){
    if(*head==NULL){
       *head = (struct tree *)malloc(sizeof(struct tree));
        (*head)->data=data; 
        (*head)->left=NULL;
        (*head)->right=NULL;  
    }else if((*head)->left==NULL){
        struct tree *new=(struct tree*) malloc(sizeof(struct tree));
        new->data=data;
        new->left=NULL;
        new->right=NULL;
        (*head)->left=new;
    }else{
        insertLeft(&(*head)->left,data);
    }
}

void insertRight(struct tree **head,int data){
    if(head==NULL){
        *head = (struct tree*)malloc(sizeof(struct tree));
        (*head)->data=data;
        (*head)->left=NULL;
        (*head)->right=NULL;
    }else if((*head)->right==NULL){
        struct tree *new=(struct tree*) malloc(sizeof(struct tree));
        new->data=data;
        new->left=NULL;
        new->right=NULL;
        (*head)->right=new;
    }else{
        insertRight(&(*head)->right,data);
    }
}

void display(struct tree *head){
    if(head!=NULL){
        display(head->left);
        printf("%d ",head->data);
        display(head->right);
    }
}

int main()
{
    int ch,ele;
    struct tree *head=NULL;

    while(1){
        printf("1.InsertLeft\n2.InsertRight\n3.Display\nExit\nEnter Choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element in Left");
                    scanf("%d",&ele);
                    insertLeft(&head,ele);
                    break;

            case 2: printf("Enter Element in Right");
                    scanf("%d",&ele);
                    insertRight(&head,ele);
                    break;

            case 3: display(head);
                    break;

            case 4: exit(0);
        }
    }
    return 0;
}