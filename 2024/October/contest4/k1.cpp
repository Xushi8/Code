// 2024/10/26 19:07:59
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
    int n, q;
    cin >> n >> q;
    multiset<int> st;
    map<int, int> mp;
    int cntr{};
    i64 suml{};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            st.emplace(x);
        }
        mp[i] = x;
        if (x > 0)
        {
            cntr++;
        }
        else
        {
            suml += x;
        }
    }

    while (q--)
    {
        int index, val;
        cin >> index >> val;
        index--;
        int old_val = mp[index];
        mp[index] = val;

        if (old_val > 0)
        {
            cntr--;
            auto it = st.find(old_val);
            if (it != st.end())
            {
                st.erase(it);
            }
            else
            {
                // suml 付出了代价, 这里找回来
                suml -= old_val;
            }
        }
        else
        {
            suml -= old_val;
        }

        if (val > 0)
        {
            cntr++;
            st.emplace(val);
        }
        else
        {
            suml += val;
        }

        while (!st.empty() && -suml >= *st.begin())
        {
            suml += *st.begin();
            st.erase(st.begin());
        }

        std::cerr << suml << ' ' << cntr << '\n';

        int r = cntr;
        int l = st.size();
        cout << (r - l + 1) << '\n';
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
