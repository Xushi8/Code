// 2024/09/25 13:01:20
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

bool isnp[N];
vector<i64> primes;
void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
            primes.emplace_back(i);
        for (auto p : primes)
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
    get_primes();

    i64 n;
    cin >> n;
    i64 ans = 0;
    for (size_t i = 0; i < primes.size(); i++)
    {
        auto a = primes[i];
        if (__int128_t(a) * a >= n)
            break;
        for (size_t j = i + 1; j < primes.size(); j++)
        {
            auto b = primes[j];
            if (__int128_t(a) * a * b >= n)
                break;
            for (size_t k = j + 1; k < primes.size(); k++)
            {
                auto c = primes[k];
                if (__int128_t(a) * a * b * c * c > n)
                    break;
                ans++;
                cout << a << ' ' << b << ' ' << c << '\n';
            }
        }
    }

    cout << ans << '\n';
}