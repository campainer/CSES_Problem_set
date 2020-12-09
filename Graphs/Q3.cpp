#include <bits/stdc++.h>
using namespace std;

vector<int> p(100001);

int parent(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = parent(p[x]);
}

void add(int x, int y)
{
    int px = parent(x), py = parent(y);
    p[py] = px;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == i)
            ans.push_back(i);
    }
    printf("%d\n", (int)ans.size() - 1);
    for (int i = 1; i < ans.size(); i++)
    {
        printf("%d %d\n", ans[0], ans[i]);
    }
    return 0;
}