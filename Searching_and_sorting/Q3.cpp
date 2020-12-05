#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a.begin(), a.end());
    int ans = n, j = n - 1;
    for (int i = 0; i < j; i++)
    {
        if (a[i] + a[i + 1] > k)
            break;
        else if (a[i] + a[j] <= k)
        {
            ans--;
            j--;
        }
        else
        {
            int p = i + 1, q = j - 1;
            while (p <= q)
            {
                int mid = (p + q) / 2;
                if (a[mid] + a[i] <= k && a[mid + 1] + a[i] > k)
                {
                    ans--;
                    j = mid - 1;
                    break;
                }
                else if (a[mid] + a[i] <= k)
                    p = mid + 1;
                else
                    q = mid - 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
