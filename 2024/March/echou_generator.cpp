#include <iostream>
#include <string>
#include <map>
using ll = long long;
using namespace std;

map<ll, string> mp = {
	{0, "(1-1)*4514"},
	{1, "11/(45-1)*4"},
	{2, "-11+4-5+14"},
	{3, "11*-4+51-4"},
	{4, "-11-4+5+14"},
	{5, "11-4*5+14"},
	{6, "1-14+5+14"},
	{7, "11-4+5-1-4"},
	{8, "11-4+5/1-4"},
	{9, "11-4+5+1-4"},
	{10, "-11/4+51/4"},
	{100, "1*(1+4)*5*1*4"},
	{114514, "114514"},
};

ll fast_pow(ll a, size_t n)
{
	ll b = 1;
	while (n)
	{
		if (n & 1)
			b *= a;
		a *= a;
		n >>= 1;
	}
	return b;
}

string get(ll x)
{
	auto it = mp.find(x);
	if (it != mp.end())
	{
		return it->second;
	}

	string res;
	ll tmp = x;
	size_t tot = 0;

	// >= 114514 使用指数缩减
	while (tmp >= 114514)
	{
		tmp /= 114514;
		tot++;
	}
	if (tot != 0)
	{
		res += "(114514)^" + to_string(tot);
		tmp = x - fast_pow(114514, tot);
		if (tmp == 0)
			return res;
		else
			res += "+";
	}

	// >= 100 使用100的乘法缩减
	tot = tmp / 100;
	if()
}

int main()
{
	return 0;
}