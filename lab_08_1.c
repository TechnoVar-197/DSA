#include <stdio.h>
#include <stdlib.h>
typedef struct Node* Stack,*Position;
struct Node{
    int data;
    struct Node* next;
};

int n=0;
Stack S,temp;
int flag=0;
void Push(Stack P,int newdata){
    S=P;
    Stack New=(struct Node*)malloc(sizeof(struct Node));
    if(S->next==NULL){
        New->data=newdata;
        New->next=NULL;
        S->next=New;
    }
    else{
    New->data=newdata;
    New->next=S->next;
    S->next=New;
    }
}
int Pop(Stack S){
    if(S->next==NULL){
        printf("Stack Underflow!!!");
        n=0;
        return 0;
    }
    else{
    temp=S->next;
    S->next=temp->next;
    return temp->data;
    }
}
void display(Stack P){
    Stack St=P;
    int i=0;
    P=P->next;
    while(P->next!=NULL){
        printf("%d\n",P->data);
        P=P->next;
        }
        printf("%d",P->data);
       
}
int main(){
    int element,s;
    Position P;
    S=(Stack)malloc(sizeof(struct Node));
    S->next=NULL;
    P=S;
    do{
        printf("Enter the element");
        scanf("%d",&element);
        Push(P,element);
        printf("\nEnter 1 to continue pushing, 0 to complete\n");
        scanf("%d",&n);
        }while(n==1);
        printf("The Stack\n");
        display(P);
    printf("\nEnter 1 to push\nEnter 2 to Pop\n");
    scanf("%d",&s);
    n=0;

   switch(s){
        case 1:
        P=S;
        do{
        printf("Enter the element");
        scanf("%d",&element);
        Push(P,element);
        printf("\nEnter 1 to continue pushing, 0 to complete\n");
        scanf("%d",&n);
        }while(n==1);
        printf("Stack after pushing\n");
        display(S);
        break;

        case 2:
        do{
            int popped=Pop(S);
            printf("Popped data\n");
            printf("%d\n",popped);
            printf("Enter 1 to continue popping\n");
            scanf("%d",&n);
        }while(n==1);
        break;

    }

    return 0;


}