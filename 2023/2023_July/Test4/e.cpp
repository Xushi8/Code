// 2023/07/29 11:12:57
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

void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int p : primes)
        {
            if (p * p > x)
                break;

            while (x % p == 0)
            {
                x /= p;
                m[p]++;
            }
        }
        if (x > 1)
            m[x]++;
    }

    priority_queue<int> que;
    for (auto [x, y] : m)
    {
        que.emplace(y);
    }

    ull ans = 0;
    while (!que.empty())
    {
        int a = que.top(); que.pop();
        if (a == 1)
        {
            que.emplace(1);
            break;
        }

        ans += a / 2;
        if (a % 2 != 0)
            que.emplace(1);
    }

    ans += que.size() / 3;
    cout << ans << '\n';

    // for (auto [x, y] : m)
    // {
    //     cout << x << ' ' << y << '\n';
    // }
    // cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    cout << endl;
    return 0;
}