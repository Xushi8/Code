// 2024/03/27 13:51:54
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

// int par[N];

// void init(int n)
// {
// 	iota(par, par + n, 0);
// }

// int find(int x)
// {
// 	if (x == par[x])
// 		return x;
// 	else
// 		return par[x] = find(par[x]);
// }

// void unite(int x, int y)
// {
// 	x = find(x);
// 	y = find(y);
// 	if (x != y)
// 		par[x] = y;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	for (int i = 0; i < m; i++)
	{
        int u, v;
		cin >> u >> v;
        u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	int q;
	cin >> q;
	while (q--)
	{
		// init(n);
		int L;
		cin >> L;
		set<int> erased;
		for (int i = 0; i < L; i++)
		{
			int x;
			cin >> x;
			x--;
			erased.emplace(x);
		}

		bool flag = 0;

		for (int i = 0; i < n; i++)
		{
			if (erased.count(i) == 1)
				continue;
			for (int v : G[i])
			{
				if (erased.count(v) == 1)
				{
					continue;
				}

				flag = 1;
				break;

				// unite(v, i);
            }
		}

		cout << (flag ? "NO" : "YES") << '\n';

    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}