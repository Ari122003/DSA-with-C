#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

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

// insert at first

void insert_at_first()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d", &new->data);
    printf("\nLinked list before insertion\n");
    print();

    new->next = head->next;
    head->next = new;
    new->prev = NULL;

    printf("\nLinked list after insertion\n");
    print();
}

// insert at any point

void insert_at_any_point()
{
    int x, i = 0;
    struct node *temp = head;
    printf("\nEnter the position of insertion:");
    scanf("%d", &x);

    while (temp != NULL)
    {

        if (i == x)
        {

            struct node *new = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data to insert");
            scanf("%d", &new->data);
            printf("\nLinked list before insertion\n");
            print();
            new->next = temp;
            (temp->prev)->next = new;
            temp->prev = new;

            break;
        }

        else
        {
            i++;
            temp = temp->next;
        }
    }
    printf("\nLinked list after insertion\n");
    print();
}

// insert at last

void insert_at_last()
{
    struct node *temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d", &new->data);
    printf("\nLinked list before insertion\n");
    print();

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
    new->prev = temp;
    new->next = NULL;

    printf("\nLinked list after insertion\n");
    print();
}

// delete from first

void delete_from_first()
{
    printf("\nLinked list before insertion\n");
    print();

    head->next = (head->next)->next;
    (head->next)->prev = NULL;

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
        printf("Enter the data of node %d:", i);
        scanf("%d", &new->data);

        temp->next = new;
        new->prev = temp;
        temp = temp->next;
    }

    temp->next = NULL;
    (head->next)->prev = NULL;

    delete_from_first();
    delete_from_first();
    delete_from_first();
    delete_from_first();
}