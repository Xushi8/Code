#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve()
{
    int all_money, n, m, k;
    cin >> all_money >> n >> m >> k;
    vector<vector<array<int, 3>>> G(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        u--;
        v--;
        G[u].push_back({v, w, c});
        G[v].push_back({u, w, c});
    }

    vector<int> vis(n);
    vector<int> maxx(n);
    set<int> ans;
    auto dfs = [&](auto &&self, int u, int money, int sum) -> void
    {
        for (auto [v, w, c] : G[u])
        {
            if (vis[v] || w > money)
            {
                continue;
            }
            vis[v] = 1;
            ans.emplace(v);
            maxx[v] = max(maxx[v], sum + c);
            self(self, v, money - w, sum + c);
            vis[v] = false;
        }
    };

    vector<int> query(k);
    for (int i = 0; i < k; i++)
    {
        cin >> query[i];
        query[i]--;
    }

    for (auto root : query)
    {
        vis[root] = 1;
        dfs(dfs, root, all_money, 0);

        vector<int> can{ans.begin(), ans.end()};
        if(can.empty()) {
            cout << "T_T\n"; 
        } else {
            for (int i = 0; i < can.size(); i++) {
                if(i != 0) {
                    cout << ' ';
                }
                cout << can[i] + 1;
            }
            cout << '\n';

            map<int, vector<int>, greater<>> mp;
            for(auto u : can) {
                mp[maxx[u]].emplace_back(u);
            }

            auto const &vec = mp.begin()->second;
            for (int i = 0; i < vec.size(); i++){ 
                if(i != 0) {
                    cout << ' ';
                }
                cout << vec[i] + 1;
            }
            cout << '\n';
        }

        ans.clear();
        fill(vis.begin(), vis.end(), 0);
        fill(maxx.begin(), maxx.end(), 0);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}