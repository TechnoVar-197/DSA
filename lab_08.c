#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *stack;
typedef struct node *position;
int n=1;
position p;stack s;
void display()  
{   
    struct node*ptr;  
    ptr=s;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Stack elements \n");  
        while(ptr->next!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr=ptr->next;  
        }  
    }  
}
void push ()  
{  
    int New;  
    position ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("not able to push");   
    }  
    else   
    {  
        printf("Enter the value:\n");  
        scanf("%d",&New);  
        if(s==NULL) {         
            ptr->data = New;  
            ptr -> next = NULL;  
            s=ptr;  
        }   
        else {  
            ptr->data = New;  
            ptr->next = s;  
            s =ptr;         
        }  
        printf("Item pushed\n");  
          
    }  
}  
void pop()  
{  
    int element;  
    struct node* ptr;  
    if (s == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        element = s->data;  
        ptr = s;  
        s = s->next;  
        free(ptr);  
        printf("Item popped\n");  
        printf("The following element removed from stack:-- %d\n",element);
        printf("The Stack contains:--\n");
        display(s);
          
    }  
} 
int main()
{
    s=(stack)malloc(sizeof(struct node));
    int element,choice,n;
    s->next=NULL;p=s;
    printf("Creation of Stack\n");
    printf("Enter number of elements:--\n");scanf("%d",&n);
    for(int i = 0;i<n;i++){
        push();
    }
    printf("The elements in stack:--\n");
    display();
    start:
    printf("1.push the element\n2.pop the element\n3.Display the stack\n4.Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push();
        goto start;
    case 2:
        pop();
        goto start;
    case 3:
        display();
        goto start;
    case 4:
        printf("The code is exiting\n");
        exit(0);
    default:
        goto start;
    }
    return 0;
}