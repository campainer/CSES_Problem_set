#include <bits/stdc++.h>
using namespace std;

vector<int> a[100001];
vector<int> parent(100001, 0);
bool flag = false;

void dfs(int x, int val)
{
    parent[x] = val;
    for (int y : a[x])
    {
        if (y != val)
        {
            if (parent[y])
            {
                parent[y] = 0;
                vector<int> cycle;
                int temp = x;
                while (temp)
                {
                    cycle.push_back(temp);
                    temp = parent[temp];
                }
                cycle.push_back(x);
                printf("%d\n", (int)cycle.size());
                for (int x : cycle)
                    printf("%d ", x);
                flag = true;
                return;
            }
            else
            {
                dfs(y, x);
                if (flag)
                    return;
            }
        }
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
        if (!parent[i])
        {
            dfs(i, -1);
        }
        if (flag)
            return 0;
    }
    printf("IMPOSSIBLE");
    return 0;
}