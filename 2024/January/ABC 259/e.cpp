// 2024/01/14 20:36:03
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
    map<int, int> mp;
    map<int, int> max_cnt;
    vector<vector<pii>> a(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int p, e;
            cin >> p >> e;
            a[i].emplace_back(p, e);
            auto it = mp.find(p);
            if (it == mp.end())
            {
                mp[p] = e;
                max_cnt[p] = 1;
            }
            else
            {
                if (e > it->second)
                {
                    mp[p] = e;
                    max_cnt[p] = 1;
                }
                else if (e == it->second)
                {
                    max_cnt[p]++;
                }
            }
        }
    }

    set<vector<pii>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<pii> tmp;
        for (int j = 0; j < a[i].size(); j++)
        {
            auto [p, e] = a[i][j];
            if (mp[p] == e && max_cnt[p] == 1)
            {
                tmp.emplace_back(p, e);
            }
        }

        sort(tmp.begin(), tmp.end());
        ans.emplace(tmp);
    }
    cout << ans.size() << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}