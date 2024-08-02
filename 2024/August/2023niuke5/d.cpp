// 2024/08/02 12:24:23
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
    int q;
    cin >> q;

    auto get_yinzi = [&](int val)
    {
        vector<int> res;
        for (int i = 1; i * i <= val; i++)
        {
            if (val % i == 0)
            {
                res.emplace_back(i);
                res.emplace_back(val / i);
            }
        }
        return res;
    };
    
    while (q--)
    {
        int k, c, n;
        cin >> k >> c >> n;
        auto yinzi = get_yinzi(c);
        int ans = 0;
        for (auto b : yinzi)
        {
            int t = c - b;
            if (t % k == 0)
            {
                int a = t / k;
                if (std::gcd(a, b) >= n && a > 0 && b > 0)
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}