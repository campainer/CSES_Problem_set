#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<string> ans = {"", "1", "NO SOLUTION", "NO SOLUTION", "3 1 4 2"};
    if (n < 5)
        cout << ans[n];
    else
    {
        for (int i = 1; i <= n; i += 2)
            cout << i << " ";
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";
    }
    return 0;
}