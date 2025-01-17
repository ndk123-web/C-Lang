#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 15

typedef struct {
    int top;
    int a[MAX];
}stack;

void push(stack *s,int ele)
{
    s->top++;
    s->a[s->top]=ele;
}

int pop(stack *s)
{
    char x;
    x=s->a[s->top];
    s->top--;
    return x;
}

int isoperand(char x)
{
    if(x>='0' && x<='9')
    return 1;
    else
    return 0;
}

int eval(char postfix[])
{
    stack s;
    s.top=-1;
    int a,b,i,ss=0;
    char x;
    for(i=0;i<strlen(postfix);i++)
{
        x=postfix[i];
        if(isoperand(x))
        push(&s,(int)x-'0');
        else
    {
     b=pop(&s);
     a=pop(&s);

     switch(x)
      {
        case '+': ss=a+b; break;
        case '-': ss=a-b; break;
        case '*': ss=a*b; break;
        case '/': ss=a/b; break;
      }
      push(&s,ss);      
    }
}
return pop(&s);
}

int main()
{
    char postfix[50];
    int x;
    printf("Enter postfix Expression: ");
    gets(postfix);
    x=eval(postfix);
    printf("Result is %d ",x);
    return 0;
}

