// 2023/08/09 10:04:15
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

bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, tt;
    cin >> n >> tt;
    init(n * 3);
    int ans = 0;
    while (tt--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        x--; y--;
        if (x >= n || y >= n)
        {
            ans++;
            continue;
        }
        
        if (op == 1)
        {
            if (same(x, y + n) || same(x + n, y + 2 * n) || same(x + 2 * n, y) ||
                same(y, x + n) || same(y + n, x + 2 * n) || same(y + 2 * n, x))
            {
                ans++;
                continue;
            }

            unite(x, y); unite(x + n, y + n); unite(x + 2 * n, y + 2 * n);
        }
        else
        {
            if (same(x, y) || same(x + n, y + n) || same(x + 2 * n, y + 2 * n) ||
                same(y, x + n) || same(y + n, x + 2 * n) || same(y + 2 * n, x) ||
                x == y)
            {
                ans++;
                continue;
            }

            unite(x, y + n); unite(x + n, y + 2 * n); unite(x + 2 * n, y);
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}