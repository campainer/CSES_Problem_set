#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> dp(501, vector<int>(501));
int f(int a, int b)
{
    if (a == b)
        return 0;
    if (dp[a][b])
        return dp[a][b];
    dp[a][b] = 250001;
    for (int i = 0; i <= a / 2; i++)
    {
        dp[a][b] = min(dp[a][b], f(i, b) + f(a - i, b) + 1);
    }
    for (int i = 0; i <= b / 2; i++)
    {
        dp[a][b] = min(dp[a][b], f(a, i) + f(a, b - i) + 1);
    }
    return dp[b][a] = dp[a][b];
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", f(a, b));
    return 0;
}