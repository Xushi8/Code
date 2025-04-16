// 2025/04/16 20:19:50
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
    vector<vector<int>> ope(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int to;
            cin >> to;
            to--;
            ope[i].emplace_back(to);
        }
    }

    vector<int> dang(105, -1);
    int now = 0;
    while (m--)
    {
        int op, x;
        cin >> op >> x;
        x--;
        if (op == 0)
        {
            now = ope[now][x];
        }
        else if (op == 1)
        {
            dang[x] = now;
            cout << now + 1 << '\n';
        }
        else
        {
            now = dang[x];
        }
    }
    cout << now + 1 << '\n';
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
