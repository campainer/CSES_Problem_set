#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

void add(int &a, int b)
{
    a += b;
    if (a > mod)
        a -= mod;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n % 4 == 2 || n % 4 == 1)
    {
        printf("0");
        return 0;
    }
    int N = ((n * (n + 1)) / 4);
    vector<int> ans(N + 1);
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = N; j >= i; j--)
        {
            if (ans[j - i])
                add(ans[j], ans[j - i]);
        }
    }
    long long k = (mod - (mod / 2)) % mod;
    ans[N] = ((long long)ans[N] * k) % mod;
    printf("%d", ans[N]);
    return 0;
}