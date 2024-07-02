#include <cassert>
#include <vector>
#include <cstdint>

constexpr int P = 1000000007;
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