// 2024/01/24 16:37:41
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
constexpr int N = 1000005;

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

int func(int x)
{
    int res = 0;
    if (x % 2 == 0)
    {
        res++;
        while (x % 2 == 0)
            x /= 2;
    }
    for (int p : primes)
    {
        if (p * p > x)
            break;
        while (x % p == 0)
        {
            res++;
            x /= p;
        }
    }
    if (x != 1)
        res++;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum ^= func(x);
    }
    cout << (sum ? 'W' : 'L') << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}