#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int a = n;
    for (int i = 1; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a ^= x;
        a ^= i;
    }
    printf("%d", a);
    return 0;
}