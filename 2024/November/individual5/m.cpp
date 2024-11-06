// 2024/11/06 15:58:36
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    stack<int> stk;
    vector<int> L(n), R(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && a[stk.top()] < a[i])
            stk.pop();
        R[i] = stk.empty() ? n : stk.top();
        stk.emplace(i);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = R[i] - 1;
        ans += r - l + 1;
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
