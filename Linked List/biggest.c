#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void print()
{
    struct node *ptr = head->next;

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

void search()
{
    struct node *temp = head->next;
    int max = temp->data;
    int min = temp->data;

    printf("\nThe linked list is\n");
    print();

    while (temp != NULL)
    {

        if (temp->data >= max)
        {
            max = temp->data;
        }

        if (temp->data < min)
        {
            min = temp->data;
        }

        temp = temp->next;
    }

    printf("\nThe greatest element is: %d\n The lowest element is: %d", max, min);
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int n, i;
    printf("Enter no of nodes:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data of node %d:", i);
        scanf("%d", &new->data);

        temp->next = new;
        temp = temp->next;
    }

    temp->next = NULL;

    search();
}