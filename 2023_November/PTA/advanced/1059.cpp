// 2023/11/16 22:14:53
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
#define int ll
constexpr int N = 1000005;

vector<int> primes;
bool isnp[N];

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
            if (p * i > N)
            {
                break;
            }

            isnp[p * i] = 1;

            if (i % p == 0)
            {
                break;
            }
        }
    }
}

int cnt[N];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();

    int n;
    cin >> n;
    int m = n;

    if (n == 1 || n == 2 || n == 3)
    {
        cout << n << '=' << n << endl;
        return 0;
    }

    for (int p : primes)
    {
        if (p * p > n)
        {
            break;
        }

        while (n % p == 0)
        {
            n /= p;
            cnt[p]++;
        }
    }
    if (n != 1)
    {
        cnt[n]++;
    }
    cout << m << '=';

    bool flag = 0;
    for (int i = 2; i * i <= m; i++)
    {
        if (cnt[i] != 0)
        {
            if (flag)
            {
                cout << '*';
            }
            flag = 1;
            cout << i;
            if (cnt[i] > 1)
            {
                cout << '^' << cnt[i];
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}