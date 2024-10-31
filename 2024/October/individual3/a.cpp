// 2024/10/16 13:01:05
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
    string s;
    cin >> s;
    array<vector<int>, 26> cnt;
    for (size_t i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'A'].emplace_back(i);
    }

    i64 ans = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < 26; j++)
        {
            auto it1 = lower_bound(cnt[j].begin(), cnt[j].end(), i);
            auto it2 = upper_bound(cnt[j].begin(), cnt[j].end(), i);
            int l = it1 - cnt[j].begin();
            int r = cnt[j].end() - it2;
            if (l > 0 && r > 0)
            {
                ans += i64(l) * r;
            }
        }
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
