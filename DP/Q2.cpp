#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> coins(101);
vector<int> dp(1000001, -2);

int ans(int x)
{
    if (x < 0)
        return -1;
    if (dp[x] != -2)
        return dp[x];
    dp[x] = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int k = ans(x - coins[i]);
        if (k > -1)
        {
            dp[x] = min(dp[x], 1 + k);
        }
    }
    if (dp[x] == INT_MAX)
        dp[x] = -1;
    return dp[x];
}

int main()
{
    dp[0] = 0;
    int x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("%d", ans(x));
    return 0;
}