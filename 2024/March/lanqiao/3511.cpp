// 2024/04/12 11:21:47
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
bool flag;

void dfs(size_t deep, int now, vector<array<int ,3>> const& a, vector<int>& vis)
{
	if (flag)
		return;
	if (deep == a.size())
	{
		flag = 1;
		return;
	}

	for (size_t i = 0; i < a.size(); i++)
	{
		if (!vis[i])
		{
			auto [t, d, l] = a[i];
			if (now > t + d)
				return;
			// if (now < t)
			// 	continue;
			vis[i] = 1;
			dfs(deep + 1, max(now, t) + l, a, vis);
			vis[i] = 0;
        }
    }
}

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	for (auto& [x, y, z] : a)
	{
		cin >> x >> y >> z;
	}
	// sort(a.begin(), a.end());

	vector<int> vis(n, 0);
	flag = 0;
	dfs(0, 0, a, vis);
	cout << (flag ? "YES" : "NO") << '\n';
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