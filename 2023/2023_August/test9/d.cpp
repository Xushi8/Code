// 2023/08/15 09:05:42
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

int par[N], rk[N];
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (rk[x] < rk[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (rk[x] == rk[y])
        {
            rk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

bool broken[N];

vector<int> G[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int k;
    cin >> k;
    vector<int> ope(k);
    for (int i = 0; i < k; i++)
    {
        cin >> ope[i];
        broken[ope[i]] = 1;
    }
    reverse(ope.begin(), ope.end());

    int tot = n - k;
    for (int u = 0; u < n; u++)
    {
        for (int v : G[u])
        {
            if (!same(u, v) && broken[u] == 0 && broken[v] == 0)
            {
                tot--;
                unite(u, v);
            }
        }
    }

    vector<int> ans;
    ans.emplace_back(tot);
    for (int u : ope)
    {
        tot++;
        broken[u] = 0;
        for (int v : G[u])
        {
            if (broken[v] == 0 && !same(u, v))
            {
                tot--;
                unite(u, v);
            }
        }

        ans.emplace_back(tot);
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++)
    {
        cout << *it << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}