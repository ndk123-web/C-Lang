#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
    int top;
    char a[MAX];
}stack;

void push(stack *s,char ele)
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

int isempty(stack *s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

int peek(stack *s)
{
    return s->a[s->top];
}

int isoperand(char x)
{
    if((x>='A' && x<='Z') || (x>='a' && x<='z'))
    return 1;
    else
    return 0;
}

int icp(char x)
{
    switch(x)
    {
        case '(':
        return 0;

        case '+':
        case '-':
        return 1;

        case '/':
        case '*':
        return 2;

        default: 
        return -1;
    }
}

int isp(char x)
{
    switch(x)
    {
        case '(':
        return 0;

        case '+':
        case '-':
        return 1;

        case '/':
        case '*':
        return 2;

        default: 
        return -1;
    }
}

void convert(char infix[] , char postfix[])
{
    char x,ele;
    int i,j=0;
    stack s;
    s.top=-1;

    for(i=0;i<strlen(infix);i++)
    {
        x=infix[i];
        if(x=='(')
        push(&s,x);

        else if(x==')')
        {
            while(!isempty(&s) && peek(&s)!='(')
            {
                ele=pop(&s);
                postfix[j++]=ele;
            }
            if(!isempty(&s) && peek(&s)=='(')
            pop(&s);
        }

        else if(isoperand(x))
        postfix[j++]=x;

        else if(isempty(&s))
        push(&s,x);
       
        else if(icp(x)>isp(peek(&s)))
        
            push(&s,x);
        

        else
        {
              while(isempty(&s)==0 && icp(x)<=isp(peek(&s)))
              {
                ele=pop(&s);
                postfix[j++]=ele;
              }
              push(&s,x);

        
        }

    }
    while(isempty(&s)==0)
    {
        ele=pop(&s);
        postfix[j++]=ele;
    }
}

int main()
{
    char infix[50];
    char post[50];
    printf("Enter infix expression:\n");
    gets(infix);
    convert(infix,post);
    printf("postfix expression : %s\n");
    return 0;
}