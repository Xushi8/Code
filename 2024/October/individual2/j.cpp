// 2024/10/09 14:06:39
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

int par[N];
int siz[N];
void init(int n)
{
    iota(par, par + n, 0);
    fill(siz, siz + n, 1);
}

int find(int x)
{
    if (x == par[x])
        return x;
    else
    {
        int p = find(par[x]);
        siz[p] += siz[x];
        siz[x] = 0;
        par[x] = p;
        return p;
    }
}

pii unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return {};
    par[x] = y;
    pii res = {siz[x], siz[y]};
    siz[y] += siz[x];
    siz[x] = 0;
    return res;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n != 0)
    {
        vector<set<int>> G(n * 2);
        unordered_map<string, int> mp1;
        vector<int> in(n * 2), out(n * 2);
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            string x, y;
            cin >> x >> y;
            if (!mp1.contains(x))
            {
                mp1.emplace(x, mp1.size());
            }
            if (!mp1.contains(y))
            {
                mp1.emplace(y, mp1.size());
            }
            int dx = mp1[x];
            int dy = mp1[y];
            if (G[dx].contains(dy))
            {
                flag = 0;
            }
            G[dy].emplace(dx);
            in[dx]++;
            out[dy]++;

            unite(mp1[x], mp1[y]);
        }

        if (!flag)
        {
            cout << "No\n";
            continue;
        }

        queue<int> que;
        for (size_t i = 0; i < mp1.size(); i++)
        {
            if (in[i] == 0)
            {
                que.emplace(i);
            }
        }

        vector<int> ans;
        while (!que.empty())
        {
            auto u = que.front();
            que.pop();
            ans.emplace_back(u);
            for (auto v : G[u])
            {
                if (--in[v] == 0)
                {
                    que.emplace(v);
                }
            }
        }

        set<int> st;
        int winer = 0;
        for (size_t i = 0; i < mp1.size(); i++)
        {
            if (out[i] == 0)
            {
                winer++;
            }
            st.emplace(find(i));
        }

        cout << (ans.size() == mp1.size() && winer == 1 && st.size() == 1 ? "Yes" : "No") << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
