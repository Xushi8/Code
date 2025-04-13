// 2025/04/13 20:09:33
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
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<string, set<string>> G;
    map<string, int> in;

    auto func = [&](auto&& self, int l, int r, int deep) -> void
    {
        if (deep < 0)
        {
            return;
        }

        // [l, r) deep 之前所有的都相同
        while (deep > 0)
        {
            deep--;
            for (int i = l; i < r; i++)
            {
                string& s = a[i];
                size_t pos = s.find('.');
                in.try_emplace(s.substr(0, pos), 0);
                s = s.substr(pos + 1);
            }
        }

        vector<pii> qujian;
        for (int i = l; i < r;)
        {
            int j;
            for (j = i + 1; j < r; j++)
            {
                size_t pos1 = a[i].find('.');
                size_t pos2 = a[j].find('.');
                if (a[i].substr(0, pos1) != a[j].substr(0, pos2))
                {
                    break;
                }
            }
            qujian.emplace_back(i, j);
            i = j;
        }

        for (size_t i = 0; i + 1 < qujian.size(); i++)
        {
            string const& minn = a[qujian[i].first];
            size_t pos = minn.find('.');
            string vx = minn.substr(0, pos);

            string const& maxx = a[qujian[i + 1].first];
            pos = maxx.find('.');
            string vy = maxx.substr(0, pos);
            G[vx].emplace(vy);
            in.try_emplace(vx, 0);
            in[vy]++;
        }

        for (auto [x, y] : qujian)
        {
            if (a[x].find('.') != string::npos) // 有后续
            {
                self(self, x, y, 1);
            }
        }
    };

    for (int i = 0; i < n;)
    {
        int c_now = count(a[i].begin(), a[i].end(), '.');
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (c_now != count(a[j].begin(), a[j].end(), '.'))
            {
                break;
            }
        }
        // [i, j) 位数相同
        func(func, i, j, 0);

        i = j;
    }

    // 拓扑
    priority_queue<string, vector<string>, greater<>> que;
    for (auto const& [s, in_val] : in)
    {
        if (in_val == 0)
        {
            que.emplace(s);
        }
    }

    vector<string> ans;
    while (!que.empty())
    {
        string u = que.top();
        que.pop();
        ans.emplace_back(u);
        for (auto const& v : G[u])
        {
            if (--in[v] == 0)
            {
                que.emplace(v);
            }
        }
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        if (i != 0)
        {
            cout << '.';
        }
        cout << ans[i];
    }
    cout << '\n';
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
