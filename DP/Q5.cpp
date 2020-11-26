#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        while (k)
        {
            dp[i] = min(dp[i], dp[i - (k % 10)] + 1);
            k /= 10;
        }
    }
    printf("%d", dp[n]);
    return 0;
}