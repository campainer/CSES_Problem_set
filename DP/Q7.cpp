#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> cost(n), pages(n), dp(k + 1, -1);
    for (int &x : cost)
        scanf("%d", &x);
    for (int &x : pages)
        scanf("%d", &x);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= cost[i]; j--)
        {
            if (dp[j - cost[i]] != -1)
                dp[j] = max(dp[j - cost[i]] + pages[i], dp[j]);
        }
    }
    printf("%d", *max_element(dp.begin(), dp.end()));
    return 0;
}