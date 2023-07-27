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
#include <cmath>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

bool isnp[N];
vector<int> primes;


void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
        {
            primes.emplace_back(i);
        }
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


ull func(ll n, ll k)
{
    if (n / k < k)
        return 0;

    ll tmp = n;
    ull res = 1;
    for (int p : primes)
    {
        if (p * p > tmp)
            break;

        if (tmp % p == 0)
        {
            int cnt = 0;
            while (tmp % p == 0)
            {
                tmp /= p;
                cnt++;
            }

            res *= cnt + 1;
        }
    }

    if (tmp > 1)
        res *= (1 + 1);

    res /= 2;
    for (ll i = 1; i < k; i++)
    {
        if (n % i == 0)
            res--;

    }

    return res;

    
    // int target = (int)sqrt(n);
    // int res = 0;
    // for (ll i = target; i >= k; i--)
    // {
    //     if (n % i == 0 && n / i >= k)
    //     {
    //         res++;
    //     }
    // }

    // return res;
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
        ll n, k;
        cin >> n >> k;
        cout << "Case " << Case++ << ": " << func(n, k) << '\n';
    }

    cout << flush;
    return 0;
}