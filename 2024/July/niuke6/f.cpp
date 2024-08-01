// 2024/08/01 13:03:25
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

int deg[N];

struct cmp
{
    bool operator()(int const& l, int const& r) const noexcept
    {
        return deg[l] > deg[r] || l < r;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> G(n + 1);
    fill(deg, deg + n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace(v);
        G[v].emplace(u);
        deg[u]++;
        deg[v]++;
    }

    set<int, cmp> st;

    for (int i = 1; i <= n; i++)
    {
        st.emplace(i);
    }
    vector<int> ans;

    int u = *st.begin();
    st.erase(st.begin());
    while (1)
    {
        ans.emplace_back(u);
        bool flag = 0;

        for (auto v : st)
        {
            if (!G[u].count(v))
            {
                u = v;
                st.erase(v);
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    
    if (ans.size() != n)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (auto x : ans)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}