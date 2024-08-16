// 2024/08/16 16:16:55
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
    cin >> tt;
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

size_t get_zuixiao(vector<pii> const& a)
{
    auto b = a;
    b.insert(b.end(), a.begin(), a.end());
    const size_t n = a.size();
    size_t i, j;
    for (i = 0, j = 1; i < n && j < n;)
    {
        size_t k;
        for (k = 0; k < n && b[i].second == b[j].second; k++) {}

        if (b[i].second > b[j].second)
            i = i + k + 1;
        else
            j = j + k + 1;
        if (i == j)
            j++;
    }
    return min(i, j);
}

void func(vector<pii>& a)
{
    size_t k = get_zuixiao(a);
    rotate(a.begin(), a.begin() + k, a.end());
}

void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        a[i] = {int(round(x * 1e4)), int(round(y * 1e4)) + 360};
    }
    sort(a.begin(), a.end());
    func(a);

    vector<pii> b(n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        b[i] = {int(round(x * 1e4)), int(round(y * 1e4)) + 360};
    }
    sort(b.begin(), b.end());
    func(b);

    int dec = a[0].second - b[0].second;
    for_each(a.begin(), a.end(), [&](pii& val)
        {
            val.second -= dec;
        });
    cout << (a == b ? "YES" : "NO") << '\n';
}