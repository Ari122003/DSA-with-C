#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node *creat(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
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

void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d\t", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t", temp->data);
    }
}

int main()
{
    root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;

    struct node *n1 = creat(3);
    struct node *n2 = creat(5);
    struct node *n3 = creat(7);
    struct node *n4 = creat(9);
    struct node *n5 = creat(11);
    struct node *n6 = creat(13);

    root->left = n1;
    n1->left = n2;
    n1->right = n3;

    root->right = n4;
    n4->left = n5;
    n4->right = n6;
    printf("\nThe inorder traversal is\n");
    inorder(root);
    printf("\nThe preorder traversal is\n");
    preorder(root);
    printf("\nThe postorder traversal is\n");
    postorder(root);
}
