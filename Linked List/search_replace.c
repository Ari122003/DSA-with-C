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
    printf("\nThe linked list is\n");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

void search()
{
    int x;
    printf("\nEnter the value you want to replace:");
    scanf("%d", &x);
    struct node *p1, *p2;

    p1 = head;
    p2 = head->next;

    while (p2 != NULL)
    {
        if (p2->data == x)
        {
            p1->next = p2->next;
            p2->next = head->next;
            head->next = p2;
            break;
        }

        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    if (p2 == NULL)
    {
        printf("OOPS!!NOT FOUND");
    }
}

int main()
{
    int i, n;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the no of nodes:");
    scanf("%d", &n);
    struct node *temp;

    temp = head;
    for (i = 1; i <= n; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("Ender data of node %d:", i);
        scanf("%d", &new->data);
        temp->next = new;
        temp = temp->next;
    }

    temp->next = NULL;

    print();
    search();
    print();
}