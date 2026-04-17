#include<stdio.h>
#include<stdlib.h>
typedef struct bst_node
{
    int info;
    struct bst_node *left,*right;  
}NODE;
NODE* insert(NODE* root, int value) //returns a pointer to a node and takes the root 
{
    if(root==NULL)
    {
        NODE* newnode = (NODE*)malloc(sizeof(NODE)); //declared a newnode
        newnode->info = value ; //set its info to value
        newnode->left = newnode->right = NULL; //it's a root no children
        root = newnode; //set the created newnode as root
    }
    else if(value<root->info) //to be set as left children
    {
        root->left = insert(root->left,value); //inserted the value in root left
    }
    else if(value>=root->info) // to be set as right children
    {
        root->right = insert(root->right,value); //inserted the value in root right
    }
    return root; // **IMPORTANT**
}
void search(NODE* root, int value)
{
    if(root==NULL) return;
    if(root->info==value)   printf("%d is present is the tree",root->info);
    if(value<root->info)    // search in the left tree
        search(root->left,value);
    if(value>root->info)    //search in the right treee
        search(root->right,value);
}
void display(NODE* root)
{
    // this is the inorder print
    if(root==NULL) return;
    if(root->left!=NULL)    display(root->left);
    printf("%d",root->info);
    if(root->right!=NULL)   display(root->right);
}
NODE* delete(NODE* root,int value)
{
    if(root==NULL) return NULL; //there is no tree 
    // search for the value recursively
    else if(value<root->info)    root->left = delete(root->left,value);
    else if(value>root->info)   root->right = delete(root->right,value);
    else    // when root is value (found) inorder succesor method
    {
        NODE* ptr ; //declare a pointer for future use
        if(root->left==NULL)
        {
            ptr = root;
            root = root ->right; //update the root 
            free(ptr);
            return root;
        }
        else if(root->right==NULL)
        {
            ptr = root;
            root = root->left;
            free(ptr);
            return root;
        }
        else
        {
            //inorder succesor//
            ptr = root->left; // go to left root 
            while(ptr->right!=NULL) //until the end find the righest node
                ptr = ptr ->right;
            root->info = ptr->info; //put the ptr info in it's respective position
            root->left = delete(root->left,ptr->info); //delete the node
            return root;
        }
    }
}
int main()
{

}