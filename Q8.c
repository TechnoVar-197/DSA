#include<stdio.h>
int main (){
    int i,rev,n,x,org;
    rev=0;
    scanf("%d",&n);
    org=n;
    while(n!=0){
        x=n%10;
        rev+=(x*x*x);
        n=(int)n/10;
    }
    if (org==rev){
        printf("The Number is Amstrong number\n");
    }
    else {
        printf("The Number is not Amstrong number\n");
    }
    return 0;
}