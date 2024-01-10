// 2023/07/21 20:37:38
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 100000005;

bool isnp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // vector<int> primes;
    // for (int i = 2; i < N; i++)
    // {
    //     if (!isnp[i])
    //         primes.emplace_back(i);

    //     for (int p : primes)
    //     {
    //         if (p * i >= N)
    //             break;

    //         isnp[p * i] = 1;

    //         if (i % p == 0)
    //             break;
    //     }
    // }

    int n, k;
    cin >> n >> k;
    // int tot = -1;
    // cout << (ll)primes[4 * n - 2] << '\n';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (tot == -1)
    //             cout << 1 * k << ' ', tot++;
    //         else
    //             cout << (ll)primes[tot++] * k << " \n"[j == 3];
    //     }
    // }

    int tot = 1;

    cout << k * ((n - 1) * 6 + 5) << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << tot * k << ' ' << (tot + 1) * k << ' ' << (tot + 2) * k << ' ' << (tot + 4) * k << '\n';
        tot += 6;
    }

    cout << endl;
    return 0;
}