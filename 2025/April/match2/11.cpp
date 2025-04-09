#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// void solve()
// {
//     int k;
//     cin >> k;

//     vector<vector<int>> a(k);
//     for (int i = k - 1; i >= 0; i--)
//     {
//         int num = 1 << i;
//         vector<int> tmp(num);
//         for (int j = 0; j < num; j++)
//         {
//             cin >> tmp[j];
//         }
//         a[i] = std::move(tmp);
//     }

//     int winner;
//     cin >> winner;

//     deque<int> ans{winner};

//     for (int i = 0; i < k; i++)
//     {
//         deque<int> tmp;
//         vector<int> loser = a[i];
//         for (int j = a[i].size() - 1; j >= 0; j--)
//         {
//             tmp.emplace_front(loser[j]);
//             tmp.emplace_front(ans[j]);
//         }
//         ans = std::move(tmp);
//     }

//     reverse(a.begin(), a.end());
//     vector<int> t(ans.begin(), ans.end());
//     for (int i = 0; i < k; i++)
//     {
//         vector<int> win, lose;
//         for (int j = 0; j / 2 < a[i].size(); j += 2)
//         {
//             lose.emplace_back(min(t[j], t[j + 1]));
//             win.emplace_back(max(t[j], t[j + 1]));
//         }

//         if (lose != a[i])
//         {
//             cout << "No Solution\n";
//             return;
//         }
//         t = win;
//     }

//     for (int i = 0; i < 1 << k; i++)
//     {
//         if (i)
//             cout << ' ';
//         cout << ans[i];
//     }
//     cout << '\n';
// }

struct node
{
    int win, lose;
};

void solve()
{
    int k;
    cin >> k;

    int siz = (1 << k) - 1;
    vector<node> game(siz);

    for (int i = siz - 1; i >= 0; i--)
    {
        cin >> game[i].lose;
    }
    cin >> game[0].win;

    auto dfs = [&](auto&& self, int p)
    {
        if (p >= siz)
        {
            return true;
        }

        if (game[p].win < game[p].lose)
        {
            return false;
        }

        int l = (p * 2) + 1;
        int r = (p * 2) + 2;
        if (r >= siz)
        {
            return true;
        }

        game[l].win = game[p].win;
        game[r].win = game[p].lose;

        if (self(self, l) && self(self, r))
        {
            return true;
        }

        swap(game[l].win, game[r].win);

        return (self(self, l) && self(self, r));
    };

    bool ok = dfs(dfs, 0);
    if (ok)
    {
        ranges::reverse(game);
        for (int i = 0; i < (1 << (k - 1)); i++)
        {
            if (i != 0)
            {
                cout << ' ';
            }
            cout << game[i].lose << ' ' << game[i].win;
        }
        cout << '\n';
    }
    else
    {
        cout << "No Solution\n";
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
}
