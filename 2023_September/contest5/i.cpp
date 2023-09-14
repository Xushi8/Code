// 2023/09/13 14:18:53
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        ll m, n;
        cin >> m >> n;
        cout << (1LL << m) - 1LL << '\n';
    }

    

    for (ll m = 1; m < 10; m++)
    {
        for (ll n = 0; n < (1LL << m); n++)
        {
            ll sum = 0;
            ll cnt = 0;
            for (ll i = 0; i < (1LL << m); i++)
            {
                if (i == n)
                    continue;
                sum ^= i;
                cnt++;
            }
            cout << "m = " << m << " n = " << n;
            cout << " 异或值 = " << sum << " ans = " << cnt << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}