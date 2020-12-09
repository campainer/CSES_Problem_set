#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    for (string &x : a)
        cin >> x;
    queue<pair<int, int>> q;
    vector<vector<bool>> is(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !is[i][j])
            {
                q.push({i, j});
                is[i][j] = true;
                ans++;
                while (!q.empty())
                {
                    pair<int, int> t = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int x = t.first + dx[k], y = t.second + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && !is[x][y])
                        {
                            q.push({x, y});
                            is[x][y] = true;
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
