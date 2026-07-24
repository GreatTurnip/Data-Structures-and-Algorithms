#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n, amount;
    cout << "Enter the number of coin types and amount" << endl;
    cin >> n >> amount;
    vector <int> coin(n+1);
    for(int i = 1; i <= n; i++)
    {
        cout << "Enter value of coin" << i << endl;
        cin >> coin[i];
    }
    const int max = INT_MAX;
    vector<vector<int>> dp(n+1);
    for(int i = 0; i < n; i++)
    {
        dp[i].resize(amount + 1, max);
    }
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(coin[i] <= j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coin[i]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << "Minimum number of coins = " << dp[n][amount] << endl;

    vector<int> selected;
    int j = amount;
    int i = n;
    while(i > 0 && j >0)
    {
        if(dp[i][j] == dp[i -1][j])
            i--;
        else
        {
            selected.push_back(coin[i]);
            j -= coin[i];
        }
    }
    for(int c : selected)
        cout << c << endl;
}