#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

vector<int> dp(1000001);

void add(int *a, int b)
{
    *a += b;
    if (*a > mod)
        *a -= mod;
}

int ans(int n)
{
    if (n < 0)
        return 0;
    if (dp[n])
        return dp[n];
    for (int i = 1; i < 7; i++)
    {
        add(&dp[n], ans(n - i));
    }
    return dp[n];
}

int main()
{
    dp[0] = 1;
    int n;
    scanf("%d", &n);
    printf("%d", ans(n));
    return 0;
}