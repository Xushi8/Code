// 2025/04/16 20:01:04
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
    int n, m, s;
    cin >> n >> m >> s;
    vector<deque<char>> a(n + 1, deque<char>(m));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    stack<char> stk;
    while (1)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }

        if (x == 0)
        {
            if (!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }
            continue;
        }

        if (!a[x].empty())
        {
            if (stk.size() == s)
            {
                cout << stk.top();
                stk.pop();
            }
            stk.emplace(a[x].front());
            a[x].pop_front();
        }
    }

    cout << '\n';
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
