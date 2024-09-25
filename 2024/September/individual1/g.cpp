// 2024/09/25 16:33:27
#ifdef LOCAL
#include <basic_std_lib.h>
#include <gmp.h>
#include <gmpxx.h>
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

void solve()
{
    int n;
    cin >> n;
    // n * string(a - b, '1') == n * a - b;
    // a - b 不会很大, 设最大为 10

    int num_len = [](int val)
    {
        if (val == 0)
            return 1;
        int res = 0;
        while (val)
        {
            res++;
            val /= 10;
        }
        return res;
    }(n);

    vector<pii> ans;
    for (int a = 1; a <= 10000; a++)
    {
        for (int b = a * num_len - 10; b < a * num_len; b++)
        {
            if (!(1 <= b && b <= min(10000, a * n)))
                continue;
            int len = a * num_len - b;
            string s;
            while (s.size() < len)
            {
                s += to_string(n);
            }
            s.erase(s.end() - (s.size() - len), s.end());
            i64 val = stoll(s);
            auto val1 = __int128_t(n) * a - b;
            if (val1 == val)
            {
                ans.emplace_back(a, b);
                continue;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';
    }
}