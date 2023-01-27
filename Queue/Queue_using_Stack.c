#include <stdio.h>
int a[50], b[50], p = -1, q = -1, n;

void enqueue()
{
    if (p == n - 1)
        printf("\nOVERFLOWED\n");

    else
    {
        p++;

        printf("\nEnter the value to insert:");
        scanf("%d", &a[p]);
    }
}

void dequeue()
{
    if (q == -1)
        printf("\nUNDERFLOWED\n");

    else
    {
        printf("\nThe deleted element is:%d", b[q]);
        q--;
        p--;
    }
}

void display()
{
    if (q == -1)
    {
        printf("\nQueue is empty\n");
    }

    else
    {
        int i;
        printf("\nThe Queue is\n");
        for (i = q; i <= 0; i--)
        {
            printf("%d\t", b[q]);
        }
    }
}

int main()
{
    printf("Enter the size of the Queue:");
    scanf("%d", &n);

    int a, b;
    do
    {
        printf("Press\n1 to enqueue\n2 to dequeue\n3 to display\n");
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

        printf("\nWill you continue?\n press\n1 for yes\n0 for no\n");
        scanf("%d", &b);

    }

    while (b == 1);
}