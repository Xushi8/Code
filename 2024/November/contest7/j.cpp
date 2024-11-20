// 2024/11/20 13:25:33
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
constexpr int N = 1e5 + 6;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    vector<int> cx(N), cy(N), cz(N);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        cx[a[i][0]]++;
        cy[a[i][1]]++;
        cz[a[i][2]]++;
    }

    vector<int> deg(n);

    for (int i = 0; i < n; i++)
    {
        deg[i] = max({cx[a[i][0]], cy[a[i][1]], cz[a[i][2]]});
    }

    vector<int> ans{deg.begin(), deg.end()};
    sort(ans.begin(), ans.end(), greater<>());

    for (int k = 0; k < n; k++)
    {
        auto it = lower_bound(ans.begin(), ans.end(), k, greater<>());
        ans.erase(it, ans.end());
        cout << n - ans.size() << ' ';
    }
    cout << '\n';
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
