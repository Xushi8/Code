// 2024/06/23 23:16:43
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#include <cassert>
#include <vector>

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

constexpr int P = 998244353;
// assume -P <= x < 2P
i64 norm(i64 x)
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
	i64 x;
	Z(i64 x = 0) :
		x(norm(x)) {}
	i64 val() const
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
		x = x * rhs.x % P;
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
	vector<int> primes;
	vector<bool> isnp(n + 1);
	for (int i = 2; i <= n; i++)
	{
		if (!isnp[i])
			primes.emplace_back(i);
		for (int p : primes)
		{
			if (p * i >= n + 1)
				break;
			isnp[p * i] = 1;
			if (i % p == 0)
				break;
        }
	}

	Z the_lcm = 1;
	for (auto p : primes)
	{
		the_lcm *= qpow(Z(p), int(log(n) / log(p)));
	}

	Z ans = 0;
	for (int i = 1; i <= n; i++)
	{
		Z m1 = the_lcm * comb.inv(i);
		ans += m1 * (n - 2 * i + 1);
	}

	cout << ans.val() << '\n';
}

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