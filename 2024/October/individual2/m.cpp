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
constexpr int N = 1e6 + 6;

void solve()
{
    i64 now, l, r, day, sub, add;
    cin >> now >> l >> r >> day >> sub >> add;

    auto sub_to_least_can_add = [&]
    {
        // 减到第一个能增加的位置的最小次数
        i64 nl = 0, nr = (now - l) / sub, ans = -1;
        while (nl <= nr)
        {
            i64 mid = (nl + nr) / 2;
            if (now - mid * sub + add <= r)
            {
                ans = mid;
                nr = mid - 1;
            }
            else
            {
                nl = mid + 1;
            }
        }
        return ans;
    };

    i64 dec = add - sub;
    if (dec >= 0)
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
            if (now < l || now > r)
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
    else
    {
        dec = -dec;
        i64 res = sub_to_least_can_add();
        i64 tim = 0;
        if (res == -1)
        {
            while (1)
            {
                now -= sub;
                if (now >= l)
                {
                    tim++;
                }
                else
                {
                    break;
                }
            }

            cout << (tim >= day ? "Yes" : "No") << '\n';
            return;
        }

        tim = res;
        now -= res * sub;
        tim += (now - l) / dec;
        cout << (tim >= day ? "Yes" : "No") << '\n';
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
