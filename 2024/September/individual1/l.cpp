// 2024/09/26 12:59:37
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 4e4 + 5;

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
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    i64 ans = 0;
    for (int i = 2; i < n; i++)
    {
        ans += phi[i];
    }
    cout << 2 * ans + 3 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();
    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
