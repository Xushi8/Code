// 2024/10/19 18:32:36
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
    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1)
    {
        cout << "NO" << '\n';
        return;
    }

    multiset<i64> st{a.begin(), a.end()};

    bool is_first = true;
    while (st.size() >= 1)
    {
        auto maxx = *--st.end();
        if (maxx > sum - maxx) // maxx != sum - maxx    always!
        {
            cout << (is_first ? "YES" : "NO") << '\n';
            return;
        }
        
        auto x = *st.begin();
        st.erase(st.begin()); // is st.begin() O(1)
        auto y = *st.begin();
        st.erase(st.begin());
        st.emplace(x + y);
        is_first = !is_first;
    }
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
