// 2023/07/29 09:38:28
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
const int N = 10005;
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    get_primes();
    int n;
    while (cin >> n && n)
    {
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        
        ull ans = 0;

        // 起始位置
        for (size_t i = 0; i < primes.size(); i++)
        {
            int p;
            int sum = 0;
            for (size_t j = i; j < primes.size(); j++)
            {
                p = primes[j];                
                sum += p;
                if (sum == n)
                {
                    ans++;
                    break;
                }
                if (sum > n)
                {
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

    cout << flush;
    return 0;
}