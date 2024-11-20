// 2024/11/20 13:04:40
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
    int n, m, K;
    cin >> n >> m >> K;
    map<string, vector<pii>> mp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            string tmp;
            for (int k = 0; k < K; k++)
            {
                char ch;
                cin >> ch;
                tmp += ch;
            }

            mp[tmp].emplace_back(i, j);
        }
    }

    pii ans;
    if (mp.begin()->second.size() == 1)
    {
        ans = mp.begin()->second.front();
    }
    else
    {
        ans = (++mp.begin())->second.front();
    }

    cout << ans.first << ' ' << ans.second << '\n';
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
