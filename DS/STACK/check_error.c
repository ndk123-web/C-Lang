#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
    int top;
    char a[MAX];
} stack;

void push(stack *s, char x) {
    s->top++;
    s->a[s->top] = x;
}

char pop(stack *s) {
    char x;
    x = s->a[s->top];
    s->top--;
    return x;
}

int isempty(stack *s) {
    return s->top == -1;
}

int isoperand(char x) {
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}

int peek(stack *s) {
    return s->a[s->top];
}

int ic(char x) {
    switch (x) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1;
    }
}

void evaluate(char *infix, char *postfix) {
    int i, j = 0;
    char x, ele;
    stack s;
    s.top = -1;
    for (i = 0; i < strlen(infix); i++) {
        x = infix[i];
        if (x == '(')
            push(&s, x);
        else if (x == ')') {
            while ((ele = pop(&s)) != '(')
                postfix[j++] = ele;
        } else if (isoperand(x))
            postfix[j++] = x;
        else {
            while (!isempty(&s) && ic(x) <= ic(peek(&s)))
                postfix[j++] = pop(&s);
            push(&s, x);
        }
    }
    while (!isempty(&s))
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

int checkkaro(char infix[]) {
    stack s;
    s.top = -1;
    char x;
    int i;
    for (i = 0; i < strlen(infix); i++) {
        x = infix[i];
        if (x == '(')
            push(&s, x);
        else if (x == ')') {
            if (isempty(&s) || pop(&s) != '(')
                return 0;
        }
    }
    return isempty(&s);
}

int getvalue(char postfix[],char op[])
{
    char x,ele;
    int a[50];
    for(int i=0;i<strlen(postfix);i++)
   {
      if(!isoperand(x))
      return 0;
      {
        printf("Enter %c value",op[i]);
        scanf("%d",a[i]);
      }
   }

}

int input(char postfix[])
{
    stack s;
    s.top=-1;
    char x,ele;
    int op[50];
    for(int i=0;i<strlen(postfix);i++)
    {
           x=postfix[i];
           if(!isoperand(x))
           return 0;
           else
        {
             op[i]=x;
             printf("Enter %c value",op[i]);
             scanf("%d",&op[i]);

            
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
        }
    }
    
    printf("Sum is %d",pop(&s));

}

int main() {
    char postfix[50];
    char infix[50];
    printf("Enter infix: ");
    gets(infix);
    if (!checkkaro(infix)) {
        printf("Invalid infix expression\n");
        return 1;
    }
    evaluate(infix, postfix);
    printf("Postfix Expression is %s\n", postfix);
    input(postfix);
    return 0;
}
