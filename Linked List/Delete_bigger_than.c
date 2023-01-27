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

void delete ()
{
    int x;
    printf("\nEnter the value:");
    scanf("%d", &x);

    struct node *p = head, *q = head->next;

    printf("\nThe linked list before deletion\n");
    print();

    while (q != NULL)
    {
        if (q->data > x)
        {
            p->next = q->next;
            q = p->next;
        }
        else
        {
            q = q->next;
            p = p->next;
        }
    }

    printf("\nThe linked list after deletion\n");
    print();
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int n, i;
    printf("Enter the number of nodes:");
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

    delete ();
}