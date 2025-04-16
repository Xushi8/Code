// 2025/04/16 20:12:59
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
    int n, m;
    cin >> n >> m;
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(m);
        for (int j = 0; j < m; j++)
        {
            cin >> tmp[j];
        }
        mp[tmp]++;
    }

    vector<pair<int, vector<int>>> ans;
    ans.reserve(mp.size());
    for (auto const& [vec, cnt] : mp)
    {
        ans.emplace_back(cnt, vec);
    }

    sort(ans.begin(), ans.end(), [](pair<int, vector<int>> const& lhs, pair<int, vector<int>> const& rhs)
        {
        if(lhs.first != rhs.first) {
            return lhs.first > rhs.first;
        }
        else
        {
            return lhs.second < rhs.second;
        } });

    cout << ans.size() << '\n';
    for (auto const& [cnt, vec] : ans)
    {
        cout << cnt;
        for (int i = 0; i < m; i++)
        {
            cout << ' ' << vec[i];
        }
        cout << '\n';
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
