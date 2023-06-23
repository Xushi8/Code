// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// const int N = 5005;

// int primes[N], cnt;
// int sum[N];
// bool st[N];

// void get_primes(int n) {
//     for (int i = 2; i <= n; ++i) {
//         if (!st[i]) primes[cnt++] = i;
//         for (int j = 0; primes[j] <= n / i; ++j) {
//             st[primes[j] * i] = true;
//             if (i % primes[j] == 0) break;
//         }
//     }
// }

// // 直观，有溢出风险
// int get(int n, int p) {
//     int res = 0, t = p;
//     while (n >= p) {
//         res += n / p;
//         p *= t;
//     }
//     return res;
// }

// // 精炼简介，完美版本
// int get1(int n, int p) {
//     int res = 0;
//     while (n) {
//         res += n / p;
//         n /= p;
//     }
//     return res;
// }

// vector<int> mul(vector<int> a, int b) {
//     vector<int> C;
//     int t = 0;

//     for (int i = 0; i < a.size(); ++i) {
//         t += a[i] * b;
//         C.push_back(t % 10);
//         t /= 10;
//     }

//     while (t) {
//         C.push_back(t % 10);
//         t /= 10;
//     }

//     return C;
// }

// int main() {
//     int a, b;
//     cin >> a >> b;

//     get_primes(a);

//     for (int i = 0; i < cnt; ++i) {
//         int p = primes[i];
//         sum[i] = get(a, p) - get(b, p) - get(a - b, p);
//     }

//     vector<int> res;
//     res.push_back(1);

//     for (int i = 0; i < cnt; ++i)
//         for (int j = 0; j < sum[i]; ++j)
//             res = mul(res, primes[i]);

//     for (int i = res.size() - 1; i >= 0; --i) cout << res[i];
//     cout << endl;

//     system("pause");
//     return 0;
// }


// 2023/05/27 12:25:34
#include <bits/stdc++.h>
using namespace std;

const long long N = 100005, MOD = (long long)1e9 + 7;

long long fact[N], infact[N];

long long kuaisu(long long k, long long n, long long mod)
{
    long long res = 1;
    while (n)
    {
        if (n & 1) res = res * k % mod;
        k = k * k % mod;
        n /= 2;
    }
    return res;
}

long long C(long long a, long long b, long long mod)
{
    if (b > a)
        return 0;
    long long res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        res = res * j % mod;
        res = res * kuaisu(i, mod - 2, mod) % mod;
    }
    return res;
}

long long lucas(long long a, long long b, long long mod)
{
    if (a < mod && b < mod)
        return C(a, b, mod);
    else
        return C(a % mod, b % mod, mod) * lucas(a / mod, b / mod, mod) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        infact[i] = infact[i - 1] * kuaisu(i, MOD - 2, MOD) % MOD;
    }

    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b;
        cin >> a >> b;
        cout << fact[a] * infact[a - b] % MOD * infact[b] % MOD << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}