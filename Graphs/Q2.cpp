#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}, dz[4] = {1, 0, 3, 2};
    char d[4] = {'R', 'L', 'U', 'D'};
    int n, m;
    string ans = "NO";
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    for (string &x : a)
        cin >> x;
    queue<pair<int, int>> q;
    vector<vector<int>> is(n, vector<int>(m, -1));
    int cx, cy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'B')
            {
                q.push({i, j});
                is[i][j] = 4;
                while (!q.empty())
                {
                    pair<int, int> t = q.front();
                    q.pop();
                    if (a[t.first][t.second] == 'A')
                    {
                        ans = "YES";
                        cx = t.first;
                        cy = t.second;
                        break;
                    }
                    for (int k = 0; k < 4; k++)
                    {
                        int x = t.first + dx[k], y = t.second + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#' && is[x][y] == -1)
                        {
                            q.push({x, y});
                            is[x][y] = dz[k];
                        }
                    }
                }
                i = n;
                j = m;
            }
        }
    }
    cout << ans;
    if (ans == "YES")
    {
        ans = "";
        int j = is[cx][cy];
        while (j != 4)
        {
            ans.push_back(d[j]);
            cx += dx[j];
            cy += dy[j];
            j = is[cx][cy];
        }
        cout << endl
             << ans.length() << endl
             << ans;
    }
    return 0;
}
