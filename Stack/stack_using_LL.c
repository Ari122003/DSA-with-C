#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *temp;
int i, n;

void push()
{
    if (i < n)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data to push:");
        scanf("%d", &new->data);
        temp->next = new;
        temp = temp->next;
        temp->next = NULL;
        i++;
    }

    else
    {
        printf("\nOVERFLOWED\n");
    }
}

void pop()
{
    if (head->next == NULL)
        printf("\nUNDERFLOWED\n");

    else
    {
        struct node *p = head;
        struct node *q = head->next;

        while (q->next != NULL)
        {
            q = q->next;
            p = p->next;
        }
        p->next = NULL;
        printf("\nThe poped element is:%d", q->data);
        temp = p;
        i--;
    }
}

void display()
{
    if (head->next == NULL)
        printf("\nThe stack is empty\n");

    else
    {
        struct node *ptr = head->next;
        printf("\nThe stack is\n");

        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    temp = head;
    printf("Enter the size of the stack:");
    scanf("%d", &n);
    i = 0;

    int a, b;

    do
    {
        printf("\nPress\n1 to push\n2 to pop\n3 to display\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        }

        printf("\nWill you continue?\n press\n1 for yes\n0 for no\n");
        scanf("%d", &b);

    } while (b == 1);
}