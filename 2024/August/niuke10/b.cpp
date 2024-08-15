// 2024/08/15 12:11:41
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
    int n, q;
    cin >> n >> q;
    map<string, string> mp;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        y.pop_back();
        mp.emplace(y, x);
    }

    while (q--)
    {
        string x;
        cin >> x;
        size_t pos = x.find('.');
        string y = x.substr(0, pos);
        string tar = mp[y];
        while (pos != string::npos)
        {
            size_t pos1 = x.find('.', pos + 1);
            string tmp = x.substr(pos + 1, pos1 - pos - 1);

            tar = tar.substr(4 + 1, tar.size() - 5 - 1);;

            stack<char> stk;
            size_t index = 0;
            for (size_t i = 0; i < tar.size(); i++)
            {
                if (tar[i] == '<')
                    stk.emplace('<');
                else if (tar[i] == '>')
                    stk.pop();
                else if (tar[i] == ',')
                {
                    if (stk.empty())
                    {
                        index = i;
                        break;
                    }
                }
            }
            if (tmp == "first")
            {
                tar = tar.substr(0, index);
            }
            else
            {
                tar = tar.substr(index + 1);
            }

            pos = pos1;
        }

        cout << tar << '\n';
    }
}