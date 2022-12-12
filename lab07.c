#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node* DList;
typedef struct Node* Position;
DList DL;Position p;
int pos,flag=0;
void display(DList S){
    S=S->next;
    while(S->next!=NULL){
        printf("%d\n",S->data);
        S=S->next;
        }
        printf("%d\n",S->data);
       
}
void InsertAtLast(DList L,int y){
    DList last=malloc(sizeof(struct Node));
    Position T;
    T=L;
    while(L->next!=NULL)
    L=L->next;
    L->next=last;
    last->prev=L;
    last->next=NULL;
    last->data=y;
    printf("After Inserting:\n");
    display(T);
}
DList FindPrev(DList L,int x,DList p)
{
    p=L->next;
    while(p->data!=x){
        p=p->next;
    }
    return p;
}

void Insertion(DList L,int newdata){
    DList First=(struct Node*)malloc(sizeof(struct Node));
    First->data=newdata;
    First->prev=L;
    First->next=L->next;
    L->next->prev=First;
    L->next=First;
    printf("After inserting:\n");
    display(L);
}

void InsertionAtAny(DList L,int pos,int newdata){
    DList New=(struct Node*)malloc(sizeof(struct Node));
    if(flag<pos){
        InsertAtLast(L,newdata);
    }
    else if(pos==1){
        Insertion(L,newdata);
    }
    else{
    for(int i=0;i<pos;i++)
        L=L->next;
    New->data=newdata;
    New->next=L;
    New->prev=L->prev->next;
    L->prev->next=New;
    L->prev=New;
    printf("After inserting:\n");
    L=DL;
    display(L);
    }
    
}
DList Find(DList L,int pos){
    int i=0;
    L=L->next;
    while(i<pos){
        L=L->next;
        i++;
    }
    return L;
}

void DeletionAtAny(DList T,int pos){
    
    T=Find(DL,pos);
    DList temp=malloc(sizeof(struct Node));
    temp=T;
    if(T->next==NULL){
        T->prev->next=NULL;
        T->prev=NULL;
        T->next=NULL;
        free(temp);
        T=DL;
        display(T);
    }
    else{
    T->prev->next=T->next;
    T->next->prev=T->prev;
    T->prev=NULL;
    free(temp);
    T=DL;
    printf("The array after deletion\n");
    display(p);
    }
}

int main(){
    int x,s;
    DList node2;
    DL=(DList)malloc(sizeof(struct Node));
    int n=0;
    p=DL;
    do{
        node2=(DList)malloc(sizeof(struct Node));
       
    flag++;
   printf("Enter the data\n");
      scanf("%d",&node2->data);
      p->next=node2;
      p->next->prev=p;
      p=p->next;
      p->data=node2->data;
      p->next=NULL;
      

    printf("Enter 1 to enter next element\nEnter 0 to complete the list\n");
    scanf("%d",&n);
    }while(n==1);
    //printf("%d",L->next->next->data);
    printf("The List:\n");
    display(DL);
    printf("Enter 1 to insert\nEnter 2 for Deletion\n");
    scanf("%d",&s);
    

    switch(s){
        case 1:
        p=DL;
        //printf("%d",flag);
        printf("Enter the position to insert\n");
        scanf("%d",&pos);
        printf("Enter the element\n");
        scanf("%d",&x);
        InsertionAtAny(p,pos,x);
        break;

        case 2:
        p=DL;
        printf("Enter the pos to delete\n");
        scanf("%d",&pos);
        DeletionAtAny(p,pos);

    }

    return 0;


}