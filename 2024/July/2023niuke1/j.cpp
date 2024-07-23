// 2024/07/22 13:05:34
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

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

	friend istream& operator>>(istream& is, Z& val)
	{
		int tmp;
		is >> tmp;
		val.x = tmp;
		return is;
	}

	friend ostream& operator<<(ostream& os, Z const& val)
	{
		return os << val.val();
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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n, m;
	cin >> n >> m;

	// Z q = 1 * Z(2).inv();
	double q = 0.5;

	// cout << qpow(q, m) * (2 * (1 - qpow(q, m))) << '\n';

	// cout << ((1 + 2 * qpow(Z(4).inv(), m)) * Z(3).inv()) << '\n';

	// cout << q - 2 * qpow(q, m) + 2 * qpow(2, 2 * m) << '\n';

	// cout << 1 - q - qpow(q, 3) - qpow(q, 4) - qpow(q, 5) - qpow(q, 6) << endl;

	// cout << (Z(1) - 4 * qpow(q, m)  * (1 - qpow(q, m))) * Z(2).inv() << endl;

	cout << qpow(3 * Z(4).inv(), 3) * qpow(7 * Z(8).inv(), 8) * qpow(15 * Z(16).inv(), 16) * qpow(31 * Z(32).inv(), 32) << endl;
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