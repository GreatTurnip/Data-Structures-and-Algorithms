#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100
int Queue[CAPACITY];
int front = -1; //set a flag -1 for both frond and end
int rear = -1;
void insert(int value)
{
    if(front==-1) //no queue exists till now
    {
        front = rear = 0; //update both
        Queue[rear] = value;
        printf("Inserted Element: %d \n",value);
    }
    else if(rear+1<CAPACITY) //unless full
    {
        rear ++;
        Queue[rear]=value;
        printf("Inserted Element: %d \n",value); 
    }
    else printf("Full Queue");
}
void delete() //queue deletion starts from the front
{
    if(front==-1 && rear==-1)   printf("Empty Queue \n");
    else if(front>=0&&front==rear)  //only one element
    {
        printf("deleted element : %d\n",Queue[front]);
        front = rear = -1;
    }
    else    printf("deleted element: %d\n",Queue[front++]); // IMPORTANT front must be updated(incremented)
}
int main()
{
    insert(10);
    insert(20);
    insert(30);

    delete();
    delete();

    return 0;
}