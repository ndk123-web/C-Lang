#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertbeg(struct node **head,int data){
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    new->data=data;
    new->next=*head;
    *head=new;
}

void insertend(struct node **head,int data){
    struct node *p,*new;
    new=(struct node*) malloc(sizeof(struct node));
    new->data=data;
    p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new;
    new->next=NULL;
}

void deletebeg(struct node **head){
    if(*head==NULL){
        printf("LL Empty\n");
    }else{
        struct node *p=*head;
        *head=(*head)->next;
        free(p);
    }
}

void deleteend(struct node **head){
    if(*head==NULL){
        printf("LL Empty\n");
    }else{
        struct node *p=*head;
        struct node *q=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
    }
}

void display(struct node *head){
    struct node *p;
    p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    struct node *head=NULL;
    int ch,ele;
    printf("%p",&head);
    while(1){
        printf("1.InsertBeg\n2.InsertEnd\n3.DeleteBeg\n4.DeleteEnd\n5.Display\n6.Exit\n");
        printf("Enter Choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element");
                    scanf("%d",&ele);
                    insertbeg(&head,ele);
                    break;

            case 2: printf("Enter Element");
                    scanf("%d",&ele);
                    insertend(&head,ele);
                    break;

            case 3: deletebeg(&head);
                    break;

            case 4: deleteend(&head);
                    break;

            case 5: display(head);  //sending copy of head pointer which is pointing to LL first data
                    break;

            case 6: exit(0);
        }
    }
}