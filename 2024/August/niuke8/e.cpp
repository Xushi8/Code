// 2024/08/08 13:01:04
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

void solve()
{
    auto calc = [](i64 val)
    {
        int res = 0;
        while (val)
        {
            res += val % 10;
            val /= 10;
        }
        return res;
    };

    auto get_yinzi = [](i64 val)
    {
        vector<i64> res;
        for (i64 i = 1; i * i <= val; i++)
        {
            if (val % i == 0)
            {
                res.push_back(i);
                res.push_back(val / i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    };

    i64 n;
    cin >> n;

    // set<i64> st;
    // for (i64 yushu = 1; yushu <= min(i64(99), n); yushu++)
    // {
    //     i64 val = n - yushu;
    //     if (val == 0)
    //         break;
    //     auto yinzi = get_yinzi(val);
    //     for (auto x : yinzi)
    //     {
    //         if (n % x == yushu && yushu == calc(x))
    //         {
    //             st.emplace(x);
    //         }
    //     }
    // }
    // cout << st.size() << '\n';

    for (i64 m = 1; m <= n; m++)
    {
        if (n % m == calc(m))
        {
            cout << m << ' ';
        }
    }
    cout << '\n';
    auto yinzi = get_yinzi(n);
    for (auto x : yinzi)
    {
        cout << x << ' ';
    }
    cout << '\n' << '\n';
}