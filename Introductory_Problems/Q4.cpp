#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a)
        scanf("%d", &x);
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            ans += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    printf("%lld", ans);
    return 0;
}