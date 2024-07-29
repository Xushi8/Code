// 2024/07/29 23:19:15
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;


void solve();

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    if (a.size() == 1)
    {
        cout << 2 * a.back() << '\n';
        return;
    }
    if (a.size() == 2)
    {
        cout << a[0] + a[1] << '\n';
        return;
    }

    vector<int> g1(a.size()), g2(a.size());
    g1.front() = a.front();
    for (int i = 1; i < a.size(); i++)
    {
        g1[i] = std::gcd(g1[i - 1], a[i]); // cpp17
    }

    g2.back() = a.back();
    for (int i = a.size() - 2; i >= 0; i--)
    {
        g2[i] = std::gcd(g2[i + 1], a[i]);
    }

    int ans = max(g1.front() + g2[1], g1[a.size() - 2] + g2.back());
    for (int i = 1; i < a.size() - 1; i++)
    {
        ans = max(ans, a[i] + std::gcd(g1[i - 1], g2[i + 1]));
    }
    cout << ans << '\n';
}