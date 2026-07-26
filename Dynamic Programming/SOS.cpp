#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, target;
    cout << "Enter number of elements and target sum" << endl;
    cin >> n >> target;

    vector <int> arr(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter values of element" << i << endl;
        cin >> arr[i];
    }

    vector < vector <int> > dp(n + 1);

    for(int i = 0; i <= n; i++)
        dp[i].resize(target + 1, false);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= target; j++)
        {
            if(arr[i] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][ j - arr[i]];
            else
                dp[i][j] = dp[i -1][j];
        }
    }

    if(!dp[n][target])
    {
        cout << "No subset exists." << endl;
        return 0;
    }

    cout << "subset exists" << endl;
    vector<int> selected;
    int j = target;
    for(int i = n; i > 0 && j > 0; i --)
    {
        if(dp[i][j]!=dp[i -1][j])
        {
            selected.push_back(arr[i]);
            j -= arr[i];
        }
    }
    cout << "Selected elements:" << endl;

    for(int x : selected)
        cout << x << " ";
    
    cout << endl;
    return 0;
}