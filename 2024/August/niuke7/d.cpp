// 2024/08/06 12:45:39
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]].emplace_back(i);
    }

    vector<pii> qujian;
    for (auto const& [x, vec] : mp)
    {
        for (int i = 0; i + k - 1 < vec.size(); i++)
        {
            qujian.emplace_back(vec[i], vec[i + k - 1]);
        }
    }

    auto vec1 = qujian, vec2 = qujian;

    sort(vec1.begin(), vec1.end(), [](pii lhs, pii rhs)
        {
            return lhs.first < rhs.first;
        });
    sort(vec2.begin(), vec2.end(), [](pii lhs, pii rhs)
        {
            return lhs.second < rhs.second;
        });

    i64 ans = 0;
    

    cout << ans << '\n';
}