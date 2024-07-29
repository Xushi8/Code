/**

// 2024/07/29 13:23:43
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

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

void solve()
{
	int n, m;
	cin >> n >> m;

	// vector<vector<Z>> dp(n + 5, vector<Z>(2 * m + 5));
	vector<vector<i64>> dp(n + 5, vector<i64>(2 * m + 5));

	fill(dp[0].begin(), dp[0].end(), 1);
	for (int j = 0; j < 2 * m + 5 - 1; j++)
	{
		dp[0][j + 1] += dp[0][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = -m; j <= m; j++)
		{
			if (n != 1 && j < 0)
			{
				j = 0;
			}
			int l = j - m, r = j + m;
			if (j < 0)
				l = 0;
			r = min(r, m);
			l += m + 1;
			r += m + 1;
			int k = j + m + 1;
			dp[i][k] = dp[i - 1][r] - dp[i - 1][l - 1];
		}
		for (int j = 0; j < 2 * m + 5 - 1; j++)
		{
			dp[i][j + 1] += dp[i][j];
		}
	}

	// cout << dp[n].back().val() << '\n';
	// cout << dp[n].back() << '\n';

	int l = m + 1;
	int r = m + 1 + m;
	cout << dp[n][r] - dp[n][l - 1] << '\n';
}

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3 + 10;
constexpr int mod = 998244353;
int DP[N][N];
int n, m;
signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= 2 * m + 1; i++)
	{
		DP[1][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * m + 1; j++)
		{
			if (j <= m)
			{
				for (int k = m + 1; k < m + 1 + j; k++)
				{
					DP[i + 1][k] += DP[i][j];
					DP[i + 1][k] %= mod;
				}
			}
			else
			{
				for (int k = m + 1 - (j - m - 1); k < 2 * m + 2; k++)
				{
					DP[i + 1][k] += DP[i][j];
					DP[i + 1][k] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 2 * m + 1; i++)
	{
		ans += DP[n][i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
