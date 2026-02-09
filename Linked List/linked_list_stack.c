#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE* top = NULL;

void push(int value)
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data=value;
    newnode->next=NULL;
    if(top==NULL)
        top=newnode;
    else
    {
        newnode->next=top;
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
        NODE* ptr = top->next;
        printf("Popped element: %d",top->data);
        free(top);
        top=ptr;
    }
}
