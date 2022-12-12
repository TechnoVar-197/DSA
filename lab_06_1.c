#include <stdio.h>
#include <stdlib.h>
typedef struct Node* DList;
struct Node{
    int data;
    struct Node* next;
};
DList L;
DList FindPrev(DList L,int x,DList P)
{
    P=L->next;
    while(P->data!=x){
        P=P->next;
    }
    return P;
}
void Insertion(DList L,int newdata){
    DList First=(struct Node*)malloc(sizeof(struct Node));
    First->data=newdata;
    First->next=L->next;
    L->next=First;
    printf("After inserting:\n");
    
}
void display(DList L){
    L=L->next;
    while(L->next!=NULL){
        printf("%d\n",L->data);
        L=L->next;
        }
        printf("\n");
       
}
int main(){
    int element,s;
    DList p,node2;
    L=(DList)malloc(sizeof(struct Node));
    int n=0;
    p=L;
    
    do{
    node2=(DList)malloc(sizeof(struct Node));
   printf("Enter the data");
   scanf("%d",&node2->data);
      p->next=node2;
      p=p->next;
      p->data=node2->data;
      p->next=NULL;

    printf("Do You want to continue, 1/0");
    scanf("%d",&n);
    }while(n==1);
    display(L);
    printf("\nEnter 1 to insert at first");
    scanf("%d",&s);
    switch(s){
        case 1:
        printf("Enter the element");
        scanf("%d",&element);
        Insertion(L,element);
        display(L);
        break;

    }

    return 0;


}