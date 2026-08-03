#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1);
    for(int i = 0; i <= n; i++)
        dp[i].resize(m + 1, 0);
    
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i -1]==b[j - 1])
                dp[i][j] = dp[i - 1][j -1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << "length of lcs " << dp[n][m] << endl;

    string lcs = "";
    int i = n;
    int j = m;
    while(i > 0 & j > 0)
    {
        if(a[i - 1]==b[j -1])
        {
            lcs += a[i - 1];
        }
        else if(dp[i - 1]>dp[j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(),lcs.end());
    cout << "LCS: " << lcs << endl;
    return 0;
}