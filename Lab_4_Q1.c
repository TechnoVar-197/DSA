#include<stdio.h>
#define size 10
int main() {
    int a[size][size],b[size][size],c[size][size],i,j,k,r1,r2,c1,c2;
    printf("Enter the size of matrix 1 :--");
    scanf("%d %d",&r1,&c1);
    printf("Enter the size of matrix 2 :--");
    scanf("%d %d",&r2,&c2);
    if (r2==c1) {
        printf("enter the values for matrix 1:--\n");
        for (i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                scanf("%d",&a[i][j]);
            }
        }
        printf("enter the values for matrix 2:--\n");
        for (i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                scanf("%d",&b[i][j]);
            }
        }
        for (i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                c[i][j]=0;
                for (k=0;k<c1;k++){
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        printf("The resultant matrix :--\n");
        for (i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
        
    }
    else {
        printf("The matrix cannot be multiplied\n");
    }
    return 0;
}