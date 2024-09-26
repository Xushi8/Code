// 2024/09/26 14:54:35
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
constexpr int N = 1e8 + 6;

bool isnp[N];
vector<int> primes;
void get_primes()
{
    isnp[1] = 1;
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
    int p, q;
    cin >> p >> q;
    auto huiwen = [](int num)
    {
        int old = num;
        int n = 0;
        while (num)
        {
            n = n * 10 + num % 10;
            num /= 10;
        }
        return (old == n);
    };

    int sum1 = 0, sum2 = 0;
    int ans;
    for (int i = 1; i < N; i++)
    {
        sum1 = sum1 + !isnp[i];
        sum2 = sum2 + huiwen(i);
        if (1ll * sum1 * q <= 1ll * sum2 * p) [[likely]]
            ans = i;
    }

    cout << ans << '\n';
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
