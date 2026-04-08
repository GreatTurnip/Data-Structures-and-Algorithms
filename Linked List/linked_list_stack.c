#include <stdio.h>
#include <stdlib.h>

typedef struct node { //stack structure declaration
    int data;
    struct node *next;
} NODE;

NODE* top = NULL; //set the top to null

void push(int value)
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE)); //create a newnode
    newnode->data=value; //node data set
    newnode->next=NULL;
    if(top==NULL)
        top=newnode; //if no stack then top is the newnode
    else
    {
        newnode->next=top; //update top
        top=newnode;
    }
    if(newnode!=NULL)
        printf("pushed element:%d\n",value);
    else
        printf("Push Failed!!\n");
}
void pop()
{
    if(top==NULL)
        printf("Empty stack\n");
    else
    {
        NODE* ptr = top->next; //store the next of the top as new node
        printf("Popped element: %d",top->data);
        free(top); //free the topppes node
        top=ptr; //set the ptr as top
    }
}
