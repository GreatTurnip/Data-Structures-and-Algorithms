#include<stdio.h>
#include<limits.h>
#define MAX_SIZE 1000
int heap[MAX_SIZE]; //the size of heap
int heapsize = 0; //idx to track current size
void swap(int *a,int *b) //swap function to implement shiftup
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shiftup(int idx)
{
    while(idx>0&&heap[(idx-1)/2]<heap[idx]) //while parent is smaller than child
    {
        swap(&heap[(idx-1)/2],&heap[idx]); //swap child and parent
        idx = (idx-1)/2; // this updates the idx to get up the heap 
    }
}
void shiftdown(int idx)
{
    int largest = idx; //set the largest to idx
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if(left<heapsize&&heap[left]>heap[largest]) largest = left;
    if(right<heapsize&& heap[right]>heap[largest])  largest = right;//if right or left which is largest . set it largest
    if(largest!=idx)
    {
        swap(&heap[idx],&heap[largest]); // swap places with largest
        shiftdown(largest); //recursion
    }
}
void insert(int value)
{
    if(heapsize>=MAX_SIZE)  return;
    heap[heapsize]=value; //value at the last position
    shiftup(heapsize); //move it to it's accurate position
    heapsize++;
}
int removeTop()
{
    int max = heap[0];
    heap[0]=heap[--heapsize]; //set the last value to the top
    shiftdown(0); //shiftdown the top
    return max; //the the integer which is removed
}
void buildheap(int arr[],int size) // take an array and its size to heapify
{
    for(int i=0;i<size;i++)
    {
        heap[i]=arr[i]; //copy the elements of array to heap
    }
    heapsize = size; // set the array size to current heapsize
    for(int idx = (heapsize-1)/2;idx>=0;idx--) // until the half of the heapsize
    {
        shiftdown(idx);//sets the elements to their respective position
    }
}
void decreaseKey(int idx,int newValue)
{
    heap[idx]=newValue;
    shiftdown(idx); // when decreased shift it down to it's respective position
}
void increaseKey(int idx,int newValue)
{
    heap[idx]=newValue;
    shiftup(idx); // when increased move it up
}
void removeArbitaryIndex(int idx)
{
    increaseKey(idx,INT_MAX); // set the removable idx to max so it sits on top
    removeTop();
}
void printHeap()
{
    printf("The heap elements(size = %d) : ",heapsize);
    for(int i=0;i<heapsize;i++) printf("%d \n",heap[i]);
    printf("End of heap \n");
}
int main()
{
    int arr[] = {10, 20, 5, 6, 1, 8, 9};
    int n = 7;

    // Build heap from array
    buildheap(arr, n);
    printHeap();

    // Insert elements
    insert(50);
    insert(15);
    printf("\nAfter inserting 50 and 15:\n");
    printHeap();

    // Remove top (max element)
    int removed = removeTop();
    printf("\nRemoved top element: %d\n", removed);
    printHeap();

    // Increase key
    increaseKey(2, 100);
    printf("\nAfter increasing index 2 to 100:\n");
    printHeap();

    // Decrease key
    decreaseKey(0, 3);
    printf("\nAfter decreasing root to 3:\n");
    printHeap();

    // Remove arbitrary index
    removeArbitaryIndex(1);
    printf("\nAfter removing index 1:\n");
    printHeap();
    return 0;
}