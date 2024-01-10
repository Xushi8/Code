// 2023/07/28 09:03:09
#ifndef DEBUG
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <climits>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;
typedef long long ll;

bool isnp[N];
vector<int> primes;
void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
        {
            primes.push_back(i);
        }
        for (ll j = 0; j < (ll)primes.size(); j++)
        {
            int p = primes[j];
            if (p * i >= N)
                break;

            isnp[p * i] = 1;

            if (i % p == 0)
            {
                break;
            }
        }
    }
}

bool vis[N];

ll get_index(ll n, ll x)
{
    ll l = 1, r = (ll)1e8;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (n * mid >= x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return r;
}

void solve()
{
    ll l, r;
    while (cin >> l >> r)
    {
        if (l == 1)
            l = 2;
        

        for (ll i = 0; i < (ll)primes.size(); i++)
        {
            for (ll j = l / primes[i]; j <= r / primes[i]; j++)
            {
                while (j <= 1)
                    j++;
                if (primes[i] * j > r || primes[i] * j < l)
                    continue;
                vis[primes[i] * j - l] = 1;
            }

        }

        vector<ll> tmp;
        for (ll i = 0; i <= r - l; i++)
        {
            if (!vis[i])
                tmp.push_back(i + l);
        }

        for (ll i = 0; i <= r - l; i++)
        {
            vis[i] = 0;
        }

        if (tmp.size() <= 1)
        {
            cout << "There are no adjacent primes.\n";
        }
        else
        {
            ll maxn = -INF, max_index = -1;
            ll minn = INF, min_index = -1;
            for (ll i = 0; i < (ll)(tmp.size() - 1); i++)
            {
                if (minn > tmp[i + 1] - tmp[i])
                {
                    minn = tmp[i + 1] - tmp[i];
                    min_index = i;
                }

                if (maxn < tmp[i + 1] - tmp[i])
                {
                    maxn = tmp[i + 1] - tmp[i];
                    max_index = i;
                }
            }

            cout << tmp[min_index] << ',' << tmp[min_index + 1] << " are closest, ";
            cout << tmp[max_index] << ',' << tmp[max_index + 1] << " are most distant.\n";
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();
    solve();

    cout << flush;
}