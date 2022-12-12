#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* list;
typedef struct node* position;
list l;position p,head;
void insertatfirst(list l)
{
    int New;  
    position ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("Memory full");   
    }  
    else   
    {  
        printf("Enter the value:\n");  
        scanf("%d",&New);  
        if(l==NULL) {         
            ptr->data = New;  
            ptr -> next = NULL;  
            l=ptr;  
        }   
        else {  
            ptr->data = New;  
            ptr->next = l;  
            l =ptr;         
        }
    }
}
void insertatlast(list l){
        int New;  
    position ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("Memory full");   
    }  
    else   
    {  
        printf("Enter the value:\n");  
        scanf("%d",&New);  
        if(l==NULL) {         
            ptr->data = New;  
            ptr -> next = NULL;  
            l=ptr;  
        }   
        else {
            ptr=l->next;
            while(ptr->next=NULL)
                ptr=ptr->next;
            position new = (struct node*)malloc(sizeof(struct node));
            new->data=New;
            new->next=NULL;
            ptr->next=new;
        }
    }
}
void printList()
{
    struct node*ptr;  
    ptr=l;  
    if(ptr == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else  
    {  
        printf("Elements in the List\n");  
        while(ptr->next!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr=ptr->next;  
        }  
    } 
}
void create(list l)
{
    int element,s;
    list P,node2;
    l=(list)malloc(sizeof(struct node));
    int n=0;
    P=l;
    
}
int main()
{
    list l = (struct node *)malloc(sizeof(struct node));
    int choice, ele;
start:
    printf("1.Create a linked list\n2.Insert a node at first position\n3.Display the linked List\n4.Exit\n");
    printf("Enter your choice:--");
    scanf("%d", &choice);
    switch (choice)
    {
    case (1):
        create(l);
        printf("Linked List After Creation:--\n");
        printList();
        goto start;
    case (2):
        insertatfirst(l);
        printf("Linked List After Insertation:--\n");
        printList();
        goto start;
    case (3):
        printList();
        goto start;
    case (4):
        printf("Program is exiting normally\n");
        exit(0);
    default:
        goto start;
    }
    return 0;
}