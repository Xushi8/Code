// 2024/03/20 19:07:48
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
constexpr int N = 205;
map<string, int> mp1;
map<int, string> mp2;

int func(string const& s)
{
	auto it = mp1.find(s);
	if (it != mp1.end())
		return it->second;
	mp1.emplace(s, mp1.size());
	mp2.emplace(mp1[s], s);
	return mp1[s];
}
int be, ed;

int siz[N];
bool vis[N];
vector<int> now_vis;

constexpr int INF = 0x3f3f3f3f;
int ans_dis = INF, ans_siz = INF;
int ans_num;
vector<int> ans_vis;

void dfs(int u, int now_dis, int now_siz, vector<vector<pii>> const& G)
{
	if (vis[u])
		return;
	vis[u] = 1;
	now_vis.emplace_back(u);
	now_siz += siz[u];
	if (u == ed)
	{
		if (now_dis < ans_dis)
		{
			ans_num = 1;
			ans_dis = now_dis;
			ans_siz = now_siz;
			ans_vis = now_vis;
		}
		else if (now_dis == ans_dis)
		{
			ans_num++;
			if (now_vis.size() > ans_vis.size() || (now_vis.size() == ans_vis.size() && now_siz > ans_siz))
			{
				ans_dis = now_dis;
				ans_siz = now_siz;
				ans_vis = now_vis;
			}
		}
		now_vis.pop_back();
		vis[u] = 0;
		return;
	}

	for (auto [v, w] : G[u])
	{
		dfs(v, now_dis + w, now_siz, G);
	}
	now_vis.pop_back();
	vis[u] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string resource, destinatin;
	cin >> resource >> destinatin;
	// mp1.emplace(resource, mp1.size());
	// mp2.emplace(mp1[resource], resource);
	// mp1.emplace(destinatin, mp1.size());
	// mp2.emplace(mp1[destinatin], destinatin);
	be = func(resource);
	ed = func(destinatin);
	for (int i = 0; i < n - 1; i++)
	{
		string x;
		int y;
		cin >> x >> y;
		siz[func(x)] = y;
	}

	vector<vector<pii>> G(n + 1);
	for (int i = 0; i < k; i++)
	{
		string u, v;
		int w;
		cin >> u >> v >> w;
		int nu = func(u);
		int nv = func(v);
		G[nu].emplace_back(nv, w);
		G[nv].emplace_back(nu, w);
	}

	dfs(be, 0, 0, G);

	for (size_t i = 0; i < ans_vis.size(); i++)
	{
		if (i != 0)
			cout << "->";
		cout << mp2[ans_vis[i]];
	}
	cout << '\n';
	cout << ans_num << ' ' << ans_dis << ' ' << ans_siz << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}