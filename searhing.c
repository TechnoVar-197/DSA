#include<stdio.h>
int main() {
    int arr1[1000],n,i,pos=-1,val;
    printf("Enter number of terms:--");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter value to be found:--");
    scanf("%d",&val);
    for(i=0;i<n;i++){
        if (arr1[i]==val){
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
    return 0;
}