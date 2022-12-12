#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
int i,n=0,l[maxsize];
void insert(int x){
    if (n>=maxsize && n!=0)
        printf("The list is Full\n");
    else {
        for(i=n-1;i>=0;i--)
            l[i+1]=l[i];
    l[0]=x;
    n++;
    }
}
void delete(int pos){
    if (n<1)
        printf("The list is empty\n");
    else {
        for(i=pos;i<=n-1;i++)
            l[i-1]=l[i];
        n--;
    }
}
int search(int val) {
    int pos=-1;
    for(i=0;i<n;i++){
        if (l[i]==val){
            pos=i;
            break;
        }
    }
    return pos;
}
void create(){
    printf("Enter the size of the list:--");
    scanf("%d", &n);
    printf("Enter the element of the list:--\n");
    for(i=0;i<n;i++) {
        scanf("%d",&l[i]);
    }
}
void printlist(){
    printf("The list contains following elements:--\n");
    for(i=0;i<n;i++){
        printf("%d\t",l[i]);
    }
    printf("\n");
}
int main() {
    int choice,ele,val,index;create();
    start:
    printf("1.Insert element in the list\n2.Delete element from the list\n3.Print the list\n4.Exit\n");
    printf("Enter your choice:--");
    scanf("%d",&choice);
    switch (choice)
    {
    case (1):
        printf("Enter the element:--\n");
        scanf("%d",&ele);
        insert(ele);
        printlist();
        goto start;
    case (2):
        printf("Enter the element to be deleted:--\n");
        scanf("%d",&val);
        index = search(val);
        if (index==-1) {
            printf("Value is not present in array\n");
        }
        else {
            index = (search(val))+1;
            delete(index);
        }
        printlist();
        goto start;
    case (3):
        printlist();
        goto start;    
    case (4):
        exit(0);
    default:
        goto start;
    }
    return 0;
}