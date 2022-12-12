// Binary tree
#include<stdio.h>
#define max 50
int bt[max],left,right,count=1;
int find(int ele){
    int in =-1;
    for(int i=1;i<=count;i++){
        if (bt[i]==ele){
            in = i;
        }
    }
    if (in ==-1){
        printf(" element not in array");
    }
    return in;
}
void getparent(int x){
    if (x == 1){
        printf("Root node");
    }
    else if (x%2 == 0){
        printf("The root node is %d",bt[x/2]);
    }
    else{
        printf("The root node is %d",bt[(x+1)/2]);
    }
}
int left_child(int x){

}
int main() {
    int r,n,ele,index;
    printf("Enter number of nodes:--");
    scanf("%d",&n);
    printf("Enter the value for root");
    scanf("%d",&r);
    bt[1]=r;
    for(int i = 2;i<=n;i++){
        printf("Enter the value");
        scanf("%d",&bt[i]);count++;
    }
    for(int i=1;i<=count;i++){
        printf("%d\t",bt[i]);
    }
    printf("\n");
    printf("Enter the position to find root node:--");
    scanf("%d",&ele);
    getparent(ele);

    return 0;
}