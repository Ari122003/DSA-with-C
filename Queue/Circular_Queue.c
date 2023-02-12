#include <stdio.h>

#define max 3
int arr[max], r = -1, f = -1;

void enqueue()
{
    if ((r == -1) && (f == -1))
    {
        r = 0;
        f = 0;

        printf("Enter data:");
        scanf("%d", &arr[r]);
    }

    else if ((r + 1) % max == f)
    {
        printf("OVERFLOWED");
    }

    else
    {

        r = (r + 1) % max;
        printf("Enter data:");
        scanf("%d", &arr[r]);
    }
}

void dequeue()
{

    if ((r == -1) && (f == -1))
    {
        printf("UNDERFLOWED");
    }

    else if (f == r)
    {

        printf("The poped element is %d", arr[f]);
        r = -1;
        f = -1;
    }

    else
    {
        printf("The poped element is %d", arr[f]);
        f = (f + 1) % max;
    }
}

void display()
{
    if ((r == -1) && (f == -1))
    {
        printf("EMPTY");
    }

    else
    {
        int i = f;

        while (i <= r)
        {
            printf("%d\t", arr[i]);
            i = (i + 1) % max;
        }
    }
}

int main()
{
    // printf("Enter the size:");
    // scanf("%d", &n);

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