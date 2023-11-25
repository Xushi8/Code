// 2023/11/21 16:43:43
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
    string s;
    int n;
    cin >> s >> n;
    map<char, int> mp;
    int all = 0;
    for (auto ch : s)
    {
        mp[ch]++;
        all += (ch - 'a' + 1);
    }

    while (all > n)
    {
        auto it = --mp.end();
        char ch = it->first;
        int l = 1, r = it->second;
        int ans = 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (all - mid * (ch - 'a' + 1) > n)
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        all -= ans * (ch - 'a' + 1);
        it->second -= ans;
        if (it->second == 0)
        {
            mp.erase(it);
        }
    }

    for (char ch : s)
    {
        auto it = mp.find(ch);
        if (it == mp.end())
        {
            continue;
        }

        cout << ch;
        it->second--;
        if (it->second == 0)
        {
            mp.erase(it);
        }
    }
    cout << '\n';
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