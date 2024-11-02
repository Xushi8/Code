// 2024/11/02 21:31:02
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        a[i] = {x, y};
    }

    constexpr int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    constexpr int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    set<pii> st;
    for (auto [x, y] : a)
    {
        st.emplace(x, y);
        for (int k = 0; k < 8; k++)
        {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (!(0 <= tx && tx < n && 0 <= ty && ty < n))
                continue;
            st.emplace(tx, ty);
        }
    }

    i64 ans = i64(n) * n - st.size();
    cout << ans << '\n';
}

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
