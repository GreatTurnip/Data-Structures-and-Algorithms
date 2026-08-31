#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,w;
    cout << "Enter number of objects and knapsack capacity:" << endl;
    cin >> n >> w;

    vector<int> weight(n+1), profit(n+1);

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter profit and weight of object" << i << " : " <<endl;
        cin >> weight[i] >> profit[i];
    }

    vector < vector <int> > dp( n + 1, vector <int> (w + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= w; w++)
        {
            if(weight[i] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], profit[i] + dp[i - 1][w - weight[i]]);
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum Profit" << " = " << dp[n][w] << endl;
    vector <int> selected;
    int k = w;

    for(int i = n; i > 0; i --)
    {
        if(dp[i][w] != dp[i - 1][w])
        {
            selected.push_back(i);
            k -= weight[i];
        }
    }

    for (int item : selected)
        cout << item << "\t" << weight[item] << "\t" << profit[item] << endl;

    return 0;
}