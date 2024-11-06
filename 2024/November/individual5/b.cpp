// 2024/11/06 13:01:34
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
    int n;
    cin >> n;
    set<pii> st;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        char ch;
        cin >> x >> ch;
        if (ch == 'R')
        {
            st.emplace(now, now + x - 1);
            now += x;
        }
        else
        {
            st.emplace(now - x, now - 1);
            now -= x;
        }
    }

    int ans = 0;

    set<int> all_r;
    now = -2e9;
    for (auto [l, r] : st)
    {
        if (now < l)
        {
            now = l;
        }
        if (!all_r.empty())
        {
            auto it = --all_r.end();
            int t = min(*it, r);
            if (t >= now)
            {
                ans += t - now + 1;
                now = 1 + t;
            }
        }

        all_r.emplace(r);
    }

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
