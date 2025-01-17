#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

typedef struct
{
    int top;
    char a[MAX];
} stack;
void push(stack *s, char x);
int pop(stack *s);
int isempty(stack *s);
int peek(stack *s);
int isoperand1(char x);
int isoperand(char x);
void convert(char infix[], char postfix[]);
int input(char postfix[]);
int evaluate(char postfix[]);

int main()
{
    int d;
    int postfix1[50];
    char postfix[50];
    char infix[50];
    printf("Enter infix Expression");
    gets(infix);
    convert(infix, postfix);
    printf("postfix :%s\n", postfix);
    input(postfix);
    return 0;
}
void push(stack *s, char ele)
{
    s->top++;
    s->a[s->top] = ele;
}

int pop(stack *s)
{
    char x;
    x = s->a[s->top];
    s->top--;
    return x;
}

int peek(stack *s)
{
    return s->a[s->top];
}

int isoperand(char x)
{
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
        return 1;
    else
        return 0;
}

int isempty(stack *s)
{
    return (s->top == -1);
}

int ic(char x)
{
    switch (x)
    {
    case '(':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    }
}

void convert(char infix[], char postfix[])
{
    stack s;
    s.top = -1;
    char x, ele;
    int i, j = 0;

    for (i = 0; i < strlen(infix); i++)
    {
        x = infix[i];
        if (x == '(')
            push(&s, x);
        else if (x == ')')
        {
            while (peek(&s) != '(')
            {

                ele = pop(&s);
                postfix[j++] = ele;
            }
            pop(&s);
        }
        else if (isoperand(x))
            postfix[j++] = x;
        else if (isempty(&s))
            push(&s, x);

        else if (ic(x) > ic(peek(&s)))
        {
            push(&s, x);
        }
        else
        {

            while (isempty(&s) == 0 && ic(x) <= ic(peek(&s)))
            {
                ele = pop(&s);
                postfix[j++] = ele;
            }
            push(&s, x);
        }
    }
    while (isempty(&s) == 0)
    {
        ele = pop(&s);
        postfix[j++] = ele;
    }

    postfix[j] = '\0';
}

int input(char postfix[])
{
    int postfix1[50];
    int i, k = 0;
    char x;
    for (i = 0; i < strlen(postfix); i++)
    {
        x = postfix[i];
        if (isoperand(x))
        {
            printf("Enter %c data : ", postfix[i]);
            scanf("%d", &postfix1[i]);
            postfix[i] = (char)postfix1[i] + '0';
        }
    }
    evaluate(postfix);
}

int isoperand1(char x)
{
    if (x >= '0' && x <= '9')
        return 1;
    else
        return 0;
}

int evaluate(char postfix[])
{
    stack s;
    s.top = -1;
    char x;
    int d, i, a, b, f;
    for (i = 0; i < strlen(postfix); i++)
    {
        x = postfix[i];
        if (isoperand1(x))
            push(&s, (int)x - '0');
        else
        {
            b = pop(&s);
            a = pop(&s);
            switch (x)
            {
            case '+':
                f = a + b;
                break;
            case '-':
                f = a - b;
                break;
            case '*':
                f = a * b;
                break;
            case '/':
                f = a / b;
                break;
            }
            push(&s, f);
        }
    }
    d = pop(&s);
    printf("RESULT : %d", d);
}
