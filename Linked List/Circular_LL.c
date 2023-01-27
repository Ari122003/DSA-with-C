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
    struct node *temp = head->next;

    while (temp != head)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));

    struct node *temp = head;
    int n, i;

    printf("Enter size\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &new->data);

        temp->next = new;
        temp = temp->next;
    }

    temp->next = head;

    print();
}