#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int heap[MAX];
int heapsize =0;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shiftdown(int idx)
{
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if(heap[left]<heap[smallest])   smallest = left;
    if(heap[right]<heap[smallest])  smallest = right;
    if(smallest!=idx)
    {
        swap(&heap[smallest],&heap[idx]);
        shiftdown(smallest);
    }
}
void buildheap(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        heap[i]=arr[i];
    }
    heapsize=size;
    for(int i=heapsize;i>0;i--)
    {
        shiftdown(i);
    }
}
int removeTop()
{
    int min = heap[0];
    heap[0] = heap[--heapsize];
    shiftdown(0);
}
int kthminValue(int arr[],int k,int size)
{
    buildheap(arr,size);
    int temp = heapsize;
    for(int i=1;i<=temp-k;i++)  removeTop();
    return heap[0];
}