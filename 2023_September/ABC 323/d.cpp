// 2023/10/07 21:30:03
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
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }

    ll ans = 0;
    // for (auto [x, y] : mp)
    // {
    //     mp[x * 2] += y / 2;
    //     if (y & 1)
    //         y = 1;
    //     else
    //         y = 0;
    // }

    
    while (1)
    {
        bool flag = 1;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            auto [x, y] = *it;
            mp[x * 2] += y / 2;
            if (y >= 2)
                flag = 0;
            
            if (y & 1)
                it->second = 1;
            else
                it->second = 0;
        }

        if (flag)
            break;
    }

    for (auto [x, y] : mp)
    {
        ans += y;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}