#include<stdio.h>
struct stud {
    char name[20];
    char rollno[20];
    float marks[7];
    float per;
};
int main() {
    int i,n,j,temp=0; struct stud S[100];
    float sum=0;
    printf("Enter the number of students:--");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter name of student %d:--",i+1);
        scanf("%s",S[i].name);
        printf("Enter rollno of student %d:--",i+1);
        scanf("%s",S[i].rollno);
        for (j=0;j<7;j++){
            printf("Enter marks for subject %d student %d:--",j+1,i+1);
            scanf("%f",&S[i].marks[j]);
            sum+=S[i].marks[j];
        }
        S[i].per=sum/7;
        printf("The percentage of Student is %.2f\n",S[i].per);
    }

    return 0;
}