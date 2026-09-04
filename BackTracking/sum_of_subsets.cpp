#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, target; // here n is the number of elements

vector <int> w; // we keep it 1 - indexed
vector <int> soln; // soln[i] = 1 if w[i] is selected

void sumOfSubsets(int i, int currentSum, int remainingSum)
{
    // base cases
    // if match found 
    if(currentSum == target)
    {
        for(int j = 0; j < n; j++)
        {
            if(soln[j])
            {
                cout << w[i] << " ";
            }
            cout << endl;
        }

        return;
    }

    // all numbers tried but no match found 

    if(i > n)
        return;
    
    if(currentSum > target)
        return;
    // bounding condition 

    if(currentSum + remainingSum > target)
        return;

    // include current element
    soln[i] = 1;
    sumOfSubsets(i + 1, currentSum + w[i], remainingSum - w[i]); // i + 1 is for the element that is in the next index
    // do not include current element
    soln[i] = 0;
    sumOfSubsets(i + 1, currentSum, remainingSum - w[i]); // currentSum is same bcz didn't take that element , index value is cut from remainingSum bcz we already considered this
}

int main()
{
    cout << "Enter number of elements stored in the array : " << endl;
    cin >> n;

    w.resize(n + 1);
    soln.resize(n + 1, 0);

    int remainingSum = 0;

    for (int i = 1; i <= n; i++)
    {
        cout<<"Enter "<<(i)<<" th item, stored in the array"<<endl;
        cin >> w[i];
        remainingSum += w[i];
    }

    cout<<"Enter Target Sum"<<endl;
    cin >> target;

    cout << "Possible subsets:\n";
    sumOfSubsets(1, 0, remainingSum);

    return 0;
}