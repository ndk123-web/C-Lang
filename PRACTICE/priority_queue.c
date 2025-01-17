#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct {
    int a[MAX];
    int fr,rr;
}queue;

void enqueue(queue *q,int data)
{
    if(q->fr==q->rr+1)
    printf("QUEUE FULL\n");
    else {
    q->rr++;
    q->a[q->rr]=data;
}
}

int dequeue(queue *q)
{
    int max ,pos,i;
    if(isempty(q))
    return 1 ;
    else
    {
        max=q->a[q->fr];
        pos=q->fr;
        for(i=q->fr+1;i<=q->rr;i++)
        {
            if(q->a[i]>max)
            {
                max=q->a[i];
                pos=i;
            }
        }
        for(i=pos;i<=q->rr;i++)
        q->a[i]=q->a[i+1];
        q->rr--;

        return max;
    }
}

int top(queue *q)
{
    if(isempty(q))
    return 1;
    else
    return q->a[q->fr];
}

void display(queue *q)
{
    int i;
    if(isempty(q))
    return ;
    else
    {
        i=q->fr;
        while(1)
        {
            printf("%d\n",q->a[i]);
            if(i==q->rr)
            break;

        }
    }
}

int isempty(queue *q)
{
    if(q->rr==MAX-1)
    return 1;
    else
    return 0;
}

int main()
{
     queue q;
    q.rr=-1;
    q.fr=0;
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

            case 2: printf("Dequeue %d\n",dequeue(&q));
                    break;

            case 3:
                    printf("Queue top : %d",d);
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