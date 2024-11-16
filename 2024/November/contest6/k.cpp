// 2024/11/16 15:44:07
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;
constexpr int INF = 0x3f3f3f3f;

void solve()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> red(n);
    vector<int> qujian(n); // 这个点可以选择左侧的覆盖区间
    for (int i = 0; i < n; i++)
    {
        cin >> red[i];
    }
    sort(red.begin(), red.end());

    set<int> black;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        black.emplace(x);
    }

    for (int i = 0; i < n; i++)
    {
        int l = red[i], r = red[i] + k - 1;
        auto it = black.upper_bound(l);
    }
}

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
