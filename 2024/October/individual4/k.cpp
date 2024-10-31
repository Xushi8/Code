// 2024/10/23 14:23:46
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

array<int, 26> operator-(array<int, 26> const& lhs, array<int, 26> const& rhs)
{
    auto res = lhs;
    for (size_t i = 0; i < 26; i++)
    {
        res[i] -= rhs[i];
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<array<int, 26>> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i];
        sum[i + 1][s[i] - 'a']++;
    }

    // [0, i), [i, n)

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        auto l = sum[i - 1];
        auto r = sum[n] - sum[i - 1];
        int now = 0;
        for (size_t j = 0; j < 26; j++)
        {
            if (l[j] > 0 && r[j] > 0)
            {
                now++;
            }
        }
        ans = max(ans, now);
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
