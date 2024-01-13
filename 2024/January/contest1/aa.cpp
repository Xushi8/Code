// 2024/01/12 14:33:24
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

    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    map<int, int> mp;
    bool flag = 0;
    ll last = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, x;
            cin >> i >> x;
            if (!flag)
            {
                sum += x - a[i];
                a[i] = x;
            }
            else
            {
                auto it = mp.find(i);
                if (it != mp.end())
                {
                    sum += x - it->second;
                    it->second = x;
                }
                else
                {
                    sum += x - last;
                    mp[i] = x;
                }
            }
        }
        else
        {
            ll x;
            cin >> x;
            sum = x * n;
            flag = 1;
            mp.clear();
            last = x;
        }

        cout << sum << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}