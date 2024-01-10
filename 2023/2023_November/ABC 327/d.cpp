// 2023/11/04 20:18:02
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
    else
        par[x] = y;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int a[N], b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i] --;
    }

    init(n * 2);

    for (int i = 0; i < m; i++)
    {
        int x = a[i];
        int y = b[i];
        if (same(x, y) || same(x + n, y + n))
        {
            cout << "No\n";
            return 0;
        }

        unite(x, y + n);
        unite(x + n, y);
    }

    cout << "Yes\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}