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
    int n;
    scanf("%d", &n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<vector<bool>> is(n + 1, vector<bool>(n + 1, 0));
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == '.')
                is[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (is[i][j])
            {
                add(dp[i][j], dp[i - 1][j]);
                add(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d", dp[n][n]);
    return 0;
}