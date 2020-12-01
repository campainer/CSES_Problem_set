#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

inline void add(int &a, int b)
{
    a += b;
    if (a > mod)
        a -= mod;
}

int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    for (int &x : a)
        scanf("%d", &x);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (a[i - 1] == 0 || a[i - 1] == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (a[i - 1] == 0 || a[i - 1] == j)
                    dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % mod + dp[i - 1][j + 1]) % mod;
                else
                    dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int x : dp[n])
        add(ans, x);
    cout << ans;
    return 0;
}