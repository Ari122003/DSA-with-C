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
    struct node *ptr;
    ptr = head->next;
    printf("YOUR LINKED LIST IS\n");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
void removeallbut()
{
    int i = 0, x;
    printf("\nNumber of node you want to keep:");
    scanf("%d", &x);
    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        if (i == x)
        {
            head->next = ptr;
            ptr->next = NULL;
            break;
        }

        else
        {
            i++;
            ptr = ptr->next;
        }
    }
}

int main()
{
    head = malloc(sizeof(struct node));
    struct node *temp;

    int n, i;
    printf("Enter the no of nodes:");
    scanf("%d", &n);

    temp = head;

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
    removeallbut();
    print();
}