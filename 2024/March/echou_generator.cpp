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
	{13113456196, "114514*114514"},
	{1501674322828744, "114514*114514*114514"},
};

string get(ll x);
ll func(ll x, ll div, string& res);

ll func(ll x, ll div, string& res)
{
	ll tot = x / div;
	if (tot != 0)
	{
		if (!(res.empty() || res.back() == '+'))
			res += '+';
		res += "((" + get(div) + ')' + "*(" + get(tot) + "))";
		x %= div;
	}
	return x;
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
	tmp = func(tmp, 1501674322828744, res);
	if (tmp == 0)
		return mp[x] = res;

	tmp = func(tmp, 13113456196, res);
	if (tmp == 0)
		return mp[x] = res;

	tmp = func(tmp, 114514, res);
	if (tmp == 0)
		return mp[x] = res;

	tmp = func(tmp, 100, res);
	if (tmp == 0)
		return mp[x] = res;

	tmp = func(tmp, 10, res);
	if (tmp == 0)
		return mp[x] = res;

	return mp[x] = res + '+' + '(' + get(tmp) + ')';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 1000000000000000000; i < 1000000000000000000 + 1000000; i++)
	{
		cout << i << " = " << get(i) << '\n';
	}

	return 0;
}