#include <stdio.h>

int checker(int x)
{

    if (x < 5)
        return 1;
    else
        return 0;
}

void teller(int x)
{
    if (checker(x) == 1)
        printf("YESS");
    else
        printf("NO");
}

int main()
{

    int a;
    printf("Enter no");
    scanf("%d", &a);

    teller(a);
}