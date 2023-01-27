#include <stdio.h>

int main()
{

    int i, j, n, arr[50], help[50], c;

    printf("Size\n");
    scanf("%d", &n);

    printf("Enter elements\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        help[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        c = 1;

        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (arr[i] == arr[j])
                {

                    c++;
                    help[j] = 0;
                }
            }
        }
        if (help[i] != 0)
        {
            help[i] = c;
        }

        if (help[i] != 0)
            printf("Frequency of %d is %d\n", arr[i], c);
    }
}