// 2024/11/06 15:57:11
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
    vector<array<int, 3>> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> que{a.begin(), a.end()};

    while (que.size() >= 2)
    {
        auto [l1, r1, w1] = que.top();
        que.pop();
        auto [l2, r2, w2] = que.top();
        que.pop();

        if (l1 == l2)
        {
            if (r1 == r2)
            {
                if (w1 != w2)
                {
                    cout << "false\n";
                    return;
                }
            }
            else
            {
                que.push({r1 + 1, r2, w2 - w1});
            }
        }
        
        que.push({l2, r2, w2});
    }

    cout << "true\n";
}

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
