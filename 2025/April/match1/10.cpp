#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    auto get_shou = [&](string_view sv) -> string
    {
        string ans;

        for (size_t i = 0; i < sv.size(); i++)
        {
            if (i == 0 || (sv[i - 1] == ' ' && sv[i] != ' '))
            {
                ans += sv[i];
            }
        }

        return ans;
    };

    map<string, vector<string>> mp;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        string t = get_shou(s);
        mp[t].emplace_back(s);
    }

    for (auto& [key, value] : mp)
    {
        sort(value.begin(), value.end());
    }

    int m;
    cin >> m;
    cin.get();
    for (int i = 0; i < m; i++)
    {
        string s;
        getline(cin, s);
        string t = get_shou(s);

        if (mp[t].empty())
        {
            cout << s << '\n';
        }
        else
        {
            cout << mp[t][0];
            for (int j = 1; j < mp[t].size(); j++)
            {
                cout << '|' << mp[t][j];
            }
            cout << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}
