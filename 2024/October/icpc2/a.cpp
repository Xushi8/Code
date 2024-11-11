#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> limit(k);
    for (int i = 0; i < k; i++)
    {
        cin >> limit[i];
    }

    map<string, vector<pii>> mp;
    for (int i = 0; i < n; i++)
    {
        int val;
        string name;
        cin >> val >> name;
        mp[name].emplace_back(val, i);
    }
    for (auto &[name, pa] : mp)
    {
        sort(pa.begin(), pa.end(), greater<>());
    }
    int minn = *min_element(limit.begin(), limit.end());
    vector<int> ans(n, -1);
    vector<pii> all;
    for (auto const &[name, pa] : mp)
    {
        std::copy(pa.begin(), pa.begin() + min<size_t>(minn, pa.size()), back_inserter(all));
    }
    sort(all.begin(), all.end(), greater<>());
    for (auto const &[name, pa] : mp)
    {
        for (int i = 0; i < (int)pa.size(); i++)
        {
            auto it = lower_bound(all.begin(), all.end(), pa[i], greater<>());
            auto &rank = ans[pa[i].second];
            if (it != all.end())
            {
                rank = it - all.begin() + 1;
                if (i != 0 && i >= minn)
                    rank--;
            }
            else
            {
                rank = all.size();
            }
        }
    }

    for (auto x : ans)
    {
        cout << x << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--)
    {
        solve();
    }

    return 0;
}