// 2023/07/28 09:03:09
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
const int N = 1000005;


bool isnp[N];
int phi[N];
vector<int> primes;
void get_primes()
{
    phi[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
        {
            primes.emplace_back(i);
            phi[i] = i - 1;
        }
        for (int p : primes)
        {
            if (p * i >= N)
                break;

            isnp[p * i] = 1;

            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }

    // for (int i = 1; i < 100; i++)
    //     cout << phi[i] << '\n';
}

ll solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll res = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i] + 1; j < N; j++)
        {
            if (phi[j] >= arr[i])
            {
                res += j;
                break;
            }
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    get_primes();
    int tt = 1;
    cin >> tt;
    int Case = 1;
    while (tt--)
    {
        cout << "Case " << Case++ << ": " << solve() << " Xukha\n";
    }

    cout << flush;
}