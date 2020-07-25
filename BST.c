#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

 
struct node
{
    int val;
    struct node *left,*right;
};

struct node * GetNewNode(int val)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->left=NULL;
    temp->right =NULL;
    return temp;
}

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

//insertion with recursion
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

//insertion with iteration
struct node * insert2(struct node *root, int val)
{
    if(root==NULL)
    {
        root  = GetNewNode(val);
        return root; 
    }

    struct node *temp = root;
    while(1)
    {
        if(temp->val>val)
        {
            if(temp->left==NULL)
            {
                // printf("Adding %d to %d\n",val,temp->val);
                temp->left = GetNewNode(val);
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if(temp->right==NULL)
            {
                // printf("Adding %d to %d\n",val,temp->val);
                temp->right = GetNewNode(val);
                break;
            }
            else
                temp = temp->right;
        }   
    }
    return root;
}


struct node * delete(struct node *root,int val)
{
    struct node *cur = root;
    struct node *pre =NULL;
    // printf("Searching for started:\n");
    while(cur->val!=val)
    {
        // printf("%d\n",cur->val);
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
    // printf("found the node\n");
    if(cur->left ==NULL && cur->right==NULL)
    {
        // printf("Node has no child\n");
        if(pre == NULL)
        {
            root = NULL;

        }
        else if(pre->val < val)
        {
            pre->right=NULL;
        }
        else
        {
            pre->left=NULL;
        }
    }
    else if(cur->left == NULL)
    {
        // printf("Node has only right child\n");
        if(pre == NULL)
        {
            // printf("removing root node\n");
            pre = cur->right;
            cur->val=pre->val;
            cur->left = pre->left;
            cur->right = pre->right;
            free(pre);
        }
        else if(pre->val<val)
        {
        // printf("sds3s\n");
            pre->right = cur->right;
        }
        else
        {
        // printf("sdss4\n");
            pre->left = cur->right;   
        }
    }
    else if(cur->right == NULL)
    {
        // printf("Node has only left child\n");   
        if(pre == NULL)
        {
            // printf("removing root node\n");
            pre = cur->left;
            cur->val=pre->val;
            cur->left = pre->left;
            cur->right = pre->right;
            free(pre);
        }
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
        struct node *pre2=pre;
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
    return root;
}

void main()
{
    for(int j=1;j<=pow(2,19);j*=2)
    {   
        FILE *fp = fopen("By Recursion.txt","a");
        // FILE *log = fopen("log.txt","w");
        struct node *root = NULL;
        // root = insert2(root,32); 
        clock_t begin = clock();
        for(int i=0;i<j;i++)
        {
            root=insert(root,GetNewNode(i));
            // root = insert(root,GetNewNode(i));
        }
        // for(int i=j-1;i>=0;i--)
        // {
        //     root = delete(root,i);
        //     // inorder(root);
        //     // printf("\n");
        //     // root = insert(root,GetNewNode(i));
        // }
        clock_t end = clock();
        double ts = (double)(end -begin)/CLOCKS_PER_SEC;
        fprintf(fp,"%d %lf\n",j,ts);
        printf("%d %lf\n",j,ts);
        fclose(fp);
    }
    // inorder(root);
    //     printf("\n----------------\n");
    // preorder(root);
    //     printf("\n----------------\n");
    // postorder(root);
    //     printf("\n----------------\n");
    // delete(root,18);
    // inorder(root);
    //     printf("\n----------------\n");
}