#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
    int top;
    char a[MAX];
    int b[MAX];
}stack;

int isoperand(char x)
{
    if((x>='A' && x<='Z') || (x>='a' && x<='z'))
    return 1;
    else
    return 0;
}

int ifdigit(char x)
{
    if(x>='0' && x<='9')
    return 1;
    else
    return 0;
}

int push(stack *s,char x)
{
   s->top++;
   s->a[s->top]=x;
}


int pop(stack *s)
{
    int x;
    x=s->a[s->top];
    s->top--;
    return x;
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

int isempty(stack *s)
{
    return s->top==-1;
}

int peek(stack *s)
{
    return s->a[s->top];
}

void convert(char infix[],char postfix[])
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
       
        else if(icp(x)>icp(peek(&s)))
        
            push(&s,x);
        

        else
        {
              while(isempty(&s)==0 && icp(x)<=icp(peek(&s)))
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

int eval(int postfix[])
{
    stack s;
    s.top=-1;
    int a,b,i,ss=0;
    int x;
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
printf("sum is %d",pop(&s));
}

int input(char postfix[])
{
    int i,ele;
    int a[50];
    char x;
    for(i=0;i<sizeof(postfix);i++)
    {
        x=postfix[i];
        if(isoperand(x))
        {
            printf("Enter %c value",x);
            scanf("%d",&ele);
            a[i]=ele;
        }
        a[i]=x;
    }
    eval(a);
}

int main()
{
    char infix[50];
    char postfix[50];
    printf("Enter infix Expression");
    gets(infix);
    convert(infix,postfix);
    printf("Postfix : %s",postfix);
    input(postfix);
    return 0;
}