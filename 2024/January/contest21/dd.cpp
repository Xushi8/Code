// 2024/01/18 09:54:43
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<pii, int>> a;
    a.reserve(2 * n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        a.emplace_back(make_pair(l, -1), i);
        a.emplace_back(make_pair(r, 1), i);
        mp[l] = i;
        mp[r] = i;
    }

    sort(a.begin(), a.end());
    vector<int> ans(n, -1);

    stack<pii> sl, sr;
    int adds = 0;
    for (auto [tmp, id] : a)
    {
        auto [x, y] = tmp;
        if (y == -1)
        {
            sl.emplace(x, -adds);
        }
        else
        {
            if (mp[sl.top().first] == id)
            {
                ans[id] = sl.top().second + adds;
                sl.pop();
                while (!sl.empty() && !sr.empty())
                {
                    if (mp[sl.top().first] == mp[sr.top().first])
                    {
                        ans[mp[sl.top().first]] = sl.top().second + adds;
                        sl.pop(); sr.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                adds++;
            }
            else
            {
                sr.emplace(y, -111);
            }
        }
    }

    while (!sl.empty())
    {
        ans[mp[sl.top().first]] = sl.top().second + adds;
        sl.pop();
    }

    for (auto x : ans)
    {
        cout << x << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}