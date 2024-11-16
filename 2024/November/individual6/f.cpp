// 2024/11/15 19:06:30
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
    string s;
    cin >> s;
    int pairs = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            pairs++;
        }
    }
    for (int i = 0; i < pairs; i++)
    {
        cout << 0;
    }
    if (n % 2 == 0)
    {
        bool ok = 1;
        for (int i = pairs; i <= n - pairs; i++)
        {
            cout << ok;
            ok = !ok;
        }
    }
    else
    {
        for (int i = pairs; i <= n - pairs; i++)
        {
            cout << 1;
        }
    }
    for (int i = n - pairs + 1; i <= n; i++)
    {
        cout << 0;
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
