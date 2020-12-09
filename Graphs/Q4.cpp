#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue<int> q;
    q.push(n);
    vector<int> parent(n + 1, 0);
    parent[n] = -1;
    while (!q.empty())
    {
        int p = q.front();
        if (p == 1)
            break;
        q.pop();
        for (int x : a[p])
        {
            if (!parent[x])
            {
                q.push(x);
                parent[x] = p;
            }
        }
    }
    if (!q.size())
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    vector<int> ans;
    ans.push_back(1);
    int i = 1;
    while (parent[i] != -1)
    {
        ans.push_back(parent[i]);
        i = parent[i];
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans)
    {
        printf("%d ", x);
    }
    return 0;
}