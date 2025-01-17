#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node *start,int ele){
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    new->data=ele;
    new->next=start;
    start=new;
}

int delete(struct node *start){
    struct node *p; int t;
    if(!start){
        printf("Null LL \n");
    }else{
        p=start;
        t=p->data;
        start=start->next;
        free(p);
    }   
    return t;
}

void display(struct node *start){
    struct node *p;
    if(!start){
        printf("Null LL\n");
    }else{
        p=start;
        while(p!=NULL){
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}

void reverse(struct node *start)
{
    if(!start){
        return;
    }else{
    reverse(start->next);
    printf("%d",start->data);
    }
}

int main()
{
    struct node *start=NULL;
    int ch,ele;
    while(1){
        printf("1.Insert\n2.Delete\n3.Display\nEnter choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Data");
                    scanf("%d",&ele);
                    insert(&start,ele);
                    break;

            case 2: printf("%d\n",delete(&start));
                    break;

            case 3: display(start);
                    break;

            case 4: reverse(&start);
                    break;

            default: printf("Invalid choide\n");
                    break;
        }
    }
    return 0;
}