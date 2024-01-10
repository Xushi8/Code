// 2023/11/08 13:00:31
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

char s[105];

bool is_prime(ll val)
{
    if (val < 2)
    {
        return false;
    }

    for (ll i = 2; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, d;
    while (cin >> n >> d)
    {
        // cout << n << ' ' << d << '\n';

        ll tot = 0;
        ll tmp = n;
        while (tmp)
        {
            s[tot++] = tmp % d;
            tmp /= d;
        }
        ll m = 0;
        ll wei = 1;
        for (ll i = tot - 1; i >= 0; i--)
        {
            m += s[i] * wei;
            wei *= d;
        }

        if (is_prime(n) && is_prime(m))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}