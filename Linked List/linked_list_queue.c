#include <stdio.h>
#include <stdlib.h>

typedef struct node { //queue struct declaration
    int data;
    struct node *next;
} NODE;

NODE* front, *rear; //two pointer (rear for inserting & front for deleting)
void insert(int value)
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE)); //create new node
    newnode->data = value;
    newnode->next = NULL;
    if(front==NULL)
    {
        front=rear=newnode; //if no node front and rear both are 
    }
    else
    {
        rear->next = newnode; // set the next of rear as new node
        rear = newnode; //set the rear as newnode
    }
}
void delete(int value)
{
    if(front==NULL) //check if empty
        printf("Empty Queue");
    else
    {
        NODE* ptr=front->next;  //store the next adress of front as ptr
        printf("Deleted element \n");
        free(front); //delete front
        front=ptr; //set the ptr as new front
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