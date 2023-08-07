// 2023/08/07 16:02:41
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

struct A
{
    int a, b, time;
};

bool cmp(const A& a, const A& b)
{
    return a.time < b.time;
}

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    init(n);
    vector<A> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].time;
        arr[i].a--; arr[i].b--;
    }
    sort(arr.begin(), arr.end(), cmp);
    int index = -1;
    for (int i = 0; i < m; i++)
    {
        int x = arr[i].a;
        int y = arr[i].b;
        if (!same(x, y))
        {
            unite(x, y);
            n--;
        }

        if (n == 1)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        cout << -1 << '\n';
    else
        cout << arr[index].time << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}