#include<stdio.h>
#include<stdlib.h>
typedef struct bstNode{
    int data;
    struct bstNode *left;
    struct bstNode *right;
}node;

//insert function
node* insert(node* root,int value)
{
    if(root==NULL)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    }
    if(value<root->data)    root->left=insert(root->left,value);
    if(value>=root->data)   root->right=insert(root->right,value);
    return root;
}
//delete function
node* delete(node* root,int value)
{
    if(root==NULL)  return root;
    else if(value<root->data)   root->left=delete(root->left,value);
    else if(value>root->data)   root->right=delete(root->right,value);
    else
    {
        node* ptr;
        if(root->right==NULL)
        {
            ptr = root;
            root = root->left;
            free(ptr);
        }
        else if(root->left==NULL)
        {
            ptr = root;
            root = root->right;
            free(ptr);
        }
        else
        {
            //inorder succesor
            ptr = root->left;
            while(ptr->right!=NULL)
            {
                ptr = ptr->right;
            }
            root->data=ptr->data;
            root->left = delete(root->left,ptr->data);
        }
        return root;
    }
}
//print max and min function
void printmaxmin(node* root)
{
    node* ptr = root;
    while(ptr->left!=NULL) ptr = ptr->left;
    printf("min value: %d",ptr->data);
    ptr = root;
    while(ptr->right!=NULL) ptr = ptr->right;
    printf("max value: %d",ptr->data);
}
//reverse order print function
void printreverseorder(node* root)
{
    printreverseorder(root->right);
    printf("%d",root->data);
    printreverseorder(root->left);
}
//count total node
int count =0;
int totalnode(node* root)
{
    totalnode(root->left);
    count++;
    totalnode(root->right);
    return count;
}
//count total leaf
int leafcount=0;
int leafnode(node* root)
{
    leafnode(root->left);
    if(root->right==NULL&&root->right==NULL)    leafcount++;
    leafnode(root->right);
}
//count total sum of all nodes
int sum=0;
int totalsum(node* root)
{
    totalsum(root->left);
    sum+=root->data;
    totalsum(root->right);
}