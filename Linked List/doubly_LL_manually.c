#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;

void print()
{
    struct node *ptr = head->next;
    printf("Your linked list is\n");

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));

    head->next = first;

    first->prev = NULL;
    first->data = 2;
    first->next = second;

    second->prev = first;
    second->data = 4;
    second->next = third;

    third->prev = second;
    third->data = 6;
    third->next = NULL;

    print();
}