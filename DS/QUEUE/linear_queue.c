#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct {
    int rr;
    int fr;
    int a[MAX];
}queue;

int isempty(queue *q)
{
    if(q->rr+1==q->fr)
    return 1;
    else
    return 0;
}

int isfull(queue *q)
{
    if(q->rr==MAX-1)
    return 1;
    else
    return 0;
}

void enqueue(queue *q,int ele)
{
    if(isfull(q))
    {
        printf("OVERFLOW\n");
        return;
    }
    q->rr++;
    q->a[q->rr]=ele;
}

int denqueue(queue *q)
{
    int ele;
    if(isempty(q))
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    {
    ele=q->a[q->fr];
    q->fr++;
    return ele;
    }
}   

int frontqueue(queue *q)
{
    if(isempty(q))
    {
    printf("UNDEFLOW\n");
    return ;
    }
    return q->a[q->fr];
}

void display(queue *q)
{
    int i;
    for(i=q->fr;i<=q->rr;i++)
    {
        printf("%d",q->a[i]);
    }
}

int main()
{
    queue q;
    q.rr=-1;
    q.fr=0;
    int ch,ele;
    while(1)
    {
        printf("1.Enqueu\n2.Denque\n3.queuefront\n4.display\n5.Exit\n");
        printf("Enter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data :");
                    scanf("%d",&ele);
                    enqueue(&q,ele);
                    break;

            case 2: ele=denqueue(&q);
                    if(ele!=-1)
                    printf("Denque : %d",ele);
                    break;

            case 3: ele=frontqueue(&q);
                    printf("Front : %d",ele);
                    break;

            case 4: display(&q);
                    break;

            case 5: printf("Thanku !!");
                    return 0;
                    break;
        }
    }
}