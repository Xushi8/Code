// 2023/07/27 15:40:21
#pragma GCC optimize(2)
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
const int N = 10000005;

bool isnp[N];
vector<int> primes;

void get_primes()
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


ll func(int n)
{
    ll res = 0;
    for (size_t i = 0; i < primes.size() && primes[i] + primes[i] <= n; i++)
    {
        res += !isnp[n - primes[i]];
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();

    int tt;
    cin >> tt;
    int Case = 1;
    while (tt--)
    {
        int n;
        cin >> n;
        cout << "Case " << Case++ << ": " << func(n) << '\n';
    }

    cout << flush;
    return 0;
}