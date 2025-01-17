#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node *start;
};

void enqueue(struct queue *q,int data)
{
    struct node *new,*p;
    new=(struct node*) malloc(sizeof(struct node));

    new->data=data;
    new->next=NULL;

    if(q->start==NULL){
        q->start=new;
    }
    else{
        p=q->start;
        while(p->next!=NULL){
            p=p->next;
        }   
        p->next=new;
    }
}

void pop(struct queue *q){
    struct node *p;
    p=q->start;
    if(q->start==NULL){
        printf("Queue Emppty\n");
        return;
    }
    q->start=q->start->next;
    printf("Dequeued %d",p->data);
    free(p);
}

void top(struct queue *q){
    struct node *p=q->start;
    if(q->start==NULL){
        printf("Queue Emppty\n");
        return;
    }
    else{
        printf("First Element %d",p->data);
    }
}

void display(struct queue *q){
    struct node *p;
    p=q->start;
    if(q->start==NULL){
        printf("Queue Emppty\n");
        return;
    }
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

void main()
{
    int ch,data;
    struct queue q;
    q.start=NULL;

    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.First Element\n4.Display\n5.Exit\nEnter Your Choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter Element");
                    scanf("%d",&data);
                    enqueue(&q,data);
                    break;

            case 2: pop(&q);
                    break;

            case 3: top(&q);
                    break;

            case 4: display(&q);
                    break;

            default: printf("Invalid Option\n");
                     break;
                
        }
    }

}