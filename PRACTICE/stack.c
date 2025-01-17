#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct {
    int top;
    int a[MAX];
}stack;

int isempty(stack *s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

int isfull(stack *s)
{
    if(s->top==MAX-1)
    return 1;
    else
    return 0;
}

void push(stack *s,int ele)
{
    if(isfull(s))
    printf("STACK FULL");
    else
    {
        s->top++;
        s->a[s->top]=ele;
    }
}

int pop(stack *s)
{
    int x;
    if(isempty(s))
    printf("STACK EMPTY");
    else
    {
        x=s->a[s->top];
        s->top--;
        return x;
    }
}

int peek(stack *s)
{
    if(isempty(s))
    printf("STACK EMPTY");
    else
    return s->a[s->top];
}

void display(stack *s)
{
    int i;
    if(isempty(s))
    printf("STACK EMPTY");
    else
    {
        for(i=0;i<=s->top;i++)
        printf("%d\n",s->a[i]);
    }
}



int main()
{
    stack s;
    s.top=-1;
    int ch,ele;
    while(1)
    {
        printf("1.push\n2.pop\n3.peek\n4.display\n5.exxit");
        printf("Enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&ele);
                    push(&s,ele);
                    break;

            case 2: printf("Popped: %d",pop(&s));
                    break;

            case 3: printf("peek value: %d",peek(&s));
                    break;

            case 4: display(&s);
                    break;

            case 5: printf("Thanku!!");
                    return 0;
                    break;

            default: printf("Invalid choice");
                     break;
        }   
    }
}