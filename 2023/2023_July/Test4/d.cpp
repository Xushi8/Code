// 2023/07/29 10:04:54
#ifndef DEBUG
#pragma GCC optimize(2)
#endif
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1005;

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

int get_mul_of_yinzi(int n)
{
    int res = 1;
    for (int p : primes)
    {
        if (p * p > n)
            break;

        if (n % p == 0)
        {
            res *= p;
            while (n % p == 0)
                n /= p;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            m[x] = i;
        }

        int ans = -1;
        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                if (__gcd(i, j) == 1 && m.count(i) != 0 && m.count(j) != 0)
                {
                    ans = max(ans, m[i] + m[j]);
                }
            }
        }


        cout << ans << '\n';
    }

    cout << endl;
    return 0;
}