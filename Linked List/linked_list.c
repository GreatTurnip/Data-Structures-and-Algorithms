#include<stdio.h>
#include<stdlib.h>
//declare node
struct Node{
    int data;
    struct Node* next;//declare the next pointer
};
//function to create Node

struct Node* createNode(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));//dynamically allocate memory for node
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtHead(struct Node** head,int value)// **head is pointer to pointer. we need to change the heads adress itselfthe
{
    struct Node* newNode = createNode(value);
    newNode->next = *head;//connects the new node to the current head of the list(*head is the head itself from the main function)
    *head = newNode;//updates the head pointer(this is why we pass the adress of the head)
}
void printList(struct Node* head)
{
    while(head !=NULL)
    {
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("NULL");

}
int main()
{
    struct Node* head = NULL;
    insertAtHead(&head,10);
    insertAtHead(&head,10);
    insertAtHead(&head,10);
    printList(head);
}

