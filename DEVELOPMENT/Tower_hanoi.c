#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int top=-1;
int a[MAX];
int t,max;

void push(int ele){
    top++;
    a[top]=ele;
}

int pop(){
    return a[top--];
}

int peek(){
    return a[top];
}

int check(int ele){
    if(top==-1){
        push(ele);
        return ele;
    }else{
        while(top!=-1){
            if(ele>peek()){
                max=ele;
                top--;
            }else{
                max=peek();
                top--;
            }
            return max;
        }
    }
}



void display(){
    for(int i=0;i<=top;i++){
        printf("%d ",a[i]);
    }
}


int main()
{
    int ch, ele;
    while (1)
    {
        printf("1.Enter Element\n2.Display\n3.Exit\n");
        printf("Enter Choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element");
            scanf("%d", &ele);
            printf("Max : %d\n" ,check(ele));

            break;
        }
    }
    return 0;
}