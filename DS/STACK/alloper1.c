#include<stdio.h>
#define MAX 5

typedef struct {
    int a[MAX];
    int top;
}stack;

int isfull(stack *s)
{
    if(s->top==MAX-1)
    return 1;
    else
    return 0;;
}

int isempty(stack *s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

void push(stack *s,int data)
{
    if(isfull(s))
    printf("FULL\n");
    else
    {
        s->top++;
        s->a[s->top]=data;
    }
}

int pop(stack *s)
{
   if(isempty(s))
   printf("EMPTY\n");
   else{
    return s->a[s->top--];
   }
}

int peek(stack *s)
{
    if(isempty(s))
    printf("EMPTY\n");
    else{
        return s->a[s->top];
    }
}

void traverse(stack *s)
{
    if(isempty(s))
    printf("EMPTY");
    else{
        for(int i=0;i<=s->top;i++)
        printf("%d\n",s->a[i]);
    }
}



int main()
{
    int ch,data;
    stack s1;
    s1.top=-1;

    while(1)
    {
        printf("1.push\n2.pop\n3.peek\n4.traverse\n5.exit\n");
        printf("Enter choice");
        scanf("%d",&ch);

        switch(ch){
            case 1 : printf("Enter push Element: ");
                     scanf("%d",&data);
                     push(&s1,data);
                     break;

            case 2 : printf("Popped : %d\n",pop(&s1));
                       break;

            case 3: printf("peek : %d\n",peek(&s1));
                      break;

            case 4: traverse(&s1);
                    break;

            case 5: printf("Thank u");
                      return 0;
                      break;

            default : printf("Invalid");
            break;
        }
    }
}