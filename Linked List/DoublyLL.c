#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
struct node *temp;

void creat()
{

    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        temp->next = new;
        new->prev = temp;
        temp = new;
    }
}

void display()
{
    struct node *temp = head;

    printf("\nThe linked list is\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    temp = head;
    int a, b;

    do
    {
        printf("\nPress\n1 to push\n2 to display\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            creat();
            break;

        case 2:
            display();
            break;
        }

        printf("\nWill you continue?\n press\n1 for yes\n0 for no\n");
        scanf("%d", &b);

    } while (b == 1);
}