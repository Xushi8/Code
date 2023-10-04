// 2023/10/04 11:55:52
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, k;
    cin >> n >> m >> k;
    if (n == 1)
    {
        cout << m << endl;
        return 0;
    }

    auto check = [&](ll val) -> bool
        {
            ll nl = k, nr = n - k;
            ll suml = nl * val + (nl * (nl - 1) / 2) * -1;
            ll sumr = nr * (val - 1) + (nr * (nr - 1) / 2) * -1;
            ll a1 = val - (nl - 1);
            ll an = val - 1 - (nr - 1);
            if (a1 <= 0)
            {
                a1 = -a1;
                suml += (a1 + 1) * (a1 + 0) / 2 + (a1 + 1);
            }
            if (an <= 0)
            {
                an = -an;
                sumr += (an + 1) * (an + 0) / 2 + (an + 1);
            }

            return suml + sumr <= m;
        };

    ll l = 1, r = m;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid + 1))
            l = mid + 1;
        else
            r = mid;
    }

    cout << l << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}