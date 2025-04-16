// 2025/04/16 19:52:33
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
    vector<i64> a(2);
    int n;
    cin >> a[0] >> a[1] >> n;
    int now = 0;
    for (; a.size() < n; now++)
    {
        i64 t = a[now] * a[now + 1];
        if (t == 0)
        {
            a.emplace_back(0);
            continue;
        }
        stack<int> stk;
        while (t)
        {
            stk.emplace(t % 10);
            t /= 10;
        }
        while (!stk.empty())
        {
            a.emplace_back(stk.top());
            stk.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << a[i];
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
