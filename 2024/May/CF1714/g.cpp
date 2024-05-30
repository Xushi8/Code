// 2024/05/30 20:20:19
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void dfs(int u, i64 now_sum, vector<i64>& prefix, map<int, int>& ans, vector<vector<array<int, 3>>> const& G)
{
	if (u != 0)
	{
		auto it = upper_bound(prefix.begin(), prefix.end(), now_sum);
		ans[u] = it - prefix.begin() - 1;
	}

	for (auto [v, w0, w1] : G[u])
	{
		prefix.emplace_back(w1 + prefix.back());
		dfs(v, now_sum + w0, prefix, ans, G);
		prefix.pop_back();
	}
}

// void solve()
// {
// 	int n;
// 	cin >> n;
// 	vector<vector<array<int, 3>>> G(n);
// 	for (int i = 1; i < n; i++)
// 	{
// 		int par, w0, w1;
// 		cin >> par >> w0 >> w1;
// 		par--;
// 		G[par].push_back({i, w0, w1});
// 	}

// 	vector<i64> prefix;
// 	prefix.emplace_back(0);
// 	map<int, int> ans;
// 	dfs(0, 0, prefix, ans, G);
// 	for (auto [x, y] : ans)
// 	{
// 		y = max(y, 0);
// 		cout << y << ' ';
// 	}
// 	cout << '\n';
// }

void solve()
{
	int n;
	cin >> n;
	vector<vector<array<int, 3>>> G(n);
	for (int i = 1; i < n; i++)
	{
		int par, w0, w1;
		cin >> par >> w0 >> w1;
		par--;
		G[par].push_back({i, w0, w1});
	}

	vector<i64> prefix{0};
	prefix.reserve(n + 1);
	vector<int> ans(n);

	const function<void(int u, i64 now_sum)> dfs = [&](int u, i64 now_sum)
	{
		// if (u != 0)
		{
			auto it = upper_bound(prefix.begin(), prefix.end(), now_sum);
			ans[u] = it - prefix.begin() - 1;
		}

		for (auto [v, w0, w1] : G[u])
		{
			prefix.emplace_back(prefix.back() + w1);
			dfs(v, now_sum + w0);
			prefix.pop_back();
		}
	};

	// auto dfs = [&](int u, i64 now_sum)
	// {
	// 	auto it = upper_bound(prefix.begin(), prefix.end(), now_sum);
	// 	ans[u] = it - prefix.begin() - 1;

	// 	for (auto [v, w0, w1] : G[u])
	// 	{
	// 		prefix.emplace_back(prefix.back() + w1);
	// 		dfs(), v, now_sum + w0);
	// 		prefix.pop_back();
	// 	}
	// }

	dfs(0, 0);

	for (int i = 1; i < n; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
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