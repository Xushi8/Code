// 2024/07/30 13:39:31
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

constexpr int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    deque<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int ave = sum / n;
    int ave1;
    if (sum % n != 0)
    {
        ave1 = ave + 1;
    }
    else
    {
        ave1 = ave;
    }

    i64 ans = 1;

    while (a.size() >= 2)
    {
        while (a.back() > ave1 && a[a.size() - 2] < 100)
        {
            a[a.size() - 1]--;
            a[a.size() - 2]++;
        }
        while (a.front() < ave && a[1] > 1)
        {
            a[0]++;
            a[1]--;
        }

        ans *= a.front();
        cout << a.front() << ' ';
        ans %= MOD;
        sum -= a.front();
        a.pop_front();
        ans *= a.back();
        cout << a.back() << ' ';
        ans %= MOD;
        sum -= a.back();
        a.pop_back();

        ave = sum / n;
        if (sum % n != 0)
        {
            ave1 = ave + 1;
        }
        else
        {
            ave1 = ave;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        ans *= a[i];
        ans %= MOD;
        cout << a[i] << ' ';
    }
    cout << ans << '\n';
}