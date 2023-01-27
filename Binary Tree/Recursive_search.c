#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// LINKER FUNCTION

void linker(struct node *temp, struct node *new)
{
    printf("\nPRESS R TO INSERT AT RIGHT %d OF AND L TO INSERT LEFT OF %d:", temp->data, temp->data);
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

// TRAVERSAL FUNCTION

void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d\t", temp->data);
        inorder(temp->right);
    }
}

// SEARCH FUNCTION

struct node *recursive_search(struct node *temp, int num)
{
    if (temp == NULL)
        return NULL;
    else if (temp->data == num)
        return temp;
    else if (num < temp->data)
        return recursive_search(temp->left, num);
    else
        return recursive_search(temp->right, num);
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

        printf("\nPRESS 1 TO PROCEED FURTHER AND 0 TO STOP:");
        scanf("%d", &a);
    } while (a == 1);

    printf("\nInorder traversal is\n");
    inorder(root);
    int x;
    printf("\nEnter the value to search:");
    scanf("%d", &x);
    struct node *result = recursive_search(root, x);

    if (result != NULL)
        printf("\nFOUND %d\n", result->data);
    else
        printf("\nNOT FOUND\n");
}