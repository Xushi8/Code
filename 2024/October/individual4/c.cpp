// 2024/10/23 14:19:46
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
    set<string> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp.emplace(s);
    }

    set<string> vis;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        auto it1 = mp.find(s);
        auto it2 = vis.find(s);
        if (it1 != mp.end() && it2 == vis.end())
        {
            cout << "OK" << '\n';
            vis.emplace(s);
        }
        else if (it1 == mp.end())
        {
            cout << "WRONG" << '\n';
        }
        else
        {
            cout << "REPEAT" << '\n';
        }
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
