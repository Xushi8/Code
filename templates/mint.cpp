#include <cassert>
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
