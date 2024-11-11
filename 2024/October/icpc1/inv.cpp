#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
int qpow(int64_t a, size_t n)
{
    int64_t b = 1;
    while (n) {
        if (n & 1)
            b = b * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return b;
}

vector<int> fac, inv, inv_fac;

void init_inv(int n) {
    fac.resize(n + 1);
    inv.resize(n + 1);
    inv_fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = int64_t(fac[i - 1]) * i % MOD;
    }
    inv_fac.back() = qpow(fac.back(), MOD - 2);
    for (int i = n; i > 0; i--) {
        inv_fac[i - 1] = int64_t(inv_fac[i]) * i % MOD;
        inv[i] = inv_fac[i] * fac[i - 1] % MOD;
    }
}