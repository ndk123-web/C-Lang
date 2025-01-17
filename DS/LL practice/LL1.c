#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **head,int data){
    struct node *new=(struct node*) malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(!(*head)){
        *head=new;
    }else{
        new->next=*head;
        *head=new;
    }
}

void display(struct node *head){
    if(head){
        struct node *p=head;
        while(p!=NULL){
            printf("%d ", p->data );
            p=p->next;
        }
    }
}

void reverse(struct node *head){
    struct node *new;
    if(head==NULL){
        return;
    }else{
        reverse(head->next);
        printf("%d ",head->data);
    }
}

void main()
{
    struct node *head=NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);

    display(head);
    printf("\n");
    reverse(head);
}