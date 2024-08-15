// 2024/08/13 12:04:03
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
     // int n, k;
    // cin >> n >> k;
    // deque<i64> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // sort(a.begin(), a.end());

    // i64 ans = 0;
    // i64 dec = 0;
    // while (!a.empty())
    // {
    //     int x = a.back();
    //     a.pop_back();
    //     x -= dec;
    //     bool flag = false;
    //     while (1)
    //     {
    //         int dec1 = x - x / k;
    //         int dec2 = a.size() + 1;
    //         if (dec1 >= dec2)
    //         {
    //             x /= k;
    //             ans++;
    //             flag = true;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }

    //     x += dec;
    //     if (x - dec > 0)
    //     {
    //         auto it = lower_bound(a.begin(), a.end(), x);
    //         a.insert(it, x);
    //     }
    //     if (!flag)
    //     {
    //         ans += a.front() - dec;
    //         dec += a.front() - dec;
    //         auto it = upper_bound(a.begin(), a.end(), dec);
    //         a.erase(a.begin(), it);
    //     }
    // }

    // cout << ans << '\n';

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    multiset<i64> st(a.begin(), a.end());
    i64 ans = 0;
    i64 dec = 0;
    while (!st.empty())
    {
        i64 x = *--st.end();
        st.erase(--st.end());
        x -= dec;
        bool flag = false;
        while (1)
        {
            int dec1 = x - x / k;
            int dec2 = st.size() + 1;
            if (dec1 >= dec2)
            {
                x /= k;
                ans++;
                flag = true;
            }
            else
            {
                break;
            }
        }
        x += dec;
        if (x - dec > 0)
        {
            st.emplace(x);
        }
        if (!flag)
        {
            ans += *st.begin() - dec;
            dec += *st.begin() - dec;
            st.erase(st.begin(), st.upper_bound(dec));
        }
    }

    cout << ans << '\n';
}

