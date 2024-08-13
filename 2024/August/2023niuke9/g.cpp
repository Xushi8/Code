// 2024/08/12 12:02:55
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

    // cout << bitset<5>(k) << '\n';
    // for (int i = 0; i < n; i++)
    // {
    //     cout << bitset<5>(a[i]) << '\n';
    // }
    // cout << '\n';

    if (n == 1)
    {
        cout << (k == a[0] ? "Bob" : "Draw") << '\n';
        return;
    }

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.count(k ^ a[i]))
        {
            cout << "Alice" << '\n';
            return;
        }
        st.emplace(a[i]);
    }
    cout << "Draw" << '\n';
}