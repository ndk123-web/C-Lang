#include<stdio.h>
#define MAX 5

struct queue{
    int a[MAX];
    int rr,fr;
    int c;
};

int isempty(struct queue *q)
{
    if(q->c==0)
    return 1;
    else
    return 0;
}

void enqueue(struct queue *q,int data)
{
    if(q->c==MAX)
    printf("Queue Full");
    else
    {
        q->c++;
        q->rr=(q->rr+1)%MAX;
        q->a[q->rr]=data;
    }
}

int dequeue(struct queue *q)
{
    int x;
    if(isempty(q))
    return -1;
    else
    {
        q->c--;
        x=q->a[q->fr];
        q->fr=(q->fr+1)%MAX;
        return x;
    }
}

int top(struct queue *q)
{
    if(isempty(q))
    return -1;
    else
    return q->a[q->fr];
}



int display(struct queue *q)
{
    int i,count;
    i=q->fr;
    count=q->c;
    while(count>0)
    {
        printf("%d\n",q->a[i]);
        i=(i+1)%MAX;
        count--;
    }
}



int main()
{
    struct queue q;
    q.rr=MAX-1;
    q.fr=0;
    q.c=0;
    int d,ch,data;

    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.Queue top\n4.display\n5.exit\n");
        printf("Enter choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&data);
                    enqueue(&q,data);
                    break;

            case 2: d=dequeue(&q);  
                    if(d==-1)
                    printf("QUEUE EMPTY");
                    else
                    printf("Dequeue %d\n",dequeue(&q));
                    break;

            case 3: d=top(&q);
                    if(d==-1)
                    printf("QUEUE EMPTY");
                    else
                    printf("Queue top : %d",top(&q));
                    break;

            case 4: display(&q);
                    break;

            case 5: return 0;
                    break;

            default: printf("Invalid choice");
                    break;
        }       

    }
}