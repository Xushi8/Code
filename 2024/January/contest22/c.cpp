// 2024/01/22 09:13:05
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
constexpr int N = 1000005;

vector<int> G[N];
int deg[N];
int ans[N];
vector<int> now;
void dfs(int u)
{
    if (ans[u] != 0)
    {
        return;
    }
    now.emplace_back(u);
    for (int v : G[u])
    {
        if (deg[v] > deg[u])
        {
            if (ans[v] == 0)
                dfs(v);
            ans[u] = max(ans[u], int(now.size() + ans[v]));
        }
    }
    ans[u] = max(ans[u], int(now.size()));
    now.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 0; i < v; i++)
    {
        dfs(i);
    }

    int maxn = *max_element(ans, ans + v);
    cout << maxn << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}