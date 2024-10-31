// 2024/10/13 19:44:39
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
    array<set<int>, 64> cnt;
    for (int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;
        for (int j = 0; j < 63; j++)
        {
            if ((x >> j) & 1)
            {
                cnt[j].emplace(i);
            }
        }
    }

    for (int i = 0; i < 64; i++)
    {
        if (cnt[i].size() % 2 != 0)
        {
            cout << -1 << '\n';
            return;
        }
    }

    vector<pll> ans;

    for (int i = 63; i >= 0; i--)
    {
        if (cnt[i].size() == 2)
        {
            auto x = *cnt[i].begin();
            auto y = *--cnt[i].end();
            cnt[i].clear();
            i64 num = i64(1) << i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (cnt[j].size() > 2 && cnt[j].contains(x) && cnt[j].contains(y))
                {
                    cnt[j].erase(x);
                    cnt[j].erase(y);
                    num |= i64(1) << j;
                }
            }
            // cout << x + 1 << ' ' << num << '\n';
            ans.emplace_back(x + 1, num);
        }

        if (!cnt[i].empty())
        {
            cout << -1 << '\n';
            return;
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';
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
