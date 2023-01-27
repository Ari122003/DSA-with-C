#include <stdio.h>
int arr[50], r = 0, f = 0, n;

void enqueue()
{
    if ((r + 1) % n == f)
    {
        printf("\nOVERFLOWED\n");
    }

    else
    {
        r = (r + 1) % n;
        printf("\nEnter data\n");
        scanf("%d", &arr[r]);
    }
}

void dequeue()
{
    if (r == f)
    {
        printf("\nUNDERFLOWED\n");
    }

    else
    {
        printf("\nThe deleted element is: %d", arr[f]);
        f = (f + 1) % n;
    }
}

void display()
{
    if (r == f)
}

int main()
{
    printf("Enter the size of the Queue\n");
    scanf("%d", &n);
}
