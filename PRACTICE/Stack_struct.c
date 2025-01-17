#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct stack{
    int a[MAX];
    int top;
};

int isempty(struct stack *s){
    if(s->top==-1)
    return 1;
    else
    return 0;
}

int isfull(struct stack *s){
    if(s->top==MAX-1)
    return 1;
    else
    return 0;
}

void push(struct stack *s,int ele){
    if(isfull(s)){
        printf("Stack Full\n");
    }else{
        s->top++;
        s->a[s->top]=ele;
    }
}

void pop(struct stack *s){
    if(isempty(s)){
        printf("Stack Empty\n");
    }else{
        printf("Popped : %d\n",s->a[s->top]);
        s->top--;
    }
}

void peek(struct stack *s){
    if(isempty(s)){
        printf("Stack Empty\n");
    }else{
        printf("Stack Top : %d\n",s->a[s->top]);
    }
}

void display(struct stack *s){
    if(isempty(s)){
        printf("Stack Empty\n");
    }else{
        for(int i=0;i<=s->top;i++){
            printf("%d\t",s->a[i]);
        }
    }
}

void main()
{
    struct stack s;
    s.top=-1;
    int ch,ele;

    while(1){
        printf("1.push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Element");
                    scanf("%d",&ele);
                    push(&s,ele);
                    break;

            case 2: pop(&s);
                    break;

            case 3: peek(&s);
                    break;

            case 4: display(&s);
                    break;

            default: printf("Invalid Option\n");
                     break;
        }
    }
}