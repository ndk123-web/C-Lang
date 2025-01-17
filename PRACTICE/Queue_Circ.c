#include<stdio.h>
#include<stdlib.h>
#define MAX 3

struct cqueue{
    int fr,rr,c;
    int a[MAX];
};

int isempty(struct cqueue *cq){
    if(cq->c==0)
    return 1;
    else
    return 0;
}

int enqueue(struct cqueue *cq,int ele){
    if(cq->c==MAX){
        printf("Queue Full\n");
        return -1;
    }else{
        cq->c++;
        cq->rr=(cq->rr+1)%MAX;
        cq->a[cq->rr]=ele;
    }
}

int dequeue(struct cqueue *cq){
    if(isempty(cq)){
        printf("Queue Empty\n");
        return -1;
    }else{
        cq->c--;
        int p=cq->a[cq->fr];
        cq->fr=(cq->fr+1)%MAX;
        return p;
    }
}

int top(struct cqueue *cq){
    if(isempty(cq)){
        printf("Queue Empty\n");
        return -1;
    }else{
        printf("Top %d",cq->a[cq->fr]);
    }
}

int display(struct cqueue *cq){
    if(isempty(cq)){
        printf("Queue Empty\n");
        return -1;
    }else{
        int i;
        i=cq->fr;
        while(1){
            printf("%d\t",cq->a[i]);
            if(i>cq->rr)
            break;
            i=(i+1)%MAX;
        }
    }
}

int main()
{
    int ch,ele,p;
    struct cqueue cq;
    cq.rr=MAX-1;
    cq.fr=0;
    cq.c=0;

    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Top\n4.Display\n5.Exit\nEnter Your choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element");
                    scanf("%d",&ele);
                    enqueue(&cq,ele);
                    break;

            case 2:  p=dequeue(&cq);
                    printf("Dequeue %d\n",p);
                    break;

            case 3: top(&cq);
                    break;

            case 4: display(&cq);
                    break;

            case 5: return 0;
                    break;

            default: printf("Invalid Option\n");
                     break;
        }
    }
}