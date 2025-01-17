#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct  DLL{
    struct node *start;
};

void insertbegin(struct DLL *l,int data){
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    
    new->data=data;
    new->next=l->start;
    new->prev=NULL;

    if(l->start!=NULL){
        l->start->prev=new;
    }
    l->start=new;
}

void display(struct DLL *l){
    struct node *p;
    p=l->start;

    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

void insertend(struct DLL *l,int data){
    struct node *new,*p;
    new=(struct node*) malloc(sizeof(struct node));
    p=l->start;
    new->data=data;
    new->next=NULL;
    if(l->start==NULL){
        l->start=new;
        return;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new;
        new->prev=p;
    }
}

void deletebegin(struct DLL *l){
    struct node *p;
    if(l->start==NULL){
        printf("Double LL Empty\n");
        return;
    }
    else{
        p=l->start;
        l->start=l->start->next;
        free(p);
    }
}

void deleteend(struct DLL *l){
    struct node *p,*q;
    p=l->start;
    q=NULL;
    if(l->start==NULL){
        printf("Double LL Empty\n");
        return ;
    }
    else{
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        if(q==NULL){
            printf("Deleted %d\n",p->data);
            free(p);
            l->start=NULL;
        }
        else{
            printf("Deleted %d\n",p->data);
            q->next=NULL;
            free(p);
        }
    }
}

void reverse(struct DLL *l){
    struct node *p;
    p=l->start;

    while(p->next!=NULL){
        p=p->next;
    }
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->prev;
    }
}

void main()
{
    int ch,data;
    struct DLL l;
    l.start=NULL;

    while(1){
        printf("1.InsertBegin\n2.InsertEnd\n3.DeleteBeg\n4.DeleteEnd\n5.Display\n6.Reverse\n7.Exit\n");
        printf("Enter Your Choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element");
                    scanf("%d",&data);
                    insertbegin(&l,data);
                    break;

            case 2: printf("Enter Element");
                    scanf("%d",&data);
                    insertend(&l,data);
                    break;

            case 3: deletebegin(&l);
                    break;

            case 4: deleteend(&l);
                    break;

            case 5: display(&l);
                    break;

            case 6: reverse(&l);
                    break;

            default: printf("Invalid Option\n");
                     break;
        }
    }
}