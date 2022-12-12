#include<stdio.h>
struct stud
{
    char name[20];
    char rollno[20];
    float marks[7];
    float per;
};
int main() {
    int i,n,j,temp; struct stud S1;
    int sum=0;
    printf("Enter name of student ");
        scanf("%s",S1.name);
        printf("Enter rollno of student ");
        scanf("%s",S1.rollno);
        printf("Enter marks of student ");
        for (j=0;j<7;j++){
            scanf("%d",&S1.marks[j]);
            sum+=S1.marks[j];
        }
        S1.per=sum/7;
        printf("%f",S1.per);
    return 0;
}