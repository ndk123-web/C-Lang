#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct {
    int fr,rr;
    int a[MAX];
}queue;

int enqueue(queue *q,int ele)
{
    if(q->rr==MAX-1){
    printf("OVERFLOW\n");
    return 0;
}
else
    {
        q->rr++;
        q->a[q->rr]=ele;
    }
}

int denqueue(queue *q)
{
    int max,i,pos;
    if(q->fr>q->rr){
    printf("UNDERFLOW\n");
    return -1;
    }
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

int frontqueue(queue *q)
{
    if(isempty(q))
    printf("UNDERFLOW\n");
    else
    return q->a[q->fr];
}

int isempty(queue *q)
{
    if(q->rr==-1)
    return -1;
    else
    return 0;
}

void display(queue *q)
{
    int i;
    if(isempty(q))
    printf("UNDEFLOW\n");
    else
    {
        for(i=q->fr;i<=q->rr;i++)
        {
            printf("%d\n",q->a[i]);
        }
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