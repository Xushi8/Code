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

unordered_map<string, int> mp1;
unordered_map<int, string> mp2;
int be, ed;

int siz[N];

int func(string const& s)
{
	auto it = mp1.find(s);
	if (it != mp1.end())
		return it->second;
	mp1.emplace(s, mp1.size());
	mp2.emplace(mp1[s], s);
	return mp1[s];
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
	func(resource);
	func(destinatin);
	for (int i = 0; i < n; i++)
	{
		string x;
		int y;
		cin >> x >> y;
		siz[func(x)] = y;
	}

	vector<vector<int>> G(n);
	for (int i = 0; i < k; i++)
	{
		string u, v;
		int w;
		cin >> u >> v >> w;
		int nu = func(u);
		int nv = func(v);
		G[nu].emplace_back(nv);
		G[nv].emplace_back(nu);
	}

	dfs(func(resource), )
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}