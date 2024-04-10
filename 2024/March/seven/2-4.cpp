// // // 2024/04/10 14:45:05
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

// // void dfs(int u, int now, array<int, 2> val, vector<int>& vis, vector<int> const& sex, vector<int>& max_dis, vector<vector<pii>> const& G)
// // {
// // 	if (vis[u])
// // 		return;
// // 	vis[u] = 1;
// // 	if (val[sex[u]] == 0)
// // 	{
// // 		val[sex[u]] = now;
// // 	}
// // 	max_dis[u] = max(max_dis[u], now - val[!sex[u]]);
// // 	for (auto [v, w] : G[u])
// // 	{
// // 		dfs(v, now + w, val, vis, sex, max_dis, G);
// // 	}
// // }

// // int main()
// // {
// // 	ios::sync_with_stdio(false);
// // 	cin.tie(0);

// // 	int n;
// // 	cin >> n;
// // 	vector<int> sex(n + 1), max_dis(n + 1), vis(n + 1);
// // 	vector<vector<pii>> G(n + 1);
// // 	for (int i = 1; i <= n; i++)
// // 	{
// // 		char ch;
// // 		cin >> ch;
// // 		if (ch == 'F')
// // 			sex[i] = 0;
// // 		else
// // 			sex[i] = 1;
// // 		int k;
// // 		cin >> k;
// // 		G[i].reserve(k);
// // 		for (int j = 0; j < k; j++)
// // 		{
// // 			int v, w;
// // 			cin >> v >> ch >> w;
// // 			G[i].emplace_back(v, w);
// // 		}
// // 	}

// // 	for (int i = 1; i <= n; i++)
// // 	{
// // 		dfs(i, 0, {0, 0}, vis, sex, max_dis, G);
// // 	}

// // 	vector<pii> ans[2];
// // 	for (int i = 1; i <= n; i++)
// // 	{
// // 		ans[sex[i]].emplace_back(i, max_dis[i]);
// // 	}

// // 	vector<int> ans1;

// // 	for (int i = 0; i < 2; i++)
// // 	{
// // 		int minn = ans[i][0].second;
// // 		for (int j = 0; j < ans[i].size(); j++)
// // 		{
// // 			if (ans[i][j].second < minn && ans[i][j].second != 0)
// // 			{
// // 				minn = ans[i][j].second;
// //             }
// // 		}

// // 		for (auto [id, val] : ans[i])
// // 		{
// // 			if (val == minn)
// // 			{
// // 				ans1.emplace_back(id);
// //             }
// // 		}
// // 		for (int j = 0; j < ans1.size(); j++)
// // 		{
// // 			if (j != 0)
// // 				cout << ' ';
// // 			cout << ans1[j];
// // 		}
// // 		cout << '\n';
// // 		ans1.clear();
// //     }

// // #ifdef LOCAL
// // 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// // #endif
// // 	return 0;
// // }

// // 2024/04/10 15:10:31
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
// int sex[N], vis[N], val[N];
// constexpr int INF = 0x3f3f3f3f;

// void dfs(int u, int now, int& v0, int& v1, vector<vector<pii>> const& G)
// {
// 	if (vis[u])
// 		return;
// 	vis[u] = 1;
// 	int target = now;
// 	if (sex[u] == 0)
// 	{
// 		if (v0 == INF)
// 			v0 = now;
// 		else
// 			v0 = max(v0, now);
// 	}
// 	else
// 	{
// 		if (v1 == INF)
// 			v1 = now;
// 		else
// 			v1 = max(v1, now);
// 	}

// 	for (auto [v, w] : G[u])
// 	{
// 		dfs(v, now + w, v0, v1, G);
// 	}
// 	if (sex[u] == 0)
// 		val[u] = v1 - target;
// 	else
// 		val[u] = v0 - target;
// }

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n;
// 	cin >> n;
// 	vector<vector<pii>> G(n + 1);
// 	for (int i = 1; i <= n; i++)
// 	{
// 		char ch;
// 		cin >> ch;
// 		if (ch == 'F')
// 			sex[i] = 0;
// 		else
// 			sex[i] = 1;
// 		int k;
// 		cin >> k;
// 		for (int j = 0; j < k; j++)
// 		{
// 			int v, w;
// 			cin >> v >> ch >> w;
// 			G[v].emplace_back(i, w);
// 		}
// 	}

// 	for (int i = 1; i <= n; i++)
// 	{
// 		if (!vis[i])
// 		{
// 			int v0 = INF, v1 = INF;
// 			dfs(i, 0, v0, v1, G);
// 		}
// 	}

// 	vector<pii> all[2];
// 	for (int i = 1; i <= n; i++)
// 	{
// 		all[sex[i]].emplace_back(i, val[i]);
// 	}

// 	vector<int> ans;
// 	for (int i = 0; i < 2; i++)
// 	{
// 		ans.clear();
// 		int minn = all[i].front().second;
// 		for (int j = 0; j < all[i].size(); j++)
// 		{
// 			if (minn > all[i][j].second)
// 			{
// 				minn = all[i][j].second;
// 			}
// 		}

// 		for (int j = 0; j < all[i].size(); j++)
// 		{
// 			if (minn == all[i][j].second)
// 			{
// 				ans.emplace_back(all[i][j].first);
// 			}
// 		}

// 		for (int j = 0; j < ans.size(); j++)
// 		{
// 			if (j != 0)
// 				cout << ' ';
// 			cout << ans[j];
// 		}
// 		cout << '\n';
// 	}

// 	// for (int i = 1; i <= n; i++)
// 	// {
// 	// 	cout << val[i] << " \n"[i == n];
//     // }

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/04/10 17:05:36
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
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> dis(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++)
	{
		dis[i][i] = 0;
	}

	vector<int> sex(n);
	for (int i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		if (ch == 'F')
			sex[i] = 0;
		else
			sex[i] = 1;

		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int v, w;
			cin >> v >> ch >> w;
			v--;
			dis[i][v] = w;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

	vector<pii> max0, max1;
	for (int i = 0; i < n; i++)
	{
		int maxx = 0;
		for (int j = 0; j < n; j++)
		{
			if (sex[i] != sex[j])
			{
				maxx = max(maxx, dis[j][i]);
			}
		}
		if (sex[i] == 0)
			max0.emplace_back(maxx, i);
		else
			max1.emplace_back(maxx, i);
	}

	auto [min0, nouse0] = *min_element(max0.begin(), max0.end());
	auto [min1, nouse1] = *min_element(max1.begin(), max1.end());

	vector<int> ans0, ans1;
	for (size_t i = 0; i < max0.size(); i++)
	{
		if (min0 == max0[i].first)
			ans0.emplace_back(max0[i].second);
	}
	for (size_t i = 0; i < max1.size(); i++)
	{
		if (min1 == max1[i].first)
			ans1.emplace_back(max1[i].second);
	}

	for (size_t i = 0; i < ans0.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans0[i] + 1;
	}
	cout << '\n';
	for (size_t i = 0; i < ans1.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans1[i] + 1;
	}
	cout << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}