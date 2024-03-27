// 2024/03/27 15:39:52
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

double va[N], vb[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<bool, int>>> a(m);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			char ch;
			cin >> ch;
			int tot = 0;
			if (ch == '-')
			{
				while ((ch = cin.get()) != ' ' && ch != '\n')
				{
					tot = tot * 10 + ch - '0';
				}
				a[i].emplace_back(0, tot);
			}
			else
			{
				tot = ch - '0';
				while ((ch = cin.get()) != ' ' && ch != '\n')
				{
					tot = tot * 10 + ch - '0';
				}
				a[i].emplace_back(1, tot);
			}
		}
	}

	pair<char, int> u, v;
	char ch;
	cin >> ch;
	int tot = 0;
	if (ch == '-')
	{
		while ((ch = cin.get()) != ' ' && ch != '\n')
		{
			tot = tot * 10 + ch - '0';
		}
		u = {0, tot};
	}
	else
	{
		tot = ch - '0';
		while ((ch = cin.get()) != ' ' && ch != '\n')
		{
			tot = tot * 10 + ch - '0';
		}
		u = {1, tot};
	}

	cin >> ch;
	tot = 0;
	if (ch == '-')
	{
		while ((ch = cin.get()) != ' ' && ch != '\n')
		{
			tot = tot * 10 + ch - '0';
		}
		v = {0, tot};
	}
	else
	{
		tot = ch - '0';
		while ((ch = cin.get()) != ' ' && ch != '\n')
		{
			tot = tot * 10 + ch - '0';
		}
		v = {1, tot};
	}

	for (int i = 0; i < m; i++)
	{
		bool f0 = 0, f1 = 0;
		for (int j = 0; j < a[i].size(); j++)
		{
			auto [sign, val] = a[i][j];
			if (val == u.second)
				f0 = 1;
			if (val == v.second)
				f1 = 1;
		}
		if (f0)
		{
			for (auto [sign, val] : a[i])
			{
				if (sign == !u.first)
				{
					va[val] += 1.0 / a[i].size();
				}
			}
		}
		if (f1)
		{
			for (auto [sign, val] : a[i])
			{
				if (sign == !v.first)
				{
					vb[val] += 1.0 / a[i].size();
				}
			}
		}
	}

	set<pair<double, int>, greater<>> st;

	for (int i = 0; i < N; i++)
	{
		if (va[i] != 0.0)
		{
			st.emplace(va[i], i);
		}
	}

	cout << u.second << ' ' << v.second << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}