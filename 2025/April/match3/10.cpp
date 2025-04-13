// 2025/04/13 19:17:49
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
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        int h, m, s;
        char ch;
        cin >> h >> ch >> m >> ch >> s;
        int l = h * 3600 + m * 60 + s;
        cin >> ch;
        cin >> h >> ch >> m >> ch >> s;
        int r = h * 3600 + m * 60 + s;

        a[i] = {l, r};
    }

    sort(a.begin(), a.end());

    int now = 0;
    int ed = 23 * 3600 + 59 * 60 + 59;

    vector<pii> ans;

    for (auto [l, r] : a)
    {
        if (l != now)
        {
            ans.emplace_back(now, l);
        }
        now = r;
    }

    if (now != ed)
    {
        ans.emplace_back(now, ed);
    }

    for (auto [l, r] : ans)
    {
        int h, m, s;
        h = l / 3600;
        m = l % 3600 / 60;
        s = l % 60;
        cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << ':' << s / 10 << s % 10 << " - ";
        h = r / 3600;
        m = r % 3600 / 60;
        s = r % 60;
        cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << ':' << s / 10 << s % 10 << "\n";
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
