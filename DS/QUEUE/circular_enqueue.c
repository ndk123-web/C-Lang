#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct {
    int fr,rr,c;
    int a[MAX];
}queue;

int isempty(queue *q)
{
    if(q->c==0)
    return 1;
    else
    return 0;
}

int frontqueue(queue *q)
{
    if (isempty(q))
    {
        printf("UNDERFLOW\n");
        return 0;
    }
    else
    return q->a[q->fr];
}

int enqueue(queue *q,int ele)
{
    if(q->c==MAX)
    {
        printf("OVERFLOW\n");
        return 0;
    }
    else
    {
        q->c++;
        q->rr=(q->rr+1)%MAX;
        q->a[q->rr]=ele;
    }
}

int denqueue(queue *q)
{
    int ele;
    if (isempty(q))
    {
        printf("UNDERFLOW\n");
        return 0;
    }
    else
    {
        q->c--;
        ele=q->a[q->fr];
        q->fr=(q->fr+1)%MAX;
        return ele;
    }
}

void display(queue *q)
{
    int i;
    i=q->fr;
    while(1)
    {
        printf("%d\n",q->a[i]);
        if(i==q->rr)
        break;
        i=(i+1)%MAX;
    }
}

int main()
{
    queue q;
    q.rr=MAX-1;
    q.fr=0;
    q.c=0;
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
                    printf("Denque : %d\n",ele);
                    break;

            case 3: ele=frontqueue(&q);
                    printf("Front : %d\n",ele);
                    break;

            case 4: display(&q);
                    break;

            case 5: printf("Thanku !!");
                    return 0;
                    break;
        }
    }
    return 0;
}