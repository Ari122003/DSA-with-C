#include <stdio.h>
int arr[50], i = -1, n;

void push()
{
    if (i == n - 1)
        printf("OVER FLOWED");

    else
    {
        i++;
        printf("\nEnter data to push\n");
        scanf("%d", &arr[i]);
    }
}

void pop()
{
    if (i == -1)
        printf("UNDER FLOWED");

    else
    {
        printf("\nThe poped element is %d", arr[i]);
        i--;
    }
}

void display()
{
    int j;
    if (i == -1)
    {
        printf("Stack is empty");
    }

    else
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d\t", arr[j]);
        }
    }
}

int main()
{
    printf("Enter the size of the stack:");
    scanf("%d", &n);
    int a, b;
    do
    {
        printf("Press\n1 to push\n2 to pop\n3 to display\n");
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

    }

    while (b == 1);
}
