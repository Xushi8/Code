// 2024/01/23 20:47:42
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
constexpr int N = 10000005;

vector<int> primes;
bool isnp[N];
void init()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
            primes.emplace_back(i);
        for (int p : primes)
        {
            if (p * i >= N)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    ll tar;
    cin >> tar;
    ll ans = 0;
    for (size_t i = 1; i < primes.size(); i++)
    {
        ll x = 1LL * primes[i] * primes[i] * primes[i];
        if (x >= tar)
            break;

        size_t j;
        for (j = 0; j < i; j++)
        {
            if (x * primes[j] > tar)
                break;
        }
        ans += j;

        // ll l = 0, r = i - 1;
        // ll tmp = -1;
        // while (l <= r)
        // {
        //     ll mid = (l + r) / 2;
        //     if (primes[mid] * x <= tar)
        //     {
        //         tmp = mid;
        //         l = mid + 1;
        //     }
        //     else
        //     {
        //         r = mid - 1;
        //     }
        // }
        // ans += tmp + 1;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}