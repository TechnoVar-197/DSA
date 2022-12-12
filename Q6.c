#include<stdio.h>
int main (){
    int i,rev,n,x;
    rev=0;
    scanf("%d",&n);
    while(n!=0){
        x=n%10;
        rev=rev*10+x;
        n=(int)n/10;
    }
    printf("reverse of number is %d",rev);
    return 0;
}