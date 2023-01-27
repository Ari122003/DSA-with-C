#include <stdio.h>
int arr[50], n, x, e, i;

// insertion

void insert(int n)
{

    printf("Enter the position where the element will be inserted:");
    scanf("%d", &x);

    if (x < n)
    {

        printf("Enter the element to be inserted:");
        scanf("%d", &e);
        printf("Array before insertion\n");
        for (i = 0; i <= n - 1; i++)
        {
            printf("%d\t", arr[i]);
        }
        for (i = n - 1; i >= x; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[x] = e;

        printf("\n");
        printf("Array after insertion\n");

        for (i = 0; i <= n; i++)
        {
            printf("%d\t", arr[i]);
        }
    }

    else
        printf("ERROR!!!!, SIZE OF THE ARRAY IS %d", n);
}

// deletion
void delete (int n)
{
    printf("Enter the position where the element will be deleted:");
    scanf("%d", &x);
    if (x < n)
    {

        printf("Array before deletion\n");
        for (i = 0; i <= n - 1; i++)
        {
            printf("%d\t", arr[i]);
        }
        for (i = x; i <= n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("\n");
        printf("Array after deletion\n");
        for (i = 0; i <= n - 2; i++)
        {
            printf("%d\t", arr[i]);
        }
    }

    else
        printf("ERROR!!!!, SIZE OF THE ARRAY IS %d", n);
}

// binary search

void search(int n)
{
    int c = 0, low, mid, high;
    low = 0;
    high = n - 1;
    printf("Enter the element to be searched:");
    scanf("%d", &e);

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == e)
        {
            printf("Element %d is found at position %d", e, mid);
            c++;
        }
        if (arr[mid] < e)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (c == 0)
    {
        printf("ERROR, ELEMENT NO FOUND!!!!!");
    }
}

int main()
{
    int a, b;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter array elements\n");

    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("PRESS\n 1 FOR INSERTION\n 2 FOR DELETION\n 3 FOR BINARY SEARCH\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        insert(n);
        break;

    case 2:
        delete (n);
        break;

    case 3:
        search(n);
        break;
    }
}