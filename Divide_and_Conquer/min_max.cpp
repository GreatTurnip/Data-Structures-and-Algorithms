#include <iostream>
#include <vector>

using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair findMinMax(vector <int> &arr, int low, int high)
{
    Pair result;

    if(low == high)
    {
        result.min = arr[low];
        result.max = arr[high];
        return result;
    }

    if(low + 1 == high)
    {
        if(arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    Pair left = findMinMax(arr, low, mid);
    Pair right = findMinMax(arr, mid + 1, high);

    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main()
{
    vector <int> arr = {100, 11, 445, 330, 3000};

    Pair ans = findMinMax(arr, 0, arr.size() - 1);

    cout << "Minimum = " << ans.min << endl;
    cout << "Maximum = " << ans.max << endl;

    return 0;
}