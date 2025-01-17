#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
    int a[MAX];
    int top;
}stack ;

int isempty(stack *s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}

void push(stack *s,char x)
{
    if(s->top==MAX-1)
    printf("STACK FULL\n");
    else
    {
        s->top++;
        s->a[s->top]=x;
    }
}

char pop(stack *s)
{
    char x;
    if(isempty(s))
    printf("STACK EMPTY\n");
    else
    {
        x=s->a[s->top];
        s->top--;
        return x;
    }
}

char peek(stack *s)
{
    if(isempty(s))
    printf("STACK EMPTY\n");
    else
    {
        return s->a[s->top];
    }
}

int isoperand(char x)
{
    if((x>='A' && x<='Z') || (x>='a' && x<='z') )
    return 1;
    else
    return 0;
}

int ic(char x)
{
    switch(x)
    {
        case '(': return 0;
        case '+':
        case '-': return 1; 
        case '/':
        case '*': return 2; 
    }
}

void convert(char infix[],char postfix[])
{
    stack s;
    s.top=-1;
    int i,j=0;
    char x,ele;

    for(i=0;i<strlen(infix);i++)
    {
        x=infix[i];
        if(x=='(')
        push(&s,x);
        else if(x==')')
        {
            while(1)
            {
                ele=pop(&s);
                if(ele=='(')
                break;
                postfix[j++]=ele;
            }
        }
        else if(isoperand(x))
        postfix[j++]=x;
        else if(isempty(&s))
        push(&s,x);
        else if(!isempty(&s) && ic(x)>ic(peek(&s)))
        push(&s,x);

        else
        {
            while(!isempty(&s) && ic(x)<=ic(peek(&s)))
            {
                ele=pop(&s);
                postfix[j++]=ele;
            }
            push(&s,x);
        }
    }
    while(!isempty(&s))
    {
        ele=pop(&s);
        postfix[j++]=ele;
    }
    postfix[j]='\0';
}

int main()
{
    char infix[50];
    char postfix[50];
    printf("Enter Infix Expression");
    fgets(infix, sizeof(infix), stdin); 
    convert (infix,postfix);
    printf("Postfix : %s",postfix);
    return 0;
}