#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max_size 100
int stack[max_size],top=-1;
void push(int x){
    top=top+1;
    stack[top]=x;
}
int pop(){
    int element = stack[top];
    top--;
    if (top==0){
        printf("Stack underflow");
        return 0;
    }
    else{
        return element;
    }
}
int main() {
     
    return 0;
}