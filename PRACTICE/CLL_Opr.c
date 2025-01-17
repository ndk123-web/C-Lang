#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct CLL{
    struct node *start;
};

void insertbegin(struct CLL *c,int ele){
    struct node *new,*p;
    new=(struct node*) malloc(sizeof(struct node));
    new->data=ele;
    
    if(c->start==NULL){
        c->start=new;
        new->next=new;
        return;
    }
    else{
        p=c->start;
        while(p->next!=c->start){
            p=p->next;
        }
        p->next=new;
        new->next=c->start;
        c->start=new;
    }
}

void display(struct CLL *c){
    if (c->start == NULL) {
        printf("Circular Linked List is Empty\n");
        return;
    }

    struct node *p = c->start;
    printf("%d\t", p->data);
    p = p->next;
    while(p != c->start){
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}


void insertend(struct CLL *c,int ele){
    struct node *new,*p;
    new=(struct node*) malloc(sizeof(struct node));
    new->data=ele;

    if(c->start==NULL){
        c->start=new;
        new->next=new;
        return ;
    }
    else{
        p=c->start;
        while(p->next!=c->start){
            p=p->next;
        }
        p->next=new;
        new->next=c->start;
    }
}

void deletebegin(struct CLL *c){
    struct node *p;
    p=c->start;
    if(c->start==NULL){
        printf("Circular LL Empty\n");
        return;
    }
    else
    {
        printf("Deleted %d",p->data);
        while(p->next!=c->start){
            p=p->next;
        }
        p->next=c->start->next;

        struct node *temp;
        temp=c->start;
        c->start=c->start->next;
        free(temp);
    }
}

void deleteend(struct CLL *c){
    struct node *p,*q;
    p=c->start;
    q=NULL;

    if(c->start==NULL){
        printf("Circular LL Empty\n");
        return;
    }
    else{
        while(p->next!=c->start){
            q=p;
            p=p->next;
        }
        printf("Deleted %d",p->data);
        q->next=c->start;
        free(p);
    }
}

void main()
{
    int ch,ele;
    struct CLL c;
    c.start=NULL;

    while(1){
        printf("1.InsertBeg\n2.InsertEnd\n3.DeleteBegin\n4.DeleteEnd\n5.Display\n");
        printf("Enter Choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element");
                    scanf("%d",&ele);
                    insertbegin(&c,ele);
                    break;

            case 2: printf("Enter Element");
                    scanf("%d",&ele);
                    insertend(&c,ele);
                    break;

            case 3: deletebegin(&c);
                    break;

            case 4: deleteend(&c);
                    break;

            case 5: display(&c);
                    break;

            default: printf("Invalid Option\n");
                     break;
        }
    }
    
}