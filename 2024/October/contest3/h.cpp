// 2024/10/19 18:56:38
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
    vector<i64> t(n), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (t[i] < i + 1)
        {
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> lens;
    for (int i = 0; i < n;)
    {
        int j;
        for (j = i; j < n && t[i] == t[j]; j++) {}
        lens.emplace_back(j - i);
        i = j;
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
