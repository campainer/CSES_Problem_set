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
    int x, n;
    scanf("%d%d", &n, &x);
    vector<int> coins(n);
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    for (int i = 1; i <= x; i++)
    {
        for (int y : coins)
            if (i - y >= 0)
                add(dp[i], dp[i - y]);
    }
    printf("%d", dp[x]);
    return 0;
}