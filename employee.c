#include <stdio.h>
struct employee
{
    char name[50];
    char ID[20];
    char pos[40];
    float salary;
};
int main()
{
    struct employee *ptr, S1;
    ptr = &S1;
    printf("Enter the Name  ");
    scanf("%s", ptr->name);
    printf("Enter the ID  ");
    scanf("%s", ptr->ID);
    printf("Enter the Position  ");
    scanf("%s", ptr->pos);
    printf("Enter the Salary  ");
    scanf("%f", &ptr->salary);
    printf("\nName:--%s\nID:--%s\npos:--%s\nSalary:--%.2f\n", ptr->name, ptr->ID, ptr->pos, ptr->salary);
    return 0;
}