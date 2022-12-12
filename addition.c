#include <stdio.h>
int main()
{
    int a[10][10], b[10][10], c[10][10], i, j, k, r1, r2, c1, c2;
    printf("Enter Size of matrix 1 \n");
    scanf("%d %d", &r1, &c1);
    printf("Enter Size of matrix 2 \n");
    scanf("%d %d", &r2, &c2);
    if (r2 == r1 && c1 == c2)
    {
        printf("Enter values for matrix 1\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("Enter values for matrix 2\n");
        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        printf("The resultant matrix is \n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d \t", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The matrices cannot be added\n");
    }

    return 0;
}