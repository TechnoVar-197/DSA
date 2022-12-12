#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
int flag =0;
typedef struct node* Dlist;
typedef struct node* position;
Dlist dl;position p,head;
Dlist Find(Dlist dl,int pos){
    int i=0;
    dl=dl->next;
    while(i<pos){
        dl=dl->next;
        i++;
    }
    return dl;
}
void InsertAnyPositon(Dlist dl,int x,int pos) {
    position new,p;
    p=dl->next;
    for(int i=0;i<pos;i++){
        if (p->data==x){
            break;
        }
        p=p->next;
    }
    new = (struct node*)malloc(sizeof(struct node));
    if (new=NULL){
        printf("Insufficient Memory");
    }
    else {
        // inserting a node
        new->data=x;
        new->prev=p;
        new->next=p->next;
        p->next = new;
        new->next->prev=new; 
    }

}
void InsertLast(Dlist dl, int x) {
    position new;
    p = dl->next;
    while(p->next!=NULL) //finding last node 
        p=p->next;
    new = (struct node*)malloc(sizeof(struct node));
    if (new=NULL){
        printf("Insufficient Memory");
    }
    else {
        dl=dl->next;
        dl->next=new;
        new->prev=dl;
        new->next=NULL;
        new->data=x;
    }
}
void printList(Dlist S) {
    S=S->next;
    while(S->next!=NULL){
        printf("%d\t",S->data);
        S=S->next;
        }
        printf("%d\n",S->data);
    printf("\n");
}
void create(Dlist dl) {
    int n, ele;
    Dlist new;
    printf("Enter of number of elements:--");
    scanf("%d", &n);p=dl;
    for (int i = 0; i <n; i++)
    {
        printf("Enter element %d:--",i+1);
        scanf("%d", &ele);
        if (p->next==NULL){
            new=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&new->data);
            p->next=new;
            p->next->prev=p;
            p=p->next;
            p->data=new->data;
            p->next=NULL;
        }
        else
            InsertLast(dl,ele);
    }
    printList(dl);
}
void DeleteAnyPos(Dlist T,int pos){
    T=Find(dl,pos);
    Dlist temp=malloc(sizeof(struct node));
    temp=T;
    if(T->next==NULL){
        T->prev->next=NULL;
        T->prev=NULL;
        T->next=NULL;
        free(temp);
        T=dl;
        printList(T);
    }
    else{
    T->prev->next=T->next;
    T->next->prev=T->prev;
    T->prev=NULL;
    free(temp);
    T=dl;
    printf("The array after deletion\n");
    printList(p);
    }
}
int main() {
    Dlist dl=(struct node*)malloc(sizeof(struct node));
    create(dl);
    return 0;
}