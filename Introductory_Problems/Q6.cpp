#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        long long k = max(x, y);
        long long ans = (k - 1) * (k - 1) + k + (min(x, y) == k ? 0 : (k % 2 == 0 && x < k) || (k % 2 == 1 && y < k) ? -k + min(x, y) : k - min(x, y));
        printf("%lld\n", ans);
    }
    return 0;
}