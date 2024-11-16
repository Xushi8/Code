// 2024/11/15 10:43:38
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
        cin >> a[i];
    }

    vector<int> ans1(n), ans2(n);
    set<int> st;
    int mex;
    st.clear();
    mex = 0;

    for (int i = 0; i < n; i++)
    {
        st.emplace(a[i]);
        while (st.count(mex))
        {
            mex++;
        }
        ans1[i] = mex;
    }

    st.clear();
    mex = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        st.emplace(a[i]);
        while (st.count(mex))
        {
            mex++;
        }
        ans2[i] = mex;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (ans1[i] == ans2[i + 1])
        {
            cout << 2 << '\n';
            int l1 = 0, r1 = i;
            int l2 = i + 1, r2 = n - 1;
            cout << l1 + 1 << ' ' << r1 + 1 << '\n'
                 << l2 + 1 << ' ' << r2 + 1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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
