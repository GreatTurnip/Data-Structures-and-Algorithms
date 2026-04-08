#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct graph{
    int data;
    struct graph *next;
}node;

node* list[SIZE];
int n; //node number

void insertEdge(int u,int v)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=v;
    newnode->next=NULL;
    if(list[u]==NULL)
    {
        list[u]=newnode;
    }
    else
    {
        newnode->next=list[u];
        list[u]=newnode;
    }
}
int outgoingEdgeCount(int u)
{
    int count =0;
    node* temp = list[u];
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int ingoingEdgeCount(int u)
{
    int count =0;
    for(int i=0;i<n;i++)
    {
        node* temp = list[i];
        while(temp!=NULL)
        {
            if(temp->data==u)    count++;
            temp = temp->next;
        }
    }
    return count;
}
//check if forms triangle function
int checkEdge(int u,int v)
{
    node* temp = list[u];
    while(temp!=NULL) 
    {
        if(temp->data==v)    return 1; //if an edge found return 1;
        temp = temp->next;
    }
    return 0; //no edge found
}

int triangularcircle(int u,int v)
{
    node* temp = list[u];
    while(temp!=NULL)
    {
        int w = temp->data; // take data into variable w
        if(checkEdge(w,v)&&checkEdge(v,u)) //check is w v x these three are connected together
            return 1;
        temp=temp->next;
    }
    return 0;
}