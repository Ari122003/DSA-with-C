#include <stdio.h>
#include <stdlib.h>
// Define structure
struct node
{
    int data;
    struct node *next;
};

// Define head
struct node *head;

// print function
void print()
{
    struct node *ptr = head->next;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

// insert at first function

void insertatfirst()
{
    struct node *temp;
    temp = head;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));

    printf("\nLinked list before insertion\n");
    print();

    printf("\nEnter data:");
    scanf("%d", &new->data);

    new->next = temp->next;
    temp->next = new;
    printf("Linked list after insertion\n");
    print();
}

// insert in between function

void insertinbetween()
{
    int i = 1, x;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position of insertion:");
    scanf("%d", &x);
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        if (i != x)
        {
            temp = temp->next;
            i++;
        }

        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            printf("Enter data:");
            scanf("%d", &new->data);

            printf("\nThe linked list before insertion\n");
            print();
            new->next = temp->next;
            temp->next = new;

            break;
        }
    }
    printf("\nThe linked list after insertion\n");
    print();
}

// insert at last function

void insertatlast()
{
    struct node *temp;
    temp = head;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));

    printf("\nLinked list before insertion\n");
    print();

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
    new->next = NULL;
    printf("\nEnter data:");
    scanf("%d", &new->data);

    printf("\nLinked list after insertion\n");
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
        printf("Enter data of node %d:", i);
        scanf("%d", &new->data);

        temp->next = new;
        temp = temp->next;
    }

    temp->next = NULL;

    int a, b;

    do
    {
        printf("\nPRESS\n 1 FOR INSERT ELEMENT AT FIRST\n 2 FOR INSERT ELEMENT AT MIDDLE\n 3 INSERT ELEMENT AT LAST\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            insertatfirst();
            break;

        case 2:
            insertinbetween();
            break;

        case 3:
            insertatlast();
        }

        printf("\nWILL YOU CONTINUE?");
        printf("\nPRESS 1 FOR YES 0 FOR NO:");
        scanf("%d", &b);

    }

    while (b == 1);
    printf("\nWELCOME");
}
