#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *temp;
int n, i;

void enqueue()
{
    if (i <= n)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data to insert:");
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

void dequeue()
{
    if (head->next == NULL)
    {
        printf("\nUNDERFLOWED\n");
    }

    else
    {
        printf("\nThe deleted element is:%d", (head->next)->data);
        head->next = (head->next)->next;
    }

    if (head->next == NULL)
    {
        temp = head;
        i = 1;
    }
}

void display()
{
    if (head->next == NULL)
    {
        printf("\nQUEUE IS EMPTY\n");
    }

    else
    {
        struct node *temp = head->next;
        printf("\nTHE QUEUE IS\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    temp = head;
    printf("Enter size of the Queue:");
    scanf("%d", &n);
    i = 1;

    int a, b;

    do
    {
        printf("\nPRESS\n 1 FOR INSERT ELEMENT \n 2 FOR DELETE ELEMENT\n 3 TO DISPLAY\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;
        }

        printf("\nWILL YOU CONTINUE?");
        printf("\nPRESS 1 FOR YES 0 FOR NO:");
        scanf("%d", &b);

    } while (b == 1);
}