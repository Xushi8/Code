// // 2024/04/02 09:37:41
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

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n, m, q, u, v, t;
// 	cin >> n >> m >> q >> u >> v >> t;
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

// 	int tot = 1;
// 	for (int i = 0; i < m; i++)
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
// 			if (a.front().first + (i - a.front().second) * q > b.front().first + (i - b.front().second) &&
// 				a.front().first + (i - a.front().second) * q > c.front().first + (i - c.front().second))
// 			{
// 				auto p = a.front();
// 				a.pop();
// 				x = p.first;
// 				id = p.second;
// 			}
// 			else if (b.front().first + (i - b.front().second) * q > c.front().first + (i - c.front().second) &&
// 					 b.front().first + (i - b.front().second) * q > c.front().first + (i - c.front().second))
// 			{
// 				auto p = b.front();
// 				b.pop();
// 				x = p.first;
// 				id = p.second;
// 			}
// 			else
// 			{
// 				auto p = c.front();
// 				c.pop();
// 				x = p.first;
// 				id = p.second;
// 			}
// 		}
// 		int y, z;
// 		y = x * p;
// 		z = x - y;
// 		b.emplace(y - q, id + 1);
// 		c.emplace(z - q, id + 1);

// 		if (i == tot * t - 1)
// 		{
// 			tot++;
// 			cout << x + i * q << ' ';
// 		}
// 	}
// 	cout << endl;

// 	vector<int> ans;
// 	while (!a.empty())
// 	{
// 		auto [x, id] = a.front();
// 		a.pop();

// 		ans.emplace_back(x + (m - id) * q);
// 	}
// 	while (!b.empty())
// 	{
// 		auto [x, id] = b.front();
// 		b.pop();

// 		ans.emplace_back(x + (m - id) * q);
// 	}
// 	while (!c.empty())
// 	{
// 		auto [x, id] = c.front();
// 		c.pop();

// 		ans.emplace_back(x + (m - id) * q);
// 	}

// 	sort(ans.begin(), ans.end(), greater<>());

// 	for (int i = 0; i < (n + m) / t; i += t)
// 	{
// 		cout << ans[i] << ' ';
// 	}
// 	cout << '\n';

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/04/02 10:15:08
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

	int n, m, q, u, v, t;
	cin >> n >> m >> q >> u >> v >> t;
	double p = 1.0 * u / v;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());

	queue<pii> a, b, c;

	for (auto x : arr)
	{
        a.emplace(x, m);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}