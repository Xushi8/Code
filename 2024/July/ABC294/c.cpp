// 2024/07/30 20:34:57
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }

    vector<int> c;
    std::merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));

    for (auto x : a)
    {
        cout << lower_bound(c.begin(), c.end(), x) - c.begin() + 1 << ' ';
    }
    cout << '\n';
    for (auto y : b)
    {
        cout << lower_bound(c.begin(), c.end(), y) - c.begin() + 1 << ' ';
    }
    cout << '\n';
}