#include<stdio.h>
int main() {
    int arr1[1000],n,i,j,temp;
    printf("Enter number of terms:--");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for (i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if (arr1[i]>arr1[j]){
                temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
            }
        }
    }
    printf("Sorted array\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr1[i]);
    }
    return 0;
}