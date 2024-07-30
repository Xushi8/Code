// 2024/07/30 12:23:35
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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

#include <cassert>
#include <vector>
#include <cstdint>

constexpr int P = 998244353;
// assume -P <= x < 2P
int norm(int x)
{
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}
template <class T>
T qpow(T a, int b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
    {
        if (b % 2) res *= a;
    }
    return res;
}
struct Z
{
    int x;
    Z(int x = 0) :
        x(norm(x)) {}
    int val() const
    {
        return x;
    }
    Z operator-() const
    {
        return Z(norm(P - x));
    }
    Z inv() const
    {
        assert(x != 0);
        return qpow(*this, P - 2);
    }
    Z& operator*=(const Z& rhs)
    {
        x = int64_t(x) * rhs.x % P;
        return *this;
    }
    Z& operator+=(const Z& rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    Z& operator-=(const Z& rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    Z& operator/=(const Z& rhs)
    {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z& lhs, const Z& rhs)
    {
        Z ret = lhs;
        ret *= rhs;
        return ret;
    }
    friend Z operator+(const Z& lhs, const Z& rhs)
    {
        Z ret = lhs;
        ret += rhs;
        return ret;
    }
    friend Z operator-(const Z& lhs, const Z& rhs)
    {
        Z ret = lhs;
        ret -= rhs;
        return ret;
    }
    friend Z operator/(const Z& lhs, const Z& rhs)
    {
        Z ret = lhs;
        ret /= rhs;
        return ret;
    }
};

struct Comb
{
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() :
        n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) :
        Comb()
    {
        init(n);
    }

    void init(int m)
    {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++)
        {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--)
        {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m)
    {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m)
    {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m)
    {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m)
    {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }

    int ave = sum / n;
    int ave1;
    if (sum % n != 0)
    {
        ave1 = ave + 1;
    }
    else
    {
        ave1 = ave;
    }

    int cp = sum;
    int now_n = n;
    auto func = [&]()
    {
        sum = cp;
        now_n = n;
        for (int i = n - 1; i > 0; i--)
        {
            int tar = sum / now_n;
            if (a[i] > tar)
            {
                a[i] = tar;
            }
            sum -= a[i];
            now_n--;
        }
        a[0] = sum;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > 100)
            {
                int dec = a[i] - 99;
                a[i] -= dec;
                a[i + 1] += dec;
            }
            if (a[i] <= 0)
            {
                int asc = 1 - a[i];
                a[i] += asc;
                a[i + 1] -= asc;
            }
        }

        sum = cp;
        now_n = n;
        for (int i = 0; i < n - 1; i++)
        {
            int tar = (sum) / now_n;
            if (a[i] < tar)
            {
                a[i] = tar;
            }
            sum -= a[i];
            now_n--;
        }
        a[n - 1] = sum;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] > 100)
            {
                int dec = a[i] - 99;
                a[i] -= dec;
                a[i - 1] += dec;
            }
            if (a[i] < 0)
            {
                int asc = 1 - a[i];
                a[i] += asc;
                a[i - 1] -= asc;
            }
        }
    };

    auto func1 = [&]()
    {
        for (int i = 0; i < n - 1; i++)
        {
            while (a[i] < ave && a[i + 1] > ave1)
            {
                a[i]++;
                a[i + 1]--;
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] > 100)
            {
                int dec = a[i] - 99;
                a[i] -= dec;
                a[i - 1] += dec;
            }
            if (a[i] < 0)
            {
                int asc = 1 - a[i];
                a[i] += asc;
                a[i - 1] -= asc;
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            while (a[i] > ave1 && a[i - 1] > ave)
            {
                a[i]--;
                a[i - 1]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > 100)
            {
                int dec = a[i] - 99;
                a[i] -= dec;
                a[i + 1] += dec;
            }
            if (a[i] <= 0)
            {
                int asc = 1 - a[i];
                a[i] += asc;
                a[i + 1] -= asc;
            }
        }
    };

    func();
    func();

    func1();
    func1();

    func();

    Z mul = 1;
    for (int i = 0; i < n; i++)
    {
        mul *= a[i];
        cout << a[i] << ' ';
    }
    cout << mul.val() << '\n';
}