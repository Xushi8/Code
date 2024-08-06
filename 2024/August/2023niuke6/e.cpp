// 2024/08/05 12:12:43
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;
        a[i] = x & 1;
    }

    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }

    a.emplace(a.begin(), 0);

    vector<int> index_of_odd;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            index_of_odd.emplace_back(i);
        }
    }

    if (index_of_odd.empty())
    {
        while (q--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            if (k > r - l + 1)
            {
                cout << "NO" << '\n';
                continue;
            }
            cout << (k <= r - l + 1 ? "YES" : "NO") << '\n';
        }
        return;
    }

    auto get_vec = [&](bool flag)
    {
        vector<pii> res;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                res.emplace_back(i, i);
            }
            else
            {
                if (!flag)
                {
                    flag = true;
                    continue;
                }

                auto it = upper_bound(index_of_odd.begin(), index_of_odd.end(), i);
                if (it != index_of_odd.end())
                {
                    res.emplace_back(i, *it);
                    i = *it;
                }
            }
        }
        return res;
    };

    auto vec1 = get_vec(true);
    auto vec2 = get_vec(false);
    
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (k > r - l + 1)
        {
            cout << "NO" << '\n';
            continue;
        }
        if ((sum[r] - sum[l - 1]) % 2 != 0)
        {
            cout << "NO" << '\n';
            continue;
        }

        auto get_cnt = [&](vector<pii> const& vec) -> int
        {
            auto it1 = lower_bound(vec.begin(), vec.end(), pii{l, 0}, [](pii lhs, pii rhs)
                {
                    return lhs.first < rhs.first;
                });
            auto it2 = lower_bound(vec.begin(), vec.end(), pii{0, r}, [](pii lhs, pii rhs)
                {
                    return lhs.second < rhs.second;
                });
            if (it1 != vec.end() && it1->first == l && it2 != vec.end() && it2->second == r)
            {
                return (it2 - it1 + 1);
            }
            else
            {
                return 0;
            }
        };

        int cnt = max(get_cnt(vec1), get_cnt(vec2));
        cout << (cnt >= k ? "YES" : "NO") << '\n';
    }
}