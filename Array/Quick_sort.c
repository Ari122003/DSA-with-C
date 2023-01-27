#include <stdio.h>
int A[100], n;
void print()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int low, int high)
{
    int index;

    if (low < high)
    {
        index = partition(low, high);
        quicksort(low, index - 1);
        quicksort(index + 1, high);
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
        scanf("%d", &A[i]);
    }

    printf("\nArray before sorting\n");
    print();

    quicksort(0, n - 1);

    printf("\nArray after sorting\n");
    print();
}