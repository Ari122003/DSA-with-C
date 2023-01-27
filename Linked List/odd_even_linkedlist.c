#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *head1;

void print(struct node *ptr)
{

        while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

void extract()
{

    struct node *p1, *p2, *ptr;
    p1 = head;
    p2 = head->next;
    ptr = head1;

    while (p2 != NULL)
    {
        if ((p2->data) % 2 == 0)
        {
            p1->next = p2->next;
            ptr->next = p2;
            ptr = ptr->next;
            p2 = p1->next;

            if (p2 == NULL)
                break;
        }

        p1 = p1->next;
        p2 = p2->next;
    }
    ptr->next = NULL;
}

int main()
{
    int i, n;
    printf("Enter the no of nodes:");
    scanf("%d", &n);
    head = (struct node *)malloc(sizeof(struct node));
    head1 = (struct node *)malloc(sizeof(struct node));

    struct node *temp = head;

    for (i = 1; i <= n; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of node %d:", i);
        scanf("%d", &new->data);

        temp->next = new;
        temp = temp->next;
    }

    temp->next = NULL;
    print(head->next);
    extract();
    printf("\nThe odd list is\n");
    print(head->next);
    printf("\nThe even list is\n");
    print(head1->next);
}