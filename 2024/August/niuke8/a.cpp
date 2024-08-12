// 2024/08/08 12:17:45
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
    constexpr string_view Alice = "dXqwq";
    constexpr string_view Bob = "Haitang";

    auto get_yinzi = [&](int val)
    {
        map<int, int> mp;
        for (int i = 2; i * i <= val; i++)
        {
            while (val % i == 0)
            {
                mp[i]++;
                val /= i;
            }
        }
        if (val != 1)
        {
            mp[val]++;
        }
        return mp;
    };

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << Bob << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        auto yinzi = get_yinzi(a[i]);
        for (auto [x, cnt] : yinzi)
        {
            while (cnt--)
            {
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}