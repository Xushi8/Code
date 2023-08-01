// 2023/07/31 19:46:17
#ifndef LOCAL
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
vector<int> primes;

void get_prime()
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

    // get_prime();
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> used(25005, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            used[arr[i]] = 2;
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i <= arr.back(); i++)
        {
            if (used[i] > 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i + arr[j] <= arr.back())
                    {
                        used[i + arr[j]] = 1;
                    }
                    else
                        break;
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < 25005; i++)
        {
            ans += (used[i] == 2);
        }
        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}