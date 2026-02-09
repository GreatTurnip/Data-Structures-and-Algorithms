#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *FIRST = NULL, *LAST = NULL;

/* INSERT */
void insert(int value)
{
    NODE *new_node = malloc(sizeof(NODE));

    if(new_node == NULL)
    {
        printf("Failed\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if(FIRST == NULL)
        FIRST = LAST = new_node;
    else
    {
        LAST->next = new_node;
        LAST = new_node;
    }

    printf("Successfully inserted\n");
}

/* DELETE */
void delete(int value)
{
    if(FIRST == NULL)
    {
        printf("Empty List\n");
        return;
    }

    NODE *curr = FIRST;
    NODE *prev = NULL;

    while(curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL)
    {
        printf("%d Not Found to delete!\n", value);
        return;
    }

    if(prev == NULL)              // deleting first node
        FIRST = curr->next;
    else
        prev->next = curr->next;

    if(curr == LAST)              // deleting last node
        LAST = prev;

    free(curr);
    printf("%d Deleted!\n", value);
}

/* SEARCH */
void search(int value)
{
    if(FIRST == NULL)
    {
        printf("Empty List\n");
        return;
    }

    NODE *curptr = FIRST;

    while(curptr != NULL)
    {
        if(curptr->data == value)
        {
            printf("Found %d\n", value);
            return;
        }
        curptr = curptr->next;
    }

    printf("Not Found\n");
}
int isSorted()
{
    if (FIRST==NULL| FIRST->next == NULL)    return 1; //sorted cz no elem or only one elem
    NODE* temp = FIRST;
    while(temp->next!=NULL)
    {
        if(temp->data>temp->next->data)
            return 0 ; //not sorted
        temp = temp->next;
    }
    return 1; //sorted
}
int largest()
{
    if(FIRST==NULL) return -1; //list is empty
    int max = FIRST->data;
    NODE *temp = FIRST;
    while(temp!=NULL)
    {
        if(temp->data>max)  max = temp->data;
        temp = temp->next;
    }
    return max;
}
int secondLargest()
{
    if(FIRST==NULL || FIRST->next ==NULL) return -1;
    int largest = INT_MIN;
    int second = INT_MIN;
    NODE* temp = FIRST;
    while(temp!=NULL)
    {
        if(temp->data > largest)
        {
            second = largest;
            largest = temp ->data;
        }
        else if(temp->data > second && temp->data !=largest)
        {
            second = temp->data;
        }
        temp = temp->next;
    }
    if(second==INT_MIN) return -1;
    return second;
}
void deleteOddPosition()
{
    if(FIRST==NULL) return;
    NODE* temp = FIRST;
    NODE* prev = NULL;
    int pos = 1;
    while(temp!=NULL)
    {
        if(pos%2!=0) //odd position
        {
            //deletion here
            NODE* delete = temp;
            if(prev==NULL) //first node
            {
                FIRST = temp->data;
            }
            else
            {
                prev->next = temp->next;
            }
            temp = temp->next;
            free(delete);
            pos++;
        }
        else //even pos
        {
            prev = temp;
            temp = temp->next;
        }

    }
}
void sortLinkedList()
{
    if(FIRST==NULL||FIRST->next==NULL)   return;
    NODE* i;
    NODE* j;
    for(i=FIRST;i!=NULL;i=i->next)
        for(j=FIRST->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
}
void reverseLinkedList()
{
    NODE* prev = NULL;
    NODE* current = FIRST;
    NODE* next = NULL;
    while(current!=NULL)
    {
        next = current->next; //stored next node
        current->next = prev; //reversing the link
        prev = current ; //move prev forward
        current = next ; //move current forward
    }
}
void print()
{
    if(FIRST==NULL) printf("Nothing to print");
    else
    {
        printf("Linked list:");
        NODE *cur = FIRST;
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur = cur->next;
        }
    }
    printf("\n");
}
void main()
{
    print();
    delete(2023);
    search(1971);
    insert(5);
    insert(15);
    print();
    insert(56);
    search(15);
    insert(25);
    print();
    search(1952);
    delete(15);
    print();
    search(15);
    delete(404);
    print();
    insert(100);
    print();
    search(100);
    print();
    delete(5);
    print();
    delete(100);
    print();
}





































