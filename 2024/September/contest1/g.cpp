// 2024/09/28 14:37:08
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
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];

    vector<int> not_equal;
    for (int i = 0; i < n; i++)
    {
        if (s[0][i] != s[1][i])
            not_equal.emplace_back(i);
    }

    if (not_equal.size() % 2 != 0)
    {
        cout << "-1\n";
        return;
    }

    vector<pii> ans;

    vector<int> n0, n1;
    for (int j = 0; j < n; j++)
    {
        if (s[0][j] != s[1][j])
        {
            if (s[0][j] < s[1][j])
                n0.emplace_back(j);
            else
                n1.emplace_back(j);
        }
    }

    while (n0.size() >= 2)
    {
        auto x = n0.back();
        n0.pop_back();
        auto y = n0.back();
        n0.pop_back();
        ans.emplace_back(x, y);
    }
    while (n1.size() >= 2)
    {
        auto x = n1.back();
        n1.pop_back();
        auto y = n1.back();
        n1.pop_back();
        ans.emplace_back(x, y);
    }

    if (!n0.empty())
    {
        // n0.size() == n1.size() == 1
        auto x = n0.back();
        n0.pop_back();
        auto y = n1.back();
        n1.pop_back();
        ans.emplace_back(x, x);
        ans.emplace_back(x, y);
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
    {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}