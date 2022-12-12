#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *next;
};
struct node *head = NULL;
void insertatfirst(struct node **head, int element)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->element = element;
    new->next = (*head);
    (*head) = new;
}
void insertatlast(struct node **head, int element)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head;
    new->element = element;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    return;
}
void printList()
{
    struct node *node;
    node = head;
    while (node != NULL)
    {
        printf("%d\t", node->element);
        node = node->next;
    }
    printf("\n");
}
void create()
{
    int n, ele;
    printf("Enter of number of elements:--");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Value:--");
        scanf("%d", &ele);
        insertatlast(&head, ele);
    }
}
int main()
{
    int choice, ele;
start:
    printf("1.Create a linked list\n2.Insert a node at first position\n3.Display the linked List\n4.Exit\n");
    printf("Enter your choice:--");
    scanf("%d", &choice);
    switch (choice)
    {
    case (1):
        create();
        printf("Linked List After Creation:--\n");
        printList();
        goto start;
    case (2):
        printf("Enter the value of element:--");
        scanf("%d", &ele);
        insertatfirst(&head, ele);
        printf("Linked List After Insertation:--\n");
        printList();
        goto start;
    case (3):
        printList();
        goto start;
    case (4):
        printf("Program is exiting normally\n");
        exit(0);

    default:
        goto start;
    }
    return 0;
}