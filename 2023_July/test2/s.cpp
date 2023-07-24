// 2023/07/21 08:35:35
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 200005;
int V, E;

vector<pii> G;
vector<int> vertical;
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
        return par[x] = find(x);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x = y)
        return;

    if (rk[x] < rk[y])
    {
        par[x] = y;
    }
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> V >> E;
    vertical.resize(V);
    for (int i = 0; i < V; i++)
        cin >> vertical[i];

    G.resize(E);
    for (int i = 0; i < E; i++)
    {
        cin >> G[i].first >> G[i].second;
        G[i].first--;
        G[i].second--;
    }

    init(V);
    for (int i = 0; i < E; i++)
    {
        auto [u, v] = G[i];
        if (!same(u, v))
        {
            unite(u, v);
        }
    }

    cout << endl;
    return 0;
}