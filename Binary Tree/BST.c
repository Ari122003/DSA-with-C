#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int bst(struct node *temp)
{
    static struct node *prev = NULL;
    if (temp != NULL)
    {
        if (!bst(temp->left))
        {
            return 0;
        }

        if (prev != NULL && temp->data <= prev->data)
        {
            return 0;
        }

        prev = temp;
        return bst(temp->right);
    }

    else
        return 1;
}

void checker(struct node *temp)
{
    if (bst(temp) == 1)
        printf("\nIT IS A BST");

    else
        printf("\nIT IS NOT A BST");
}

void linker(struct node *temp, struct node *new)
{
    printf("\nPRESS\nL TO INSERT LEFT OF %d\nR TO INSERT RIGHT OF %d\n", temp->data, temp->data);
    char x = getch();

    if (x == 'L' || x == 'l')
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
    if (x == 'R' || x == 'r')
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

void inorder(struct node *temp)
{

    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d\t", temp->data);
        inorder(temp->right);
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
        printf("\nWILL YOU CONTINUE?");
        printf("\nPRESS 1 FOR YES 0 FOR NO:");
        scanf("%d", &a);
    } while (a == 1);

    printf("\nThe inorder traversal is\n");
    inorder(root);
    checker(root);
}