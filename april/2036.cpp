// 2023/04/26 19:12:56
#include <bits/stdc++.h>
using namespace std;

int n;
int a1[10], a2[10];
int a, b;
int ans = -1;
bool used = 0;
void dfs(int deep, int c, int d)
{
    if (deep == n)
    {
        if ((ans == -1 || ans > abs(c - d)) && used)
        {
            ans = abs(c - d);
        }
        return;
    }

    dfs(deep + 1, c, d);
    used = true;
    dfs(deep + 1, c * a1[deep], d + a2[deep]);
    used = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i] >> a2[i];
    }
    dfs(0, 1, 0);
    cout << ans;

    cout << endl;
    return 0;
}