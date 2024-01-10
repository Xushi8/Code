// 2023/11/08 16:48:40
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
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 10005;

vector<int> G[N];
bool vis[N];
int arr[N];
int now_root;

void dfs(int u, int deep)
{
    if (vis[u])
        return;
    vis[u] = 1;
    arr[now_root] = max(arr[now_root], deep);
    for (int v : G[u])
    {
        dfs(v, deep + 1);
    }
}

void check(int u)
{
    if (vis[u])
        return;
    vis[u] = 1;
    for (int v : G[u])
    {
        check(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    // 是否联通
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            check(i);
            cnt++;
        }
    }

    if (cnt > 1)
    {
        cout << "Error: " << cnt << " components";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        now_root = i;
        dfs(i, 1);
    }

    int maxn = arr[1];
    for (int i = 1; i <= n; i++)
    {
        maxn = max(maxn, arr[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == maxn)
        {
            cout << i << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}