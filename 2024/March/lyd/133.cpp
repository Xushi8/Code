// // // 2024/04/02 09:37:41
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

// // using ll = long long;
// // using pii = pair<int, int>;
// // using pll = pair<ll, ll>;
// // constexpr int N = 1000005;

// // int main()
// // {
// // 	ios::sync_with_stdio(false);
// // 	cin.tie(0);

// // 	int n, m, adds, u, v, t;
// // 	cin >> n >> m >> adds >> u >> v >> t;
// // 	double p = 1.0 * u / v;

// // 	vector<int> arr(n);
// // 	for (int i = 0; i < n; i++)
// // 	{
// // 		cin >> arr[i];
// // 	}

// // 	sort(arr.begin(), arr.end(), greater<>());

// // 	queue<pii> a, b, c;
// // 	for (auto x : arr)
// // 	{
// // 		a.emplace(x, 0);
// // 	}

// // 	int tot = 1;
// // 	for (int i = 0; i < m; i++)
// // 	{
// // 		int x, id;
// // 		if (i == 0)
// // 		{
// // 			auto p = a.front();
// // 			a.pop();
// // 			x = p.first;
// // 			id = p.second;
// // 		}
// // 		else
// // 		{
// // 			if (a.front().first + (i - a.front().second) * adds > b.front().first + (i - b.front().second) &&
// // 				a.front().first + (i - a.front().second) * adds > c.front().first + (i - c.front().second))
// // 			{
// // 				auto p = a.front();
// // 				a.pop();
// // 				x = p.first;
// // 				id = p.second;
// // 			}
// // 			else if (b.front().first + (i - b.front().second) * adds > c.front().first + (i - c.front().second) &&
// // 					 b.front().first + (i - b.front().second) * adds > c.front().first + (i - c.front().second))
// // 			{
// // 				auto p = b.front();
// // 				b.pop();
// // 				x = p.first;
// // 				id = p.second;
// // 			}
// // 			else
// // 			{
// // 				auto p = c.front();
// // 				c.pop();
// // 				x = p.first;
// // 				id = p.second;
// // 			}
// // 		}
// // 		int y, z;
// // 		y = x * p;
// // 		z = x - y;
// // 		b.emplace(y - adds, id + 1);
// // 		c.emplace(z - adds, id + 1);

// // 		if (i == tot * t - 1)
// // 		{
// // 			tot++;
// // 			cout << x + i * adds << ' ';
// // 		}
// // 	}
// // 	cout << endl;

// // 	vector<int> ans;
// // 	while (!a.empty())
// // 	{
// // 		auto [x, id] = a.front();
// // 		a.pop();

// // 		ans.emplace_back(x + (m - id) * adds);
// // 	}
// // 	while (!b.empty())
// // 	{
// // 		auto [x, id] = b.front();
// // 		b.pop();

// // 		ans.emplace_back(x + (m - id) * adds);
// // 	}
// // 	while (!c.empty())
// // 	{
// // 		auto [x, id] = c.front();
// // 		c.pop();

// // 		ans.emplace_back(x + (m - id) * adds);
// // 	}

// // 	sort(ans.begin(), ans.end(), greater<>());

// // 	for (int i = 0; i < (n + m) / t; i += t)
// // 	{
// // 		cout << ans[i] << ' ';
// // 	}
// // 	cout << '\n';

// // #ifdef LOCAL
// // 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// // #endif
// // 	return 0;
// // }

// // 2024/04/02 10:15:08
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

// int32_t main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n, m, adds, u, v, t;
// 	cin >> n >> m >> adds >> u >> v >> t;
// 	double p = 1.0 * u / v;

// 	vector<int> arr(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> arr[i];
// 	}

// 	sort(arr.begin(), arr.end(), greater<>());

// 	queue<pii> a, b, c;

// 	for (auto x : arr)
// 	{
// 		a.emplace(x, 0);
// 	}

// 	for (int i = 1; i <= m; i++)
// 	{
// 		int x, id;
// 		if (i == 0)
// 		{
// 			auto p = a.front();
// 			a.pop();
// 			x = p.first;
// 			id = p.second;
// 		}
// 		else
// 		{
// 			int x1 = -1e9, id1 = 0;
// 			if (!a.empty())
// 			{
// 				auto p = a.front();
// 				x1 = p.first;
// 				id1 = p.second;
// 			}
// 			auto [x2, id2] = b.front();
// 			auto [x3, id3] = c.front();
// 			int v1 = x1 + adds * (i - id1);
// 			int v2 = x2 + adds * (i - id2);
// 			int v3 = x3 + adds * (i - id3);
// 			if (v1 >= v2 && v1 >= v3)
// 			{
// 				x = x1;
// 				id = id1;
// 				a.pop();
// 			}
// 			else if (v2 >= v1 && v2 >= v3)
// 			{
// 				x = x2;
// 				id = id2;
// 				b.pop();
// 			}
// 			else
// 			{
// 				x = x3;
// 				id = id3;
// 				c.pop();
// 			}
// 		}

// 		int val = x + adds * (i - id - 1);
// 		int y = val * p;
// 		int z = val - y;
// 		b.emplace(y, i + 1);
// 		c.emplace(z, i + 1);
// 		if (i % t == 0)
// 		{
// 			cout << val << ' ';
// 		}
// 	}
// 	cout << '\n';

// 	vector<int> ans;

// 	while (!a.empty())
// 	{
// 		auto [x, id] = a.front();
// 		a.pop();
// 		int val = x + adds * (m - id);
// 		ans.emplace_back(val);
// 	}
// 	while (!b.empty())
// 	{
// 		auto [x, id] = b.front();
// 		b.pop();
// 		int val = x + adds * (m - id);
// 		ans.emplace_back(val);
// 	}
// 	while (!c.empty())
// 	{
// 		auto [x, id] = c.front();
// 		c.pop();
// 		int val = x + adds * (m - id);
// 		ans.emplace_back(val);
// 	}

// 	sort(ans.begin(), ans.end(), greater<>());

// 	for (int i = 1; i <= (n + m); i++)
// 	{
// 		if (i % t == 0)
// 			cout << ans[i] << ' ';
// 	}
// 	cout << '\n';

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/04/02 14:46:00
#pragma GCC optimize(3)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, adds, u, v, t;
	cin >> n >> m >> adds >> u >> v >> t;
	double p = 1.0 * u / v;

	vector<int> arr(n);
	for (auto& x : arr)
		cin >> x;

	sort(arr.begin(), arr.end(), greater<>());
	queue<int> a, b, c;
	for (auto x : arr)
		a.emplace(x);

	auto get = [&]() -> int
	{
		int x, y, z;
		x = y = z = -2e9;
		if (!a.empty())
			x = a.front();
		if (!b.empty())
			y = b.front();
		if (!c.empty())
			z = c.front();
		int val = max({x, y, z});
		if (val == x)
			a.pop();
		else if (val == y)
			b.pop();
		else
			c.pop();
		return val;
	};

	for (int i = 1; i <= m; i++)
	{
		int val = get() + (i - 1) * adds;
		int x = val * p;
		int y = val - x;
		b.emplace(x - i * adds);
		c.emplace(y - i * adds);
		if (i % t == 0)
		{
			cout << val << ' ';
		}
	}
	cout << '\n';

	for (int i = 1; i <= (n + m); i++)
	{
		int val = get() + m * adds;
		if (i % t == 0)
		{
			cout << val << ' ';
		}
	}
	cout << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}