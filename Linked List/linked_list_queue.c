#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE* front,rear;
void insert(int value)
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = value;
    newnode->next = NULL;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void delete(int value)
{
    if(front=NULL)
        printf("Empty Queue");
    else
    {
        NODE* ptr=front->next;
        printf("Deleted element");
        free(front);
        front=ptr;
    }
}
