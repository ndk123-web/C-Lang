#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct LL{
    struct node *start;
};

void insertbeg(struct LL *l,int ele){
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    new->data=ele;
    new->next=l->start;
    l->start=new;
}

void insertend(struct LL *l,int ele){
    struct node *new,*p;
    new=(struct node*) malloc(sizeof(struct node));
    new->data=ele;
    new->next=NULL;

    if(l->start==NULL){
        l->start=new;
    }
    else{
        p=l->start;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new;
    }
}

void display(struct LL *l){
    struct node *p;
    p=l->start;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

void deletebeg(struct LL *l){
    struct node *p;
    p=l->start;
    l->start=l->start->next;
    printf("Deleted: %d\n", p->data);
    free(p);
}

void deleteend(struct LL *l){
    struct node *p,*prev;
    if(l->start==NULL){
        printf("Empty Linked List\n");   
    }
    else{
        p=l->start;
        prev=NULL;
        while(p->next!=NULL){
            prev=p;
            p=p->next;
        }
        if(prev==NULL){
            printf("Deleted: %d\n", p->data);
            free(p);
            l->start=NULL;
        }
        else{
            printf("Deleted: %d\n", p->data);
            prev->next=NULL;
            free(p);
        }
    }
}

void insertat(struct LL *l, int ele, int pos, int c) {
    if (pos == 0 || pos == 1) {
        insertbeg(l, ele);
    } else if (pos > c || pos < 0) {
        printf("Invalid Position\n");
    } else {
        struct node *p, *new, *prev;
        p = l->start;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = ele;
        new->next = NULL;

        for (int i = 0; i < pos - 1; i++) {
            prev = p;
            p = p->next;
        }
        new->next = p;
        prev->next = new;
    }
}

void deleteat(struct LL *l, int pos, int c) {
    struct node *p, *prev;
    p = l->start;
    
    if (pos == 0 || pos == 1) {
        deletebeg(l);
        c--;
    } else if (pos > c || pos < 1) {
        printf("Invalid position\n");
        return; 
    } else {
        for (int i = 0; i < pos - 1; i++) {
            prev = p;
            p = p->next;
        }
        printf("Deleted: %d\n", p->data);
        prev->next = p->next;
        free(p);
        c--;
    }
}

void search(struct LL *l, int data) {
    struct node *p;
    p = l->start;
    while (p != NULL) {
        if (p->data == data) {
            printf("Found\n");
            return;
        }
        p = p->next;
    }
    printf("Not Found\n");
}

void sort(struct LL *l){
    struct node *p,*q;
    int t;
    p=l->start;
    for(p=l->start;p->next!=NULL;p=p->next){
        for(q=l->start;q->next!=NULL;q=q->next){
            if(q->data > q->next->data){
                t=q->data;
                q->data=q->next->data;
                q->next->data=t;
            }
        }
    }
}

void reverse(struct LL *l){
    struct node *c,*p,*n;
    c=l->start;
    p=NULL;

    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    l->start=p;
}

int main(){
    int data,ch,ele,pos,c=0;
    struct LL l;
    l.start=NULL;

    while(1)
    {
        printf("1.Insert beginning\n2.Insert Ending\n3.Delete beginning\n4.Delete Ending\n5.Display\n6.InsertAt\n7.DeleteAt\n8.Search\n9.sort\n10.Reverse");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Data: ");
                    scanf("%d",&ele);
                    insertbeg(&l,ele);
                    c++;
                    break;

            case 2: printf("Enter Data: ");
                    scanf("%d",&ele);
                    insertend(&l,ele);
                    c++;
                    break;
                    
            case 3: deletebeg(&l);
                    c--;
                    break;
                    
            case 4: deleteend(&l);
                    c--;
                    break;

            case 5: display(&l);
                    printf("\n");
                    break;
                    
            case 6: printf("Enter Element and position: ");
                    scanf("%d %d",&ele,&pos);
                    insertat(&l,ele,pos,c);
                    c++;
                    break;
                    
            case 7: printf("Enter position for Delete: ");
                    scanf("%d",&pos);
                    deleteat(&l,pos,c);
                    c--;
                    break;
                    
            case 8: printf("Enter data to be found: ");
                    scanf("%d",&data);
                    search(&l,data);
                    break;

            case 9: sort(&l);
                    break;

            case 10: reverse(&l);
                     break;

            default: printf("Invalid Choice\n");
                     break;
        }
    }

    return 0;
}
