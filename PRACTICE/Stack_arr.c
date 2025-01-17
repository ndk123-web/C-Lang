#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10
int stack[CAPACITY];
int top = -1, data;

int isempty()
{
    if (top == -1)
    {
        printf("Stack Empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if (top >= CAPACITY - 1)
    {
        printf("Stack Full\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (!isfull())
    {
        top++;
        stack[top] = data;
    }
}

int pop()
{
    int p;
    if (!isempty())
    {
        p = stack[top];
        top--;
        return p;
    }
}

void stop()
{
    if (!isempty())
    {
        printf("Stack Top : %d\n", stack[top]);
        return;
    }
}

void display()
{
    if (!isempty())
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d\t", stack[i]);
        }
    }
}

int main()
{
    int ch, i;
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Stack Top\n4.Display\n5.Exit\nEnter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            i = pop();
            printf("Popped : %d\n", i);
            break;

        case 3:
            stop();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;
            break;

        default:
            printf("Invalid Option\n");
            break;
        }
    }
}