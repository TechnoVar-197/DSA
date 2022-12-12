#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char firstname[20];
    char lastname[20];
    int number;
    struct node *next;
};
typedef struct node* list;
typedef struct node* position;
list start=NULL;

list getnode()
{
    return((list)malloc(sizeof(struct node)));
} 


void display( position start)
{
    position temp;
    temp=start;
    printf("\nThe phone book conains following numbers:--- \n");
    while(temp!=NULL)
    {
        printf("Name:-- %s\t%s\n",temp->firstname,temp->lastname);
        printf("Phone No. :-- %d\n",temp->number);
        temp=temp->next;
    }
}

void insert()
{
    position temp,nn;
    nn=getnode();
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%d",&nn->number);
    temp->next=nn;
    nn->next=NULL;
}

list create()
{
    position temp,nn;
    if(start!=NULL)
        insert();
    else
    {
    nn=getnode();
    start=nn;
    temp=start;
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%d",&nn->number);
    nn->next=NULL;
    }
}

void search()
{
    position temp;
    char *f,*l;
    temp=start;
    printf("Enter name to be searched:\n");
    scanf("%s",&f);
    scanf("%s",&l);
    while((temp->firstname==f)&&(temp->lastname==l))
    {
        temp=temp->next;
    }
    printf("%s\n",temp->firstname);
    printf("%s\n",temp->lastname);
    printf("%d\n",temp->number);
}

void del()
{
    position pretemp,temp;
    int ph;
    temp=start;
    pretemp=start->next;
    printf("Enter PhoneNumber :");
    scanf("%d",&ph);
    while(temp->number!=ph){
        pretemp=pretemp->next;
        temp=temp->next;}

    if(start->next==NULL){
        pretemp->next=NULL;
        pretemp->next=NULL;
        free(temp);
    }    
    else{
    pretemp->next=temp->next;
    free(temp);
    }
}
int main()
{
    int op,ch;
    do{
        printf("-------Welcome--------\n");
        printf("1.Create\n2.Insert\n3.Display\n4.Delete\n5.Search\n6.Sort\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
            break;
            case 2: insert();
            break;
            case 3: display(start);
            break;
            case 4: del();
            break;
            case 5:search();
            break;
        }
        printf("Do you want to quit ? 1 for no / 0 for yes:");
        scanf("%d",&op);
    }while(op!=0);
return 0;
}
