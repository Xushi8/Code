// 2024/08/05 16:17:08
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
    int m_x;
    Z(int x = 0) :
        m_x(norm(x)) {}
    int val() const
    {
        return m_x;
    }
    Z operator-() const
    {
        return Z(norm(P - m_x));
    }
    Z inv() const
    {
        assert(m_x != 0);
        return qpow(*this, P - 2);
    }
    Z& operator*=(const Z& rhs)
    {
        m_x = int64_t(m_x) * rhs.m_x % P;
        return *this;
    }
    Z& operator+=(const Z& rhs)
    {
        m_x = norm(m_x + rhs.m_x);
        return *this;
    }
    Z& operator-=(const Z& rhs)
    {
        m_x = norm(m_x - rhs.m_x);
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

    friend bool operator==(Z const& lhs, Z const& rhs)
    {
        return lhs.val() == rhs.val();
    }

    friend bool operator<(Z const& lhs, Z const& rhs)
    {
        return lhs.val() < rhs.val();
    }

    friend bool operator>(Z const& lhs, Z const& rhs)
    {
        return lhs.val() > rhs.val();
    }

    friend bool operator<=(Z const& lhs, Z const& rhs)
    {
        return lhs.val() <= rhs.val();
    }

    friend bool operator>=(Z const& lhs, Z const& rhs)
    {
        return lhs.val() >= rhs.val();
    }

    friend ostream& operator<<(ostream& os, Z const& val)
    {
        os << val.val();
        return os;
    }

    friend istream& operator>>(istream& is, Z& val)
    {
        is >> val.m_x;
        return is;
    }

    friend Z abs(Z const& val)
    {
        return abs(val.m_x);
    }
};

struct Comb
{
    int m_n;
    std::vector<Z> m_fac;
    std::vector<Z> m_invfac;
    std::vector<Z> m_inv;

    Comb() :
        m_n{0}, m_fac{1}, m_invfac{1}, m_inv{0} {}
    Comb(int n) :
        Comb()
    {
        init(n);
    }

    void init(int new_n)
    {
        if (new_n <= m_n) return;
        m_fac.resize(new_n + 1);
        m_invfac.resize(new_n + 1);
        m_inv.resize(new_n + 1);

        for (int i = m_n + 1; i <= new_n; i++)
        {
            m_fac[i] = m_fac[i - 1] * i;
        }
        m_invfac[new_n] = m_fac[new_n].inv();
        for (int i = new_n; i > m_n; i--)
        {
            m_invfac[i - 1] = m_invfac[i] * i;
            m_inv[i] = m_invfac[i] * m_fac[i - 1];
        }
        m_n = new_n;
    }

    Z fac(int m)
    {
        if (m > m_n) init(2 * m);
        return m_fac[m];
    }
    Z invfac(int m)
    {
        if (m > m_n) init(2 * m);
        return m_invfac[m];
    }
    Z inv(int m)
    {
        if (m > m_n) init(2 * m);
        return m_inv[m];
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto func = [&](int x, int y) -> Z
    {
        if (x > y)
            swap(x, y);
        if (x == 0)
            return 1;
        else
            return comb.binom(x + y, x);
    };

    Z ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += abs(a[i] - b[j]) * func(i, j) * func(n - i - 1, n - j - 1);
        }
    }

    cout << ans << '\n';
}