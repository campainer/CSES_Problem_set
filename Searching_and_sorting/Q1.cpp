#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a)
        scanf("%d", &x);
    int j = 1;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            j++;
    printf("%d", j);
    return 0;
}