// 2024/01/15 19:49:33
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

struct A
{
    ll x, y, id;
    A() = default;
    A(ll a, ll b, ll c)
    {
        x = a;
        y = b;
        id = c;
    }
};

bool operator<(A a, A b)
{
    return a.y < b.y;
}

bool cmp(A a, A b)
{
    return a.x < b.x;
}

int par[N];
int tot[N];
A a[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
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

int ans;
ll n, c;
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        par[x] = y;
        ans--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x + y, x - y, i};
    }
    sort(a + 1, a + 1 + n, cmp);
    init(n);
    multiset<A> st;
    constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
    st.emplace(0, INF, 0);
    st.emplace(0, -INF, 0);

    int now = 1;
    st.emplace(a[1]);
    ans = n;
    for (int i = 2; i <= n; i++)
    {
        while (a[i].x - a[now].x > c)
        {
            st.erase(st.find(a[now]));
            now++;
        }
        auto it = st.lower_bound(a[i]);
        A l = *--it;
        A r = *it;
        if (a[i].y - l.y <= c)
            unite(a[i].id, l.id);
        if (r.y - a[i].y <= c)
            unite(a[i].id, r.id);
        st.emplace(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        tot[find(i)]++;
    }

    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        maxn = max(maxn, tot[i]);
    }

    cout << ans << ' ' << maxn;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}