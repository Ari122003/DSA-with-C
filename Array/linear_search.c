#include <stdio.h>

int arr[], n;

void display()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void search()
{
    int i = 0, x;
    printf("Enter the element:");
    scanf("%d", &x);

    while (i < n)
    {
        if (arr[i] == x)
        {
            printf("FOUND");
            break;
        }

        else
        {
            i++;
        }
    }

    if (i == n)
    {
        printf("NOT FOUND");
    }
}

int main()
{
    printf("Enter the size:");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter data:");
        scanf("%d", &arr[i]);
    }

    display();
    search();
}