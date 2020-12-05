#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> a(n), b(m);
    for (int &x : a)
        scanf("%d", &x);
    for (int &x : b)
        scanf("%d", &x);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0, j = 0;
    for (int x : b)
    {
        if (abs(x - a[j]) <= k)
        {
            j++;
            ans++;
        }
        else if (x > a[j])
        {
            j++;
            int p = j, q = n - 1;
            while (p <= q)
            {
                int mid = (p + q) / 2;
                if (abs(a[mid] - x) <= k && abs(a[mid - 1] - x) > k)
                {
                    j = mid + 1;
                    ans++;
                    break;
                }
                else if (a[mid] > x || abs(a[mid] - x) <= k)
                    q = mid - 1;
                else
                    p = mid + 1;
            }
        }
        if (j >= n)
            break;
    }
    printf("%d", ans);
    return 0;
}