// 2024/11/09 15:14:19
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
        double x;
        cin >> x;
        a[i] = round(x * 100);
    }
    queue<int> b, c;

    i64 ans = 0;
    for (auto x : a)
    {
        int t = x % 5;
        if (t <= 2)
        {
            ans += x - t;
        }
        else
        {
            if (t == 3)
            {
                b.emplace(x);
            }
            else
            {
                c.emplace(x);
            }
        }
    }

    while (!b.empty() && !c.empty())
    {
        auto l = b.front();
        b.pop();
        auto r = c.front();
        c.pop();

        int x = l + r;
        int t = x % 5;
        ans += x - t;
    }

    while (c.size() >= 3) // b.empty()
    {
        auto x = c.front();
        c.pop();
        auto y = c.front();
        c.pop();
        auto z = c.front();
        c.pop();

        int tmp = x + y + z;
        int t = tmp % 5;
        ans += tmp - t;
    }

    while (b.size() >= 2) // c.empty()
    {
        auto l = b.front();
        b.pop();
        auto r = b.front();
        b.pop();

        int x = l + r;
        int t = x % 5;
        ans += x - t;
    }

    if (!b.empty()) // 0 or 1
    {
        ans += b.front();
        b.pop();
    }

    while (!c.empty()) // 0 or 1 or 2
    {
        ans += c.front();
        c.pop();
    }

    int l = ans / 100, r = ans % 100;
    cout << l << '.' << r / 10 << r % 10 << '\n';
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
