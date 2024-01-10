// 2023/10/22 16:05:10
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

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    ll ans = 0;
    int cnt = 0;
    while (!mp.empty())
    {
        vector < map<int, int>::iterator> to_be_erase;
        auto it = mp.begin();
        to_be_erase.push_back(it);
        int now = 0;
        int tar = it->first;
        now += it->second;
        it++;
        for ( ; it != mp.end(); it++)
        {
            int tmp = __gcd(tar, it->first);
            if (tmp != 1)
            {
                to_be_erase.push_back(it);
                tar = tmp;
                now += it->second;
            }
        }

        ans += now * (n - cnt - now);
        cnt += now;
        for (auto x : to_be_erase)
        {
            mp.erase(x);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}