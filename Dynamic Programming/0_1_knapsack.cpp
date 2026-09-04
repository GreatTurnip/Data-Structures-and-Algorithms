
 #include <bits/stdc++.h>

 using namespace std;

 int main()
 {
    int n, w;
    cin >> n >> w;
    vector <int> weight(n + 1), profit(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> profit[i];
    }
    vector < vector <int> > dp(n + 1);
    for(int j = 1; j <= n; j++)
    {
        dp[j].resize(w + 1, 0);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(weight[i] <= j)
            {
                dp[i][j] = max(dp[i -1][j], profit[i] + dp[i - 1][j - weight[i]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    vector <int> selected;
    int k = w;

    for(int i = n; i > 0; i --)
    {
        if(dp[i][k] != dp[i - 1][k])
        {
            selected.push_back(i);
            k -= weight[i];
        }
    }

    reverse(selected.begin(), selected.end());

    for(int c : selected)
    {
        cout << c << endl;
    }

    return 0;
 }
