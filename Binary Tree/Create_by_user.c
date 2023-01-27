#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

void linker(struct node *root, struct node *new)
{
    char x;
    printf("\nWhere to insert?\nPress\n R to insert at right and L to insert at left of %d\n", root->data);

    x = getch();

    if (x == 'R' || x == 'r')
    {
        if (root->right == NULL)
        {
            root->right = new;
        }
        else
        {
            linker(root->right, new);
        }
    }

    if (x == 'L' || x == 'l')
    {
        if (root->left == NULL)
        {
            root->left = new;
        }
        else
        {
            linker(root->left, new);
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
int main()
{
    struct node *root = NULL;
    int a;

    do
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->left = NULL;
        new->right = NULL;
        printf("\nEnter data:");
        scanf("%d", &new->data);

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

    }

    while (a == 1);

    preorder(root);
}