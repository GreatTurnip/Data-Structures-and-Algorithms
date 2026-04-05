#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE* front, *rear;
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
    if(front==NULL)
        printf("Empty Queue");
    else
    {
        NODE* ptr=front->next;
        printf("Deleted element \n");
        free(front);
        front=ptr;
    }
}
void print()
{
    if(front==NULL)
    {
        printf("Empty Queue\n");
        return;
    }
    NODE* ptr = front;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    insert(10);
    insert(20);
    insert(30);

    delete(10);
    delete(20);

    print();

    return 0;
}