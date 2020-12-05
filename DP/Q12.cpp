#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
vector<long long> a(N), sum(N);
vector<vector<long long>> dp(N, vector<long long>(N));
inline long long gs(int x, int y)
{
    if (x == 0)
        return sum[y];
    return sum[y] - sum[x - 1];
}
long long f(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    if (x == y)
        return dp[x][y] = a[x];
    return dp[x][y] = gs(x, y) - min(f(x + 1, y), f(x, y - 1));
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = a[i] + sum[i - 1];
    }
    printf("%lld", f(0, n - 1));
    return 0;
}