#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct pqueue{
    int a[MAX];
    int fr,rr;
};

int isempty(struct pqueue *q){
    if(q->fr==q->rr+1)
    return 1;
    else
    return 0;
}

int isfull(struct pqueue *q){
    if(q->rr==MAX-1)
    return 1;
    else
    return 0;
}

int enqueue(struct pqueue *q,int ele){
    if(isfull(q)){
        printf("Queue Full\n");
        return -1;
    }else{
        q->rr++;
        q->a[q->rr]=ele;
    }
}

int dequeue(struct pqueue *q){
    int max,pos;
    if(isempty(q)){
        printf("Queue Empty\n");
        return -1;
    }else{
        max=q->a[q->fr];
        pos=q->fr;
        for(int i=q->fr+1;i<=q->rr;i++){
            if(q->a[i]>max){
                max=q->a[i];
                pos=i;
            }
        }
        for(int i=pos;i<=q->rr;i++){
            q->a[i]=q->a[i+1];
        }
        q->rr--;
    }
    return max;
}

int top(struct pqueue *q){
    if(isempty(q)){
        printf("Queue Empty\n");
        return -1;
    }else{
        printf("Top Element %d\n",q->a[q->fr]);
    }
}

int display(struct pqueue *q){
    if(isempty(q)){
        printf("Queue Empty\n");
        return -1;
    }else{
        for(int i=q->fr;i<=q->rr;i++){
            printf("%d\t",q->a[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct pqueue q;
    q.fr=0;
    q.rr=-1;
    int ch,ele;

    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Top\n4.Display\n5.Exit\nEnter choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element");    
                    scanf("%d",&ele);
                    enqueue(&q,ele);
                    break;

            case 2: printf("Dequeue %d\n",dequeue(&q));
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