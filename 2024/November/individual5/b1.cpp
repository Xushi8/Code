// 2024/11/06 21:27:04
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
    int now = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        char op;
        cin >> x >> op;
        if (op == 'R')
        {
            mp[now]++;
            mp[now + x]--;
            now += x;
        }
        else
        {
            mp[now - x]++;
            mp[now]--;
            now -= x;
        }
    }

    vector<pii> a{mp.begin(), mp.end()};

    i64 sum = 0;
    int ans = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (sum >= 2)
        {
            ans += a[i].first - a[i - 1].first;
        }
        sum += a[i].second;
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
