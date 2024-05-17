// 2024/05/16 21:35:25
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int par[N], dis[N], siz[N];

int find(int x)
{
	if (par[x] == x)
		return x;
	int t1 = par[x];
	int t2 = find(par[x]);
	dis[x] += dis[t1];
	return par[x] = t2;
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	par[y] = x;
	dis[y] = siz[x];
	siz[x] += siz[y];
	siz[y] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	iota(par, par + N, 0);
	fill(siz, siz + n, 1);

	for (int i = 0; i < n; i++)
	{
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'M')
		{
			unite(x, y);
		}
		else
		{
			if (find(x) == find(y))
				cout << abs(dis[x] - dis[y]) - 1 << '\n';
			else
				cout << "-1\n";
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}