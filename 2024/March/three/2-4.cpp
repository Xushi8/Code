// // 2024/03/27 15:39:52
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// #include <numeric>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// constexpr int N = 1000005;

// double va[N], vb[N];

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n, m;
// 	cin >> n >> m;
// 	vector<vector<pair<bool, int>>> a(m);
// 	for (int i = 0; i < n; i++)
// 	{
// 		int k;
// 		cin >> k;
// 		for (int j = 0; j < k; j++)
// 		{
// 			char ch;
// 			cin >> ch;
// 			int tot = 0;
// 			if (ch == '-')
// 			{
// 				while ((ch = cin.get()) != ' ' && ch != '\n')
// 				{
// 					tot = tot * 10 + ch - '0';
// 				}
// 				a[i].emplace_back(0, tot);
// 			}
// 			else
// 			{
// 				tot = ch - '0';
// 				while ((ch = cin.get()) != ' ' && ch != '\n')
// 				{
// 					tot = tot * 10 + ch - '0';
// 				}
// 				a[i].emplace_back(1, tot);
// 			}
// 		}
// 	}

// 	pair<char, int> u, v;
// 	char ch;
// 	cin >> ch;
// 	int tot = 0;
// 	if (ch == '-')
// 	{
// 		while ((ch = cin.get()) != ' ' && ch != '\n')
// 		{
// 			tot = tot * 10 + ch - '0';
// 		}
// 		u = {0, tot};
// 	}
// 	else
// 	{
// 		tot = ch - '0';
// 		while ((ch = cin.get()) != ' ' && ch != '\n')
// 		{
// 			tot = tot * 10 + ch - '0';
// 		}
// 		u = {1, tot};
// 	}

// 	cin >> ch;
// 	tot = 0;
// 	if (ch == '-')
// 	{
// 		while ((ch = cin.get()) != ' ' && ch != '\n')
// 		{
// 			tot = tot * 10 + ch - '0';
// 		}
// 		v = {0, tot};
// 	}
// 	else
// 	{
// 		tot = ch - '0';
// 		while ((ch = cin.get()) != ' ' && ch != '\n')
// 		{
// 			tot = tot * 10 + ch - '0';
// 		}
// 		v = {1, tot};
// 	}

// 	for (int i = 0; i < m; i++)
// 	{
// 		bool f0 = 0, f1 = 0;
// 		for (int j = 0; j < a[i].size(); j++)
// 		{
// 			auto [sign, val] = a[i][j];
// 			if (val == u.second)
// 				f0 = 1;
// 			if (val == v.second)
// 				f1 = 1;
// 		}
// 		if (f0)
// 		{
// 			for (auto [sign, val] : a[i])
// 			{
// 				if (sign == !u.first)
// 				{
// 					va[val] += 1.0 / a[i].size();
// 				}
// 			}
// 		}
// 		if (f1)
// 		{
// 			for (auto [sign, val] : a[i])
// 			{
// 				if (sign == !v.first)
// 				{
// 					vb[val] += 1.0 / a[i].size();
// 				}
// 			}
// 		}
// 	}

// 	set<pair<double, int>, greater<>> st;

// 	for (int i = 0; i < N; i++)
// 	{
// 		if (va[i] != 0.0)
// 		{
// 			st.emplace(va[i], i);
// 		}
// 	}

// 	cout << u.second << ' ' << v.second << '\n';

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/03/29 08:42:29
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<bool, int>>> G(m);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			string s;
			cin >> s;
			bool f = s.front() != '-';
			if (f)
				G[i].emplace_back(f, stoi(s) + 1);
			else
				G[i].emplace_back(f, -(stoi(s) - 1));
		}

		sort(G[i].begin(), G[i].end());
	}

	string s;
	cin >> s;
	bool flag = s.front() != '-';
	pair<bool, int> u, v;
	if (flag)
		u = {flag, stoi(s) + 1};
	else
		u = {flag, -(stoi(s) - 1)};
	cin >> s;
	flag = s.front() != '-';
	if (flag)
		v = {flag, stoi(s) + 1};
	else
		v = {flag, -(stoi(s) - 1)};

	vector<double> va(n + 1), vb(n + 1);

	for (int i = 0; i < m; i++)
	{
		auto it1 = lower_bound(G[i].begin(), G[i].end(), u);
		auto it2 = lower_bound(G[i].begin(), G[i].end(), v);
		if (*it1 == u)
		{
			for (auto [f, val] : G[i])
			{
				if (f == !u.first)
				{
					va[val] += 1.0 / G[i].size();
				}
			}
		}
		if (*it2 == v)
		{
			for (auto [f, val] : G[i])
			{
				if (f == !v.first)
				{
					vb[val] += 1.0 / G[i].size();
				}
			}
		}
	}

	double max1 = *max_element(va.begin(), va.end());
	double max2 = *max_element(vb.begin(), vb.end());
	double eps = 1e-6;
	if (abs(va[v.second] - max1) < eps && abs(vb[u.second] - max2) < eps)
	{
		if (!u.first)
			cout << '-';
		cout << u.second - 1 << ' ';
		if (!v.first)
			cout << '-';
		cout << v.second - 1 << '\n';
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (abs(va[i] - max1) < eps)
			{
				if (!u.first)
					cout << '-';
				cout << u.second - 1 << ' ';
				if (u.first)
					cout << '-';
				cout << i - 1 << '\n';
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (abs(vb[i] - max2) < eps)
			{
				if (!v.first)
					cout << '-';
				cout << v.second - 1 << ' ';
				if (v.first)
					cout << '-';
				cout << i - 1 << '\n';
			}
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}