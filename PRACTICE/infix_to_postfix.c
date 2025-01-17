#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct stack{
    int a[MAX];
    int top;
};

void push(struct stack *s,char x){
    if(s->top==MAX-1){
    printf("Full\n");
    return;
    }
    else{
        s->top++;
        s->a[s->top]=x;
    }
}



int isempty(struct stack *s){
    if(s->top==-1)
    return 1;
    else
    return 0;
}
char pop(struct stack *s){
    char x;
    if(isempty(s)){
        printf("Empty\n");
        return -1;
    }else{
        x=s->a[s->top];
        s->top--;
        return x;
    }
}

char peek(struct stack *s){
    return s->a[s->top];
}

int isoperand(char x){
    if((x>'A' && x<'Z') || (x>'a' && x<'z') )
    return 1;
    else
    return 0;
}

int ic(char x){
    switch(x){
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':return 2;
    }
}

void convert(char *infix,char *postfix){
    struct stack s;
    s.top=-1;
    char x,ele;
    int i,j=0;

    for(i=0;i<strlen(infix);i++){
        x=infix[i];
        if(x=='('){
            push(&s,x);
        }
        else if(x==')'){
            while(!isempty(&s) && peek(&s)!='(' ){
                ele=pop(&s);
                postfix[j++]=ele;
            }
            if(!isempty(&s) && peek(&s)=='(' ){
                pop(&s);
            }
        }

        else if(isoperand(x)){
            postfix[j++]=x;
        }

        else if(isempty(&s)){
            push(&s,x);
        }

        else if(!isempty(&s) && ic(x)>ic(peek(&s)) ){
            push(&s,x);
        }
            else{
                while(!isempty(&s) && ic(x)<=ic(peek(&s)) ){
                    ele=pop(&s);
                    postfix[j++]=ele;
                }
                push(&s,x);
            }
        }
        while(!isempty(&s)){
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
    gets(infix);
    convert(infix,postfix);
    printf("Postfix Expression:\t %s\n",postfix);
    return 0;
}