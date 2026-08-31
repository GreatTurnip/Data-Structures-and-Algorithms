#include <iostream>
#include <vector>

using namespace std;

int partition(vector <int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(true)
    {
        while(i <= high && arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        
        if(i < j)
        {
            swap(arr[i], arr[j]);
        }
        else
            swap(arr[low], arr[j]);
        
    }
    return j;
}

void quicksort(vector <int> &arr, int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    vector <int> arr = {50, 70, 60, 90, 80, 10, 20, 30};

    quicksort(arr, 0, arr.size() - 1);

    cout << "Sorted Array : ";
    
    for(int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}