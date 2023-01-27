#include <stdio.h>
int arr[50], p = -1, n;

void creat()
{
    int i;
    if (p == n - 1)
        printf("Array is full");

    else
    {
        for (i = 0; i < n; i++)
        {
            p++;
            printf("Enter element of position %d:", i);
            scanf("%d", &arr[i]);
        }
    }
}

void insert_at_any_position()
{
    int i, x;
    printf("\nEnter the position of insertion:");
    scanf("%d", &x);

    for (i = p; i >= x - 1; i--)
    {
        arr[i + 1] = arr[i];
    }

    printf("\nEnter the element to be inserted:");
    scanf("%d", &arr[x - 1]);
    p++;
}

void display()
{
    int i;
    printf("Array is\n");
    if (p == -1)
    {
        printf("Array is empty");
    }

    else
    {
        for (i = 0; i <= p; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}

int main()
{

    printf("ENTER THE SIZE:");
    scanf("%d", &n);

    int a, b;
    do
    {
        printf("\nPress\n1 to creat\n2 to insert at any position\n3 to display\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            creat();
            break;
        case 2:
            insert_at_any_position();
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