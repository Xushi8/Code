#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

struct node
{
    int x;
    int16_t l, r;
    node(int xx, int ll, int rr) : x(xx), l(ll), r(rr) {}
    friend constexpr bool operator>(node const &lhs, node const &rhs)
    {
        return lhs.x > rhs.x;
    }
};


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    set<node, greater<>> st;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<char>> valid(n, vector<char>(m, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;
            st.insert({x, i, j});
        }
    }

    while (k--)
    {
        auto [maxx, be_x, be_y] = *st.begin();
        for (int i = 0; i < n; i++)
        {
            if (valid[i][be_y])
            {
                valid[i][be_y] = 0;
                st.erase({a[i][be_y], i, be_y});
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (valid[be_x][j])
            {
                valid[be_x][j] = 0;
                st.erase({a[be_x][j], be_x, j});
            }
        }
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            if (valid[i][j])
            {
                tmp.emplace_back(a[i][j]);
            }
        }
        if (!tmp.empty())
        {
            ans.emplace_back(std::move(tmp));
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (j != 0)
            {
                cout << ' ';
            }
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}