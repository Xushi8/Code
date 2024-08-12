// 2024/08/09 12:15:05
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    auto L = [&](int i)
    {
        return (i - k + n) % n;
    };
    auto R = [&](int i)
    {
        return (i + k) % n;
    };

    if (k > n / 2)
    {
        cout << (count(a.begin(), a.end(), 0) == n ? "YES" : "NO") << '\n';
        return;
    }

    auto func = [&](vector<int> const& b)
    {
        if (b.size() % 2 == 1)
        {
            i64 sum = reduce(b.begin(), b.end(), i64(0));
            if (sum % 2 == 1)
            {
                return false;
            }
            sum /= 2;
            i64 even_sum = 0;
            for (size_t i = 0; i < b.size(); i++)
            {
                if (i % 2 == 0)
                    even_sum += b[i];
            }
            size_t m = b.size();
            vector<i64> t(m);
            t.back() = even_sum - sum;
            for (int i = m - 1; i > 0; i--)
            {
                t[i - 1] = b[i] - t[i];
            }
            return *min_element(t.begin(), t.end()) >= 0;
        }

        i64 odd_sum = 0, even_sum = 0;
        for (size_t i = 0; i < b.size(); i++)
        {
            if (i % 2 == 0)
                even_sum += b[i];
            else
                odd_sum += b[i];
        }
        if (odd_sum != even_sum)
            return false;

        i64 ulim = b[1], dlim = 0;
        i64 now = b[1];
        for (size_t i = 2; i < b.size(); i++)
        {
            if (i % 2 == 0)
            {
                now -= b[i];
                dlim = max(dlim, now);
            }
            else
            {
                now += b[i];
                ulim = min(ulim, now);
            }
        }
        return dlim <= ulim;
    };

    vector<int> vis(n);
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vector<int> b;
            int now = i;
            while (!vis[now])
            {
                vis[now] = 1;
                b.push_back(a[now]);
                now = R(now);
            }
            ok &= func(b);
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}