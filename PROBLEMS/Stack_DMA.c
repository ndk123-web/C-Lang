#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int data;
int *a;

void push(int data){
    if(top==MAX){
        printf("Stack Full\n");
    }else{
        top++;
        a[top]=data;
    }
}

void pop(){
    if(top==-1){
        printf("Stack Empty\n");
    }else{
        printf("Popped %d\n",a[top]);
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("Stack Empty\n");
    }else{
        printf("Top Of Stack %d",a[top]);
    }
}

void display()
{
    for(int i=0;i<=top;i++){
        printf("%d\t",a[i]);
    }
}

int main()
{    
    a=(int*) malloc(sizeof(int)*MAX);
    int ch;
    while(1){
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Choice");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter Data");
                    scanf("%d",&data);
                    push(data);
                    break;

            case 2: pop();
                    break;

            case 3: peek();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);
        }
    }    
}