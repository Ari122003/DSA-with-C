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
    printf("\nPRESS\nL TO INSERT LEFT OF %d\nR TO INSERT RIGHT OF %d\n", temp->data, temp->data);
    char x = getch();

    if (x == 'l' || x == 'L')
    {
        if (temp->left == NULL)
        {
            temp->left = new;
        }
        else
        {
            linker(temp->left, new);
        }
    }

    if (x == 'r' || x == 'R')
    {
        if (temp->right == NULL)
        {
            temp->right = new;
        }
        else
        {
            linker(temp->right, new);
        }
    }
}

void preorder(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d\t", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void insert(struct node *temp)
{
    struct node *prev = NULL;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->left = NULL;
    new->right = NULL;
    printf("\nEnter the data to insert\n");
    scanf("%d", &new->data);

    while (temp != NULL)
    {
        prev = temp;
        if (temp->data == new->data)
        {
            break;
            printf("\nItem is already aviable\n");
        }

        else if (new->data < temp->data)
        {
            temp = temp->left;
        }

        else
        {
            temp = temp->right;
        }
    }

    if (new->data < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    struct node *root = NULL;
    int a;

    do
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data\n");
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
        printf("\nWILL YOU CONTINUE?");
        printf("\nPRESS 1 FOR YES 0 FOR NO:");
        scanf("%d", &a);
    } while (a == 1);

    printf("\nTree before insertion\n");
    preorder(root);
    insert(root);
    printf("\nTree after insertion\n");
    preorder(root);
}