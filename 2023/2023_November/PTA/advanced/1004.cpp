// 2023/11/07 17:52:05
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

int par[N];

vector<int> child[N];

int ans[N];

int maxn;

void dfs(int node, int deep)
{
    maxn = max(maxn, deep);
    if (child[node].empty())
    {
        ans[deep]++;
    }
    else
    {
        for (int v : child[node])
        {
            dfs(v, deep + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(par, -1, sizeof(par));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, k;
        cin >> u >> k;
        while (k--)
        {
            int x;
            cin >> x;
            par[x] = u;
            child[u].emplace_back(x);
        }
    }

    int root;
    for (int i = 1; i < N; i++)
    {
        if (par[i] == -1)
        {
            root = i;
            break;
        }
    }

    dfs(root, 0);

    cout << ans[0];
    for (int i = 1; i <= maxn; i++)
    {
        cout << ' ' << ans[i];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}