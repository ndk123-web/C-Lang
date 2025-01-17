#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

    void push(struct node **head1,struct node **head2,int data1,int data2){
    struct node *new1,*new2;
    new1=(struct node*) malloc(sizeof(struct node));
    new2=(struct node*) malloc(sizeof(struct node));
    new1->data=data1;
    new2->data=data2;

    new1->next=*head1;
    *head1=new1;
    new2->next=*head2;
    *head2=new2;

}

void displayans(struct node *head){
    struct node *p=head;
    printf("\n\nADD 2 LL is \n\n");
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

void display(struct node *head1,struct node *head2){
    struct node *p=head1,*q=head2;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n"); 
    while(q!=NULL){
        printf("%d\t",q->data);
        q=q->next;
    }
}

void reverseadd(struct node *head1,struct  node *head2){
        int carry=0,digit,digit1,digit2,sum=0;
        struct node *newnode,*dummy,*tail; 
        dummy=(struct node*) malloc(sizeof(struct node));
        tail=dummy;
        while(head1!=NULL ||  head2!=NULL || carry!=0 ){
            digit1=(head1!=NULL) ? head1->data : 0;
            digit2=(head2!=NULL) ? head2->data : 0;
            sum=digit1+digit2+carry;
            carry=sum/10;
            digit=sum%10;

            newnode=(struct node*) malloc(sizeof(struct node));
            newnode->data=digit;
            newnode->next=NULL;
            tail->next=newnode;
            tail=tail->next;

            (head1!=NULL) ? head1=head1->next : NULL;
            (head2!=NULL) ? head2=head2->next : NULL;
        }
        struct node *result=dummy->next;
        free(dummy);
        displayans(result);
}

int  main()
{
    int ch,ele;
    struct node *head1,*head2;
    head1=NULL;
    head2=NULL;
    push(&head1,&head2,5,3);
    push(&head1,&head2,6,4);
    push(&head1,&head2,2,3);
    display(head1,head2);
    reverseadd(head1,head2);
    return 0;
}