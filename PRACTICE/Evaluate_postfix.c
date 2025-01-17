#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct stack{
    int top;
    int a[MAX];
};

int isempty(struct stack *s){
    if(s->top==-1)
    return 1;
    else
    return 0;
}

int isoperand(char x){
    if(x>= '0' && x<= '9')
    return 1;
    else
    return 0;
}

void push(struct stack *s,int x){
    if(s->top==MAX-1){
        printf("Full\n");
    }else{
        s->top++;
        s->a[s->top]=x;
    }
}

int pop(struct stack *s){
    int x;
    x=s->a[s->top];
    s->top--;
    return x;
}

int convert(char *postfix){
    char x,ele;
    struct stack s;
    s.top=-1;
    int a,b,c=0;

    for(int i=0;i<strlen(postfix);i++){
        x=postfix[i];
        if(isoperand(x)){
            push(&s,(int)x-'0');
        }
        else{
            a=pop(&s);
            b=pop(&s);
            switch(x){
                case '+': c=b+a;
                        break;
                case '-': c=b-a;
                         break;
                case '*': c=a*b;
                         break;
                case '/': if(a==0){
                            printf("Not possible\n");
            }
                         c=b/a;
                        
                         break;
            }
            push(&s,c);
        }
    }
    return pop(&s);
}

int main()
{
    char postfix[50];
    printf("Enter Postfix Expression");
    fgets(postfix,MAX,stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
    int sum=convert(postfix);
    printf("Sum : %d",sum);
    return 0;
}