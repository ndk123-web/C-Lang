#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct {
    int a[MAX];
    int fr,rr;
}queue ;

void enqueue(queue *q,int ele)
{
    if(q->rr==MAX-1)
    printf("Queue Full");
    else
    {
        q->rr++;
        q->a[q->rr]=ele;
    }
}

int dequeue(queue *q)
{
    int x;
    if(isempty(&q))
    return 0;
    else
    {
        x=q->a[q->fr];
        q->fr++;
        return x;
    }
}

int top(queue *q)
{
    if(isempty(&q))
    printf("Queue Empty");
    else
    return q->a[q->fr];
}

void display(queue *q)
{
    int i;
    for(i=q->fr;i<=q->rr;i++)
    printf("%d\n",q->a[i]);
}

int isempty(queue *q)
{
    if(q->fr==q->rr+1)
    return 1;
    else
    return 0;
}

int main()
{
    queue q;
    q.fr=0;
    q.rr=-1;
    int ele,ch;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.top\n4.display\n5.exit\n");
        printf("Enter choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&ele);
                    enqueue(&q,ele);
                    break;

            case 2: printf("Dequeue : %d\n",dequeue(&q));
                    break;

            case 3: printf("Queue top : %d",top(&q));
                    break;

            case 4: display(&q);
                    break;

            case 5: return 0;
            default: printf("Invalid choice ");
                    break;
        }
    }
}