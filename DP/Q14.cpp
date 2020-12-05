#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n), b;
    int ans = 0;
    for (int &x : a)
        scanf("%d", &x);
    b.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > b[ans])
        {
            b.push_back(a[i]);
            ans++;
        }
        else if (a[i] < b[0])
            b[0] = a[i];
        else
        {
            int p = 1, q = ans;
            while (p <= q)
            {
                int mid = (p + q) / 2;
                if (b[mid] >= a[i] && a[i] > b[mid - 1])
                {
                    b[mid] = a[i];
                    break;
                }
                else if (b[mid] > a[i])
                    q--;
                else
                    p++;
            }
        }
    }
    printf("%d", ans + 1);
    return 0;
}