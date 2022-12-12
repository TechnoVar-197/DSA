#include <stdio.h>
#include<stdlib.h>
#define maxsize 1002
int i,n=0, list[maxsize];
void create() {
    printf("Enter the size of the list:--");
    scanf("%d", &n);
    printf("Enter the element of the list:--\n");
    for(i=0;i<n;i++)
        scanf("%d",&list[i]);
}
void printlist() {
    printf("The elements in the list are :--\n");
    for (i=0;i<n;i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
}
void insertfirst(int x){
    if (n>=maxsize && n!=0)
        printf("The list is Full\n");
    else {
        for(i=n-1;i>=0;i--)
            list[i+1]=list[i];
    list[0]=x;
    n++;
    }
}
void insertanypos(int x,int pos){
    if (n>=maxsize && n!=0)
        printf("The list is Full\n");
    else {
        for(i=n-1;i>=pos-1;i--)
            list[i+1]=list[i];
    list[pos-1]=x;
    n++;
    }
}
void insertlast(int x){
    if (n>=maxsize && n!=0)
        printf("The list is Full\n");
    else {
        list[n]=x;
        n++;
    }
}
void deletefirst(){
    if (n<1)
        printf("The list is empty\n");
    else {
        for(i=0;i<=n-2;i++)
            list[i]=list[i+1];
        n--;
    }
}
void deletelast(){
    if (n<1)
        printf("The list is empty\n");
    else 
        n--;
}
void deleteanypos(int pos){
    if (n<1)
        printf("The list is empty\n");
    else {
        for(i=pos;i<=n-1;i++)
            list[i-1]=list[i];
        n--;
    }
}
void search(){
    int val,pos=-1;
    printf("Enter value to be found:-- ");
    scanf("%d",&val);
    for(i=0;i<n;i++){
        if (list[i]==val){
            pos=i;
            break;
        }
    }
    if (pos==-1) {
        printf("Value is not present in array\n");
    }
    else {
        printf("Value %d is present at %d postion in array\n",val,pos+1);
    }
}
int main() {
    int choice,pos,ele,ichoice,index;
    start:
    printf("1.CREATE THE LIST\n2.PRINT THE LIST\n3.INSERT ELEMENT IN THE LIST\n4.DELETE ELEMENT IN THE LIST\n5.SEARCH ELEMENT IN THE LIST\n6.EXIT\n");
    printf("Enter your choice:-- ");
    scanf("%d",&choice);
    switch (choice)
    {
    case (1):
        create();
        goto start;
        break;
    case (3):
        printf("1.Insert first element\n2.Insert last element\n3.Insert element at any position\n");
        printf("Enter your choice:-- ");
        scanf("%d",&ichoice);
        printf("Enter the elment to added to the list:--");
        scanf("%d",&ele);
        switch (ichoice)
        {
        case (1):
            insertfirst(ele);
            break;
        case (2):
            insertlast(ele);
            break;
        case (3):
            printf("Enter the position element to be inserted:--");
            scanf("%d",&index);
            insertanypos(ele,index);
            break;       
        default:
            break;
        }
        goto start;
        break;
    case (4):
        printf("1.Delete first element\n2.Delete last element\n3.Delete element at any position\n");
        printf("Enter your choice:-- ");
        scanf("%d",&ichoice);
        switch (ichoice)
        {
        case (1):
            deletefirst();
            break;
        case (2):
            deletelast();
            break;
        case (3):
            printf("Enter the position element to be deleted:--");
            scanf("%d",&index);
            deleteanypos(index);
            break;       
        default:
            break;
        }
        goto start;
        break;
    case (5):
        search();
        goto start;
        break;
    case (6):
        exit(0);
        break;
    case (2):
        printlist();
        goto start;
        break;
    default:      
        break;
    }
    return 0;
}