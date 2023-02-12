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

    int low = 0, mid, high = n - 1, x;

    printf("Enter the element:");
    scanf("%d", &x);

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            printf("FOUND");
            return;
        }

        else if (x > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("NOT FOUND");
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