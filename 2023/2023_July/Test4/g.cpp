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
    if (n & 1)
        cout << "Bob\n";
    else
    {
        int cnt = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            cnt++;
        }
        if (n > 1)
            cout << "Alice\n";
        else
            if (cnt & 1)
                cout << "Bob\n";
            else
                cout << "Alice\n";
    }
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