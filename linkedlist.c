#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *next;
};
typedef struct node * List,*position;
void InsertFirst(List l,int x){
    position new;
    new = (struct node*)malloc(sizeof(struct node));
    if (new=NULL){
        printf("Insufficient Memory");
    }
    else{
    new->element = x; 
    new->next=l->next;
    l->next = new;
     // changing address in head
    }
}
void InsertAtLast(List l, int x) {
    position new,p;
    p = l->next;
    while(p->next=NULL) //finding last node 
        p=p->next;
    new = (struct node*)malloc(sizeof(struct node));
    if (new=NULL){
        printf("Insufficient Memory");
    }
    else { 
        new->element=x;
        new->next=NULL;
        p->next = new; //inserting a node
    }
}
void insertAnyPositon(List l,int x,int pos){
    position new,p;
    p=l->next;
    while(pos!=1) {   //finding previous node before given position
        p=p->next;
        pos--;
    }
    new = (struct node*)malloc(sizeof(struct node));
    if (new=NULL){
        printf("Insufficient Memory");
    }
    else { 
        new->element=x;
        new->next=p->next;
        p->next = new; //inserting a node
    }

}

void printList(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->element);
        temp = temp->next;
    }
    printf("\n");
}
void create(List l)
{
    int n, ele;
    printf("Enter of number of elements:--");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Value:--");
        scanf("%d", &ele);
        InsertAtLast(&l,ele);
    }
}
int main()
{
    int choice, ele;
    struct node * head = (struct node*)malloc(sizeof(struct node));
    List l = head;
    l->next=NULL;
start:
    printf("1.Create a linked linked\n2.Insert a node\n3.Display the linked List\n4.Exit\n");
    printf("Enter your choice:--");
    scanf("%d", &choice);
    switch (choice)
    {
    case (1):
        create(&l);
        printf("Linked List After Creation:--\n");
        printList(&head);
        goto start;
        break;
    case (2):
        printf("Enter the value of element:--");
        scanf("%d", &ele);
        InsertFirst(&l, ele);
        printf("Linked List After Insertation:--\n");
        printList(&head);
        goto start;
        break;
    case (3):
        printList(&head);
        goto start;
        break;
    case (4):
        exit(0);
        break;

    default:
        goto start;
        break;
    }
    return 0;
}