#include <bits/stdc++.h>
using namespace std;

vector<int> a[100001];
vector<int> ans(100001, 0);
bool flag = false;

void dfs(int x, int val)
{
    ans[x] = val;
    int z = (val == 1 ? 2 : 1);
    for (int y : a[x])
    {
        if (ans[y])
        {
            if (ans[y] != z)
            {
                flag = true;
            }
        }
        else
            dfs(y, z);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i])
        {
            dfs(i, 1);
        }
    }
    if (flag)
    {
        printf("IMPOSSIBLE");
        return 0;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}