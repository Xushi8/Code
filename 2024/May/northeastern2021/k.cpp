// // // 2024/05/17 16:58:49
// // #include <iostream>
// // #include <algorithm>
// // #include <cstring>
// // #include <cstdint>
// // #include <vector>
// // #include <string>
// // #include <set>
// // #include <map>
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <queue>
// // #include <functional>
// // #include <iomanip>
// // #include <cmath>
// // #include <stack>
// // #include <array>
// // #include <fstream>
// // #include <bitset>
// // #include <numeric>
// // using namespace std;

// // using i64 = int64_t;
// // using pii = pair<int, int>;
// // using pll = pair<i64, i64>;
// // constexpr int N = 1000005;

// // int par[N];
// // int siz[N];
// // void init(int n)
// // {
// // 	iota(par, par + n, 0);
// // 	fill(siz, siz + n, 1);
// // }

// // int find(int x)
// // {
// // 	if (x == par[x])
// // 		return x;
// // 	else
// // 		return par[x] = find(par[x]);
// // }

// // int unite(int x, int y)
// // {
// // 	x = find(x);
// // 	y = find(y);
// // 	if (x == y)
// // 		return 0;

// // 	int sum = siz[x] * siz[y];
// // 	par[x] = y;
// // 	siz[y] += siz[x];
// // 	return sum;
// // }

// // void solve()
// // {
// // 	int n, m, q;
// // 	cin >> n >> m >> q;
// // 	init(n);
// // 	vector<array<int, 3>> a(m);
// // 	for (int i = 0; i < m; i++)
// // 	{
// // 		int u, v, w;
// // 		cin >> u >> v >> w;
// // 		u--;
// // 		v--;
// //         a[i] = {u, v, w};
// // 	}
// // 	sort(a.begin(), a.end(), [](auto const& x, auto const& y)
// // 		{
// // 			return x.back() < y.back();
// // 		});

// // 	vector<pii> query(q);
// // 	for (int i = 0; i < q; i++)
// // 	{
// // 		int x;
// // 		cin >> x;
// // 		query[i] = {x, i};
// // 	}
// // 	sort(query.begin(), query.end(), greater<>());

// // 	int ans = 0;
// // 	for (int i = 0; i < q; i++)
// // 	{
// // 		while (!a.empty() && a.back().back() >= query[i].first)
// // 		{
// // 			ans += unite(a.back()[0], a.back()[1]);
// // 			a.pop_back();
// // 		}
// // 		query[i].first = ans;
// // 	}

// // 	sort(query.begin(), query.end(), [](auto const& x, auto const& y)
// // 		{
// // 			return x.second < y.second;
// // 		});
// // 	for (auto const& [x, y] : query)
// // 	{
// // 		cout << x << ' ' << '\n';
// // 	}
// // }

// // int main()
// // {
// // 	ios::sync_with_stdio(false);
// // 	cin.tie(0);

// // 	int tt;
// // 	cin >> tt;
// // 	while (tt--)
// // 	{
// // 		solve();
// // 	}

// // #ifdef LOCAL
// // 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// // #endif
// // 	return 0;
// // }

// // 2024/05/17 17:39:01
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

// using i64 = int64_t;
// using pii = pair<int, int>;
// using pll = pair<i64, i64>;
// constexpr int N = 1000005;

// int par[N];
// i64 siz[N];
// void init(int n)
// {
// 	iota(par, par + n, 0);
// 	fill(siz, siz + n, 1);
// }

// int find(int x)
// {
// 	if (par[x] == x)
// 		return x;
// 	else
// 		return par[x] = find(par[x]);
// }

// i64 unite(int x, int y)
// {
// 	x = find(x);
// 	y = find(y);
// 	if (x == y)
// 		return 0;

// 	par[x] = y;
// 	i64 res = siz[x] * siz[y];
// 	siz[y] += siz[x];
// 	return res;
// }

// void solve()
// {
// 	int n, m, q;
// 	cin >> n >> m >> q;
// 	init(n);
// 	vector<array<int, 3>> a(n);
// 	for (int i = 0; i < m; i++)
// 	{
// 		int u, v, w;
// 		cin >> u >> v >> w;
// 		u--, v--;
// 		a[i] = {u, v, w};
// 	}

// 	sort(a.begin(), a.end(), [](auto const& x, auto const& y)
// 		{
// 			return x.back() > y.back();
// 		});

// 	vector<pair<i64, int>> query(q);
// 	for (int i = 0; i < q; i++)
// 	{
// 		int x;
// 		cin >> x;
// 		query[i] = {x, i};
// 	}

// 	sort(query.begin(), query.end(), greater<>());

// 	int i = 0;
// 	i64 ans = 0;
// 	for (auto& [x, id] : query)
// 	{
// 		while (i < m && a[i][2] >= x)
// 		{
// 			ans += unite(a[i][0], a[i][1]);
// 			i++;
// 		}

// 		x = ans;
// 	}

// 	sort(query.begin(), query.end(), [](auto const& x, auto const& y)
// 		{
// 			return x.second < y.second;
// 		});

// 	for (auto const& [x, y] : query)
// 	{
// 		cout << x << '\n';
// 	}
// }

// signed main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int tt;
// 	cin >> tt;
// 	while (tt--)
// 	{
// 		solve();
// 	}

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/05/17 18:26:54
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int par[N];
i64 siz[N];
void init(int n)
{
	iota(par, par + n, 0);
	fill(siz, siz + n, 1);
}

int find(int x)
{
	if (par[x] == x)
		return par[x];
	else
		return par[x] = find(par[x]);
}

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	init(n + 1);
	vector<array<int, 3>> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[i] = {u, v, w};
	}

	vector<pair<i64, int>> query(q + 1);
	for (int i = 1; i <= q; i++)
	{
		i64 x;
		cin >> x;
		query[i] = {x, i};
	}

	sort(a.begin() + 1, a.end(), [&](auto const& x, auto const& y)
		{
			return x.back() > y.back();
		});
	sort(query.begin() + 1, query.end(), [&](auto const& x, auto const& y)
		{
			return x.first > y.first;
		});

	int cnt = 1;
	i64 sum = 0;
	for (int i = 1; i <= q; i++)
	{
		while (cnt <= m && a[cnt].back() >= query[i].first)
		{
			int t = find(a[cnt][0]);
			int z = find(a[cnt][1]);
			if (t != z)
			{
				par[t] = z;
				sum += siz[t] * siz[z];
				siz[z] += siz[t];
			}
			cnt++;
		}
		query[i].first = sum;
	}

	sort(query.begin(), query.end(), [&](auto const& x, auto const& y)
		{
			return x.second < y.second;
		});
	for (int i = 1; i <= q; i++)
	{
		cout << query[i].first << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}