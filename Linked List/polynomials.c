#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int power;
    struct node *next;
};

struct node *head1;
struct node *head2;
struct node *head3;

void print(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%dx^%d\t", ptr->coef, ptr->power);
        ptr = ptr->next;
    }
}

void add()
{
    struct node *temp1 = head1->next;
    struct node *temp2 = head2->next;
    struct node *temp3 = head3;

    while (temp1 || temp2 != NULL)
    {
        if (temp1->power == temp2->power)
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));

            new->coef = temp1->coef + temp2->coef;
            new->power = temp1->power;

            temp3->next = new;
            temp3 = temp3->next;
            temp3->next = NULL;
        }

        else if (temp1->power > temp2->power)
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->coef = temp1->coef;
            new->power = temp1->power;

            temp3->next = new;
            temp3 = temp3->next;
            temp3->next = NULL;

            struct node *new1 = (struct node *)malloc(sizeof(struct node));
            new1->coef = temp2->coef;
            new1->power = temp2->power;

            temp3->next = new1;
            temp3 = temp3->next;
            temp3->next = NULL;
        }

        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->coef = temp2->coef;
            new->power = temp2->power;

            temp3->next = new;
            temp3 = temp3->next;
            temp3->next = NULL;

            struct node *new1 = (struct node *)malloc(sizeof(struct node));
            new1->coef = temp1->coef;
            new1->power = temp1->power;

            temp3->next = new1;
            temp3 = temp3->next;
            temp3->next = NULL;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

int main()
{
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head3 = (struct node *)malloc(sizeof(struct node));
    struct node *p = head1;
    struct node *q = head2;

    int m, n, i, j;

    printf("Enter the number of terms of 1st polynomial:");
    scanf("%d", &m);

    for (i = 1; i <= m; i++)
    {
        struct node *new1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter coefficient of term %d:", i);
        scanf("%d", &new1->coef);

        printf("Enter power of variable of term %d:", i);
        scanf("%d", &new1->power);

        p->next = new1;
        p = p->next;
    }

    p->next = NULL;

    printf("Enter the number of terms of 2nd polynomial:");
    scanf("%d", &n);

    for (j = 1; j <= m; j++)
    {
        struct node *new2 = (struct node *)malloc(sizeof(struct node));
        printf("Enter coefficient of term %d:", j);
        scanf("%d", &new2->coef);

        printf("Enter power of variable of term %d:", j);
        scanf("%d", &new2->power);

        q->next = new2;
        q = q->next;
    }

    q->next = NULL;

    printf("\nThe 1st polynomial is\n");
    print(head1->next);
    printf("\nThe 2nd polynomial is\n");
    print(head2->next);
    printf("\nPolynomial after adding\n");
    add();
    print(head3->next);
}