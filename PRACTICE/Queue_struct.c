#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct queue{
    int fr,rr;
    int a[MAX];
};

int isempty(struct queue *q){
    if(q->fr > q->rr)
    return 1;
    else
    return 0;
}

int isfull(struct queue *q){
    if(q->rr==MAX-1)
    return 1;
    else
    return 0;
}

int enqueue(struct queue *q,int ele){
    if(isfull(q)){
        printf("Queue Full\n");
    }else{
        q->rr++;
        q->a[q->rr]=ele;
    }
}

int dequeue(struct queue *q){
    if(isempty(q)){
        printf("Queue Empty\n");
    }else{
        int p=q->a[q->fr];
        q->fr++;
        return p;
    }
}

int top(struct queue *q){
    if(isempty(q)){
        printf("Queue Empty\n");
    }else{
        printf("Queue Top %d",q->a[q->fr]);
    }
}

int display(struct queue *q){
    if(isempty(q)){
        printf("Queue Empty\n");
    }else{
    for(int i=q->fr;i<=q->rr;i++){
        printf("%d\t",q->a[i]);
    }
}
}

int main()
{
    int ch,ele,i;
    struct queue q;
    q.fr=0;
    q.rr=-1;

    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Queue Top\n4.Display\n5.Exit\nEnter Choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element");
                    scanf("%d",&ele);
                    enqueue(&q,ele);
                    break;

            case 2: i=dequeue(&q);
                    printf("Popped : %d\n",i);
                    break;

            case 3: top(&q);
                    break;

            case 4: display(&q);    
                    break;

            case 5: return 0;
                    break;

            default: printf("Invalid Option\n");
                     break;     

            
        }
    }
}