// 2024/04/06 15:22:09
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

bool cmp(vector<int> const& x, vector<int> const& y)
{
	return x.size() > y.size();
}

vector<int> ans;
int n;
int m;
void dfs(int now, vector<int> const& a, vector<vector<int>> const& G, vector<int>& vis)
{
	if (now == n - 1)
	{
		for (int i = 0; i < m; i++)
		{
			if (i != 0)
				cout << ' ';
			cout << ans[i] + 1;
		}
		exit(0);
	}

	for (int i = 0; i < m; i++)
	{
		if (vis[i])
			continue;
		auto const& vec = G[i];
		bool flag = 1;
		for (int j = 0; j < vec.size(); j++)
		{
			if (a[now + j] != vec[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			vis[i] = 1;
			ans.emplace_back(i);
			dfs(now + vec.size() - 1, a, G, vis);
            ans.pop_back();
			vis[i] = 0;
        }
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> m;
	vector<vector<int>> G(m);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		G[i].reserve(k);
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			G[i].emplace_back(x);
		}
	}

	// sort(G.begin(), G.end(), cmp);

	vector<int> vis(n, 0);

	dfs(0, a, G, vis);

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}