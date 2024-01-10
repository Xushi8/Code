// 2023/08/07 20:16:10
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
struct A
{
    int a, b, c;
};

bool cmp(const A& a, const A& b)
{
    return a.c > b.c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<A> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].a--;
        arr[i].b--;
    }

    sort(arr.begin(), arr.end(), cmp);
    init(n * 2);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        auto [a, b, c] = arr[i];
        if (same(a, b) || same(a + n, b + n))
        {
            ans = c;
            break;
        }
        else
        {
            unite(a, b + n);
            unite(a + n, b);
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}