#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a)
        scanf("%d", &x);
    bitset<100001> s;
    s[0] = 1;
    for (int x : a)
    {
        s |= (s << x);
    }
    vector<int> ans;
    int count = 0;
    for (int i = 1; i < 100001; i++)
    {
        if (s[i])
        {
            count++;
            ans.push_back(i);
        }
    }
    printf("%d\n", count);
    for (int x : ans)
        printf("%d ", x);
    return 0;
}