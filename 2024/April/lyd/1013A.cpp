// 2024/04/22 14:29:41
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
constexpr int N = 30004;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	vector<int> in(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].emplace_back(v);
		in[v]++;
	}

	queue<int> que;
	for (int i = 0; i < n; i++)
	{
		if (in[i] == 0)
		{
			que.emplace(i);
		}
	}

	vector<int> seq;
	seq.reserve(n);
	while (!que.empty())
	{
		auto u = que.front();
		que.pop();
		seq.emplace_back(u);
		for (int v : G[u])
		{
			if (--in[v] == 0)
			{
				que.emplace(v);
			}
		}
	}

	reverse(seq.begin(), seq.end());
	vector<bitset<N>> cnt(n);
	for (auto u : seq)
	{
		cnt[u][u] = 1;
		for (int v : G[u])
		{
			cnt[u] |= cnt[v];
        }
	}

	for (auto const& t : cnt)
	{
		cout << t.count() << '\n';
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}