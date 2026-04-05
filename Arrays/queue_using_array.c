#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100
int Queue[CAPACITY];
int front = -1; //set a flag -1 for both frond and end
int rear = -1;
void insert(int value)
{
    if(front=-1) //no queue exists till now
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
int main()
{

}