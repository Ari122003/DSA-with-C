#include <stdio.h>

int arr[50], n, r = -1, f = -1;

void enqueue()
{
    if (r == n - 1)
        printf("\nOVERFLOWED\n");

    else if (r == -1)
    {
        f = 0;
        r = 0;
        printf("\nEnter data to insert:");
        scanf("%d", &arr[r]);
    }

    else
    {
        r++;
        printf("\nEnter data to insert:");
        scanf("%d", &arr[r]);
    }
}

void dequeue()
{
    if (f == -1)
        printf("\nUNDERFLOWED\n");

    else if (f == r)
    {
        printf("\nThe deleted element is:%d", arr[f]);
        r = -1;
        f = -1;
    }

    else
    {
        printf("\nThe deleted element is:%d", arr[f]);
        f++;
    }
}

void display()
{
    int i;

    if (r == -1)
        printf("\nQueue is empty\n");

    else
    {
        for (i = f; i <= r; i++)
        {
            printf("%d\t", arr[i]);
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