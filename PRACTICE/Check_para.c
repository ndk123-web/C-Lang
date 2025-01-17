#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
    int top;
    char a[MAX];
}stack;

void push(stack *s,char x)
{
  s->top++;
  s->a[s->top]=x;
}
char pop(stack *s)
{
    char x;
    x=s->a[s->top];
    s->top--;
    return x;
}

int isopen(char x)
{
    if(x=='[' ||x=='{' || x=='(')
    return 1;
    else
    return 0;
}

int isclose(char x)
{
    if(x==')' || x=='}' || x==']')
    return 1;
    else
    return 0;
}
int isempty(stack *s)
{
    if(s->top==-1)
    return 1;
    else 
    return 0;
}

int check(char exp[])
{
    char x,ele;
    int i;
    stack s;
    s.top=-1;
    for(i=0;i<strlen(exp);i++)
    {
        x=exp[i];
        if(isopen(x))
        push(&s,x);
        else if(isempty(&s))
        return 0;
        else if(isclose(x))
        {
            ele=pop(&s);
            if(ele!='(' && x==')')
            return 0;
            else if(ele!='[' && x==']')
            return 0;
            else if(ele!='{' && x=='}')
            return 0;
    }
}
return 1;
}

int main()
{
    char exp[50];
    printf("Enter expression");
    gets(exp);
    if(check(exp))
    printf("ALL WELL");
    else
    printf("INVALID");
    return 0;
}