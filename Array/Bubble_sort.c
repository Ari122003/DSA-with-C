#include <stdio.h>

int n, arr[100];

void print()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void sort()
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int i;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d:", i);
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting\n");
    print();

    sort();

    printf("\nArray after sorting\n");
    print();
}