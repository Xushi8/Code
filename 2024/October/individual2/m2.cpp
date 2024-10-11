// 2024/10/09 16:46:33
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
constexpr int N = 1e8 + 6;

void solve()
{
    i64 now, l, r, day, sub, add;
    cin >> now >> l >> r >> day >> sub >> add;
    now -= l;
    r -= l;
    l -= l;

    auto check = [&](i64 val)
    {
        return l <= val && val <= r;
    };

    if (sub >= add)
    {
        if (now + add > r)
        {
            day--;
            now -= sub;
        }
        if (!check(now))
        {
            cout << "No" << '\n';
            return;
        }

        int dec = sub - add;
        if (dec == 0)
        {
            cout << "Yes\n";
            return;
        }

        cout << ((now - l) / dec >= day ? "Yes" : "No") << '\n';
    }
    else
    {
        i64 cnt = (now - l) / sub;
        if (cnt >= day)
        {
            cout << "Yes" << '\n';
            return;
        }
        day -= cnt;
        now -= cnt * sub;
        vector<char> vis(N);
        while ((!vis[now]) && day > 0)
        {
            vis[now] = 1;
            now += add;
            if (!check(now))
            {
                cout << "No" << '\n';
                return;
            }
            i64 num2 = (now - l) / sub;
            day -= min(num2, day);
            now = now - num2 * sub;
        }
        cout << "Yes" << '\n';
    }
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
