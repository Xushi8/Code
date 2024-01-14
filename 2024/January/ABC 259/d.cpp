// 2024/01/14 20:06:44
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

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
}

int find(int x)
{
    if (x == par[x])
    {
        return x;
    }
    else
    {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    par[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    init(n);
    ll bx, by, ex, ey;
    cin >> bx >> by >> ex >> ey;
    int be, ed;
    vector<ll> x(n), y(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
        if ((x[i] - bx) * (x[i] - bx) + (y[i] - by) * (y[i] - by) == r[i] * r[i])
            be = i;
        if ((x[i] - ex) * (x[i] - ex) + (y[i] - ey) * (y[i] - ey) == r[i] * r[i])
            ed = i;
        for (int j = 0; j < i; j++)
        {
            ll x1 = (r[i] - r[j]) * (r[i] - r[j]);
            ll x2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            ll x3 = (r[i] + r[j]) * (r[i] + r[j]);
            if (x1 <= x2 && x2 <= x3)
            {
                unite(i, j);
            }
        }
    }

    cout << ((find(be) == find(ed)) ? "Yes" : "No") << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}