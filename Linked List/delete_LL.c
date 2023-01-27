#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void delete_form_first()
{
    struct node *temp = head;
    printf("\nThe linked list before insertion\n");
    display();

    temp->next = (temp->next)->next;

    printf("\nThe linked list after insertion\n");
    display();
}

void delete_from_any_point()
{

    struct node *temp = head;

    int x, i = 1;
    printf("Enter position\n");
    scanf("%d", &x);
    printf("\nThe linked list before insertion\n");
    display();
    while (temp != NULL)
    {

        if (i == x)
        {
            temp->next = (temp->next)->next;
            break;
        }

        else
        {
            temp = temp->next;
            i++;
        }
    }

    printf("\nThe linked list after insertion\n");
    display();
}

void delete_from_last()
{

    struct node *temp = head;
    printf("\nThe linked list before insertion\n");
    display();
    while ((temp->next)->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = NULL;

    printf("\nThe linked list after insertion\n");
    display();
}

int main()
{
    int i, n;
    head = (struct node *)malloc(sizeof(struct node));

    struct node *temp = head;
    printf("Enter the size of the list\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d", &new->data);

        temp->next = new;
        temp = temp->next;
    }

    temp->next = NULL;

    int a, b;

    do
    {
        printf("\n1 TO DELETE FROM FIRST\n2 FOR DELETE FROM ANY POINT\n3 TO DELETE FORM LAST\n");
        scanf("%d", &a);

        switch (a)
        {

        case 1:
            delete_form_first();
            break;

        case 2:
            delete_from_any_point();
            break;

        case 3:
            delete_from_last();
            break;
        }

        printf("\nWILL YOU CONTINUE?");
        printf("\nPRESS 1 FOR YES 0 FOR NO:");
        scanf("%d", &b);

    }

    while (b == 1);
    printf("\nWELCOME");
}