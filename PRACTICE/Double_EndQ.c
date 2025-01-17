#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct queue {
    int fr,rr;
    int a[MAX];
};

void enqueueright(struct queue *q,int ele){
    if(q->rr==MAX-1){
        printf("Overflow\n");
        return;
    }else{
        q->rr++;
        q->a[q->rr]=ele;
    }
}

void enqueueleft(struct queue *q,int ele){
    if(q->fr==-1){
        printf("Overflow\n");
        return;
    }else{
        q->a[q->fr]=ele;
        q->fr++;
    }
}

void display(struct queue *q){
    for(int i=q->fr;i<=q->rr;i++){
        printf("%d\t",q->a[i]);
    }
    printf("\n");
}

void dequeueright(struct queue *q){
    if(q->fr==q->rr){
        printf("Underflow\n");
        return;
    }else{
        int ele=q->a[q->rr];
        q->rr--;
    }
}

void dequeueleft(struct queue *q){
    if(q->fr==q->rr){
        printf("Underflow\n");
        return;
    }else{
        int ele=q->a[q->fr];
        q->fr++;
    }
}

void main(){
    int ch,ele;
    struct queue q;
    q.fr=MAX/2;
    q.rr=MAX/2;

    while(1){
        printf("1.EnqueueRight\n2.EnqueueLeft\n3.DequeueRight\n4.DequeueLeft\n5.Display\n");
        printf("Enter Your choice");
        scanf("%d",&ch);

        switch(ch){
        case 1: printf("Enter Element");
                scanf("%d",&ele);
                enqueueright(&q,ele);
                break;

        case 2: printf("Enter Element");
                scanf("%d",&ele);
                enqueueleft(&q,ele);
                break;

        case 3: dequeueright(&q);   
                break;

        case 4: dequeueleft(&q);
                break;

        case 5: display(&q);
                break;

        default: printf("Invalid Option\n");
                 break;

        }
    }

}