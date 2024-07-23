// 2024/07/23 14:14:06
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

template <typename T, size_t NN>
array<T, NN> operator+(array<T, NN> l, array<T, NN> r)
{
	array<T, NN> res;
	for (size_t i = 0; i < NN; i++)
	{
		res[i] = l[i] + r[i];
	}
	return res;
}

template <typename T, size_t NN>
array<T, NN>& operator+=(array<T, NN>& l, array<T, NN> r)
{
	for (size_t i = 0; i < NN; i++)
	{
		l[i] += r[i];
	}
	return l;
}

template <typename T, size_t NN>
array<T, NN> operator-(array<T, NN> l, array<T, NN> r)
{
	array<T, NN> res;
	for (size_t i = 0; i < NN; i++)
	{
		res[i] = l[i] - r[i];
	}
	return res;
}

string func(size_t n, size_t a, string s)
{
	while (s.size() < a * 4)
	{
		s += s;
	}

	string xiaochang;

	vector<array<size_t, 2>> sum(s.size() + 1);
	for (size_t i = 0; i < s.size(); i++)
	{
		sum[i + 1] += sum[i];
		sum[i + 1][s[i] - '0']++;
	}

	for (size_t i = 1; i <= n; i++)
	{
		size_t be = i;
		size_t l = i;
		size_t r = i + 2 * a - 1;
		size_t ans = l - 1;
		while (l <= r)
		{
			size_t mid = (l + r) / 2;
			auto [c0, c1] = sum[mid] - sum[be - 1];
			if (c0 >= a || c1 >= a)
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		auto [c0, c1] = sum[ans] - sum[be - 1];
		if (c0 >= a)
			xiaochang += '0';
		else
			xiaochang += '1';
	}
	return xiaochang;
}

void solve()
{
	size_t n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	s = func(n, a, s);
	s = func(n, b, s);
	cout << s << '\n';
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