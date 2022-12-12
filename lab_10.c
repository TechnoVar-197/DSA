//Circular queue
#include<stdio.h>
#include<stdlib.h>
#define max_size 5
int q[max_size],front=-1,rear=-1,count=0;
void enqueue( int x){
    if(count==max_size){
        printf("Queue is Overflow");
    }
    else{
        if (front == -1){
            front++;
        }
        rear=(rear+1)%max_size;
        count++;
        q[rear]=x;
    }
}
int dequeue(){
    if (count == 0){
        printf("The Queue is empty");
    }
    else{
        int temp = q[front];
        front=(front+1)%max_size;
        count--;
        return temp;
    }
}
void display(){
    printf("The queue contains following elements:--");
    int i=front,temp=1;
        while(temp!=count){
            printf("%d\t",q[i]);
            i=(i+1)%max_size;
            temp++;
        }
    printf("%d\t",q[rear]);
    printf("\n");
}
int main() {
    int choice,x;
    start:
    printf("1.To enter the element in Queue \n2.To Delete the element in Queue\n3.Exit\n");
    printf("Enter the choice:--");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the element to be entered:--");
        scanf("%d",&x);
        enqueue(x);
        display();
        goto start;
    
    case 2:
        int temp = dequeue();
        printf("The element removed is %d",temp);
        display();
        goto start;
    case 3:
        exit(0);
    
    default:
        goto start;
    }
    return 0;
}