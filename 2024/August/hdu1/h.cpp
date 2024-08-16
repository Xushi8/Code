// 2024/08/16 12:20:56
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
    map<int, int> mp;
    constexpr int kk = 6;
    for (int i = 0; i < (1 << kk); i++)
    {
        for (int j = 0; j < (1 << kk); j++)
        {
            for (int k = 0; k < (1 << kk); k++)
            {
                for (int l = 0; l < (1 << kk); l++)
                {
                    int a = (((i & j) ^ k) | l);
                    int b = (((i & j) ^ (k | l)));
                    // cout << a << ' ' << b << '\n';
                    mp[a]++;
                }
            }
        }
    }

    int sum = 0;
    for (auto [x, y] : mp)
    {
        sum += y;
        cout << x << ' ' << y / (1 << kk << kk) << '\n';
    }
    cout << sum << '\n';

    // int n, k;
    // cin >> n >> k;
    // int m = (1 << k);
    // // a & b ^ c | d

    
}