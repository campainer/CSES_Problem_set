#include <bits/stdc++.h>

using namespace std;

int main()
{
    string m, n;
    cin >> n >> m;
    int nl = n.length(), ml = m.length();
    vector<int> ans(nl + 1);
    for (int i = 0; i <= nl; i++)
        ans[i] = i;
    for (int i = 0; i < ml; i++)
    {
        vector<int> temp = ans;
        ans[0] = i + 1;
        for (int j = 0; j < nl; j++)
        {
            if (n[j] == m[i])
            {
                ans[j + 1] = temp[j];
            }
            else
            {
                ans[j + 1] = min(ans[j], min(temp[j], temp[j + 1])) + 1;
            }
        }
    }
    printf("%d", ans[nl]);
    return 0;
}