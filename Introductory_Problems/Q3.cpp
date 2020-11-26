#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int count = 1, ans = 1;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            count = 0;
        }
        count++;
        ans = max(ans, count);
    }
    printf("%d", ans);
    return 0;
}