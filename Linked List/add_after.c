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

void insert()
{
    int x;
    printf("\nEnter the element after which the new element will be added:");
    scanf("%d", &x);

    struct node *temp = head;

    printf("\nThe linked list before insertion\n");
    print();

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter data:");
            scanf("%d", &new->data);

            new->next = temp->next;
            temp->next = new;
            break;
        }

        else
        {
            temp = temp->next;
        }
    }

    printf("\nThe linked list after insertion\n");
    print();
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
        printf("\nEnter data of node%d:", i);
        scanf("%d", &new->data);

        temp->next = new;
        temp = temp->next;
    }

    temp->next = NULL;

    int a, b;

    do
    {
        insert();

        printf("\nWILL YOU CONTINUE\nPRESS\n1 TO YES\n0 TO NO\n");
        scanf("%d", &b);

    } while (b == 1);

    printf("WELCOME");
}
