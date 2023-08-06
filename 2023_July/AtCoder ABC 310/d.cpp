// 2023/07/15 21:34:00

// 2023/08/06 21:00:05
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int n, t, m;
int a[200], b[200], ans;
int vis[200];

void dfs(int deep, int maxn)
{
    if (deep == n)
    {
        if (maxn != t)
            return;
        for (int i = 0; i < m; i++)
        {
            if (vis[a[i]] == vis[b[i]])
                return;
        }
        ans++;

        return;
    }

    for (int i = 1; i <= maxn; i++)
    {
        vis[deep] = i;
        dfs(deep + 1, maxn);
        vis[deep] = 0;
    }
    vis[deep] = maxn + 1;
    dfs(deep + 1, maxn + 1);
    vis[deep] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    dfs(0, 0);
    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}