#include<stdio.h>
#include<stdlib.h>

 
struct node
{
    int val;
    struct node *left,*right;
};


void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->val);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->val);
    }
}

struct node * insert(struct node *root, struct node *new)
{
    if(root==NULL)
    {
        // printf("adding root\n");
        return new;
    }
    if(root->val >= new->val)
    {
        // printf("adding left\n");
        root->left = insert(root->left,new);
        return root;
    }
    if(root->val < new->val)
    {
        // printf("adding right\n");
        root->right = insert(root->right,new);
        return root;
    }
}

void main()
{
    struct node *root = NULL;
    int arr[] = {10,5,15,12,7,4,13,11};

    for(int i=0;i<8;i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val = arr[i];
        temp->left=NULL;
        temp->right=NULL;
        root = insert(root,temp);
        // inorder(root);
        // printf("----------------\n");
    }
    inorder(root);
        printf("----------------\n");
    preorder(root);
        printf("----------------\n");
    postorder(root);
        printf("----------------\n");
}