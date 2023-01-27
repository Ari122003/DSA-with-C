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
    printf("\nYour linked is\n");

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

void search()
{
    int c = 0, x;
    printf("\nEnter the element to be searched:");
    scanf("%d", &x);
    struct node *temp = head;

    while (temp != NULL)
    {

        if (temp->data == x)
        {
            printf("\nFOUND at node:%d", c);
            break;
        }

        else
        {
            temp = temp->next;
        }
        c++;
    }
}

int main()
{
    int n, i;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
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

    print();

    int a, b;
    do
    {

        printf("\nPRESS 1 TO SEARCH\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            search();
            break;
        }

        printf("\nWILL YOU CONTINUE?\nPRESS\n 1 TO YES\n0 TO NO\n");
        scanf("%d", &b);

    }

    while (b == 1);
}