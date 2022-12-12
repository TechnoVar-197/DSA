#include<stdio.h>
int main (){
    int i,n;
    float sum=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        sum+=(1/(i*i));
    }
    printf("Sum is %f",sum);
    return 0;
}