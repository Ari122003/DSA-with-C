#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void linker(struct node *temp, struct node *new)
{
    printf("\nPRESS\n R TO INSERT AT RIGHT OF %d\n L TO INSERT LEFT OF %d\n", temp->data, temp->data);
    char x = getch();

    if (x == 'L' || x == 'l')
    {
        if (temp->left == NULL)
            temp->left = new;
        else
            linker(temp->left, new);
    }
    if (x == 'R' || x == 'r')
    {
        if (temp->right == NULL)
            temp->right = new;
        else
            linker(temp->right, new);
    }
}

void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d\t", temp->data);
        inorder(temp->right);
    }
}

int search(struct node *temp, int num)
{
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return temp->data;
        }

        else if (num < temp->data)
        {
            temp = temp->left;
        }

        else
        {
            temp = temp->right;
        }
    }
}

int main()
{
    struct node *root = NULL;
    int a;

    do
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d", &new->data);
        new->left = NULL;
        new->right = NULL;

        if (root == NULL)
        {
            root = new;
        }

        else
        {
            linker(root, new);
        }

        printf("\nPRESS\n 1 TO PROCEED FURTHER\n 0 TO STOP\n");
        scanf("%d", &a);
    }

    while (a == 1);

    inorder(root);

    int n;
    printf("\nEnter the value to search\n");
    scanf("%d", &n);
    if (search(root, n) == n)
    {
        printf("\nFOUND %d", n);
    }
    else
    {
        printf("\nNOT FOUND");
    }
}