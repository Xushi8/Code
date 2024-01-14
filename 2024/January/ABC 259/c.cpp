// 2024/01/13 21:40:27
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

vector<pair<char, int>> func(string const& s)
{
    vector<pair<char, int>> res;
    for (size_t i = 0; i < s.size(); )
    {
        size_t j = i + 1;
        if (j < s.size() && s[i] == s[j])
        {
            res.emplace_back(s[i], 1);
            while (j < s.size() && s[j] == s[i])
            {
                j++;
                res.back().second++;
            }
            i = j;
        }
        else
        {
            res.emplace_back(s[i], 1);
            i++;
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    // size_t i = 0, j = 0;
    // while (1)
    // {
    //     if (i == s.size() || j == s.size())
    //     {
    //         break;
    //     }
    //     if (s[i] != t[j])
    //     {
    //         break;
    //     }
    //     size_t nowi = i;
    //     while (i < s.size() && j < t.size() && s[i] == t[j] && s[i] == s[nowi])
    //     {
    //         i++;
    //         j++;
    //     }
    //     size_t len = i - nowi;
    //     if (len >= 2)
    //     {
    //         while (j < t.size() && t[j] == s[nowi])
    //         {
    //             j++;
    //         }
    //     }
    // }

    // if (i == s.size() && j == t.size())
    // {
    //     cout << "Yes\n";
    // }
    // else
    // {
    //     cout << "No\n";
    // }

    auto x = func(s);
    auto y = func(t);
    bool flag = 1;
    if (x.size() != y.size())
    {
        flag = 0;
    }

    if (flag)
    {
        for (size_t i = 0; i < x.size(); i++)
        {
            auto [a, cnta] = x[i];
            auto [b, cntb] = y[i];
            if (a != b)
            {
                flag = 0;
                break;
            }

            if (cnta > cntb || (cnta < cntb && cnta == 1))
            {
                flag = 0;
                break;
            }
        }
    }

    cout << (flag ? "Yes" : "No") << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}