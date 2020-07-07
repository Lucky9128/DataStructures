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

void delete(struct node *root,int val)
{
    struct node *cur = root;
    struct node *pre;
    printf("Searching for started:\n");
    while(cur->val!=val)
    {
        printf("%d\n",cur->val);
        pre=cur;
        if(pre->val<val)
        {
            cur = pre->right;
        }
        else
        {
            cur = pre->left;
        }
    }
    if(cur->left ==NULL && cur->right==NULL)
    {
        if(pre->val < val)
            pre->right==NULL;
        else
            pre->left==NULL;
    }
    else if(cur->left == NULL)
    {
        printf("sdss\n");
        if(pre->val<val)
        {
        printf("sds3s\n");
            pre->right = cur->right;
        }
        else
        {
        printf("sdss4\n");
            pre->left = cur->right;   
        }
    }
    else if(cur->right == NULL)
    {
        printf("sds2s\n");
        if(pre->val<val)
        {
            pre->right = cur->left;
        }
        else
        {
            pre->left = cur->left;   
        }
    }   
    else
    {
        struct node pre2=pre;
        pre = cur->left;
        while(pre->right!=NULL)
        {
            pre2 = pre;
            pre = pre->right;
        }
        if(pre->left==NULL)
        {
            cur->val = pre->val;
            pre2->right = NULL;
        }
        else 
        {
            cur->val = pre->val;
            pre = pre->left;
            
        }
    }

    
}

void main()
{
    struct node *root = NULL;
    int arr[] = {10,5,15,12,7,4,13,11,17,16,18,22,19,21};

    for(int i=0;i<14;i++)
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
        printf("\n----------------\n");
    // preorder(root);
    //     printf("\n----------------\n");
    // postorder(root);
    //     printf("\n----------------\n");
    delete(root,18);

    inorder(root);
        printf("\n----------------\n");
}