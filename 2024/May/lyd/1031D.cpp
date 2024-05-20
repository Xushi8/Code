// 2024/05/16 22:54:08
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

int par[N];

void init(int n)
{
	iota(par, par + n, 0);
}

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	par[x] = y;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	init(n * 3);
	int ans = 0;
	while (k--)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (!(1 <= x && x <= n && 1 <= y && y <= n))
		{
			ans++;
			continue;
		}
		if (op == 1)
		{
			if (same(x, y + n) || same(x + n, y + 2 * n) || same(x + 2 * n, y) || same(y, x + n) || same(y + n, x + 2 * n) || same(y + 2 * n, x))
			{
				ans++;
				continue;
			}
			unite(x, y);
			unite(x + n, y + n);
			unite(x + 2 * n, y + 2 * n);
		}
		else
		{
			if (same(x, y) || same(x + n, y + n) || same(x + 2 * n, y + 2 * n) || same(y, x + n) || same(y + n, x + 2 * n) || same(y + 2 * n, x))
			{
				ans++;
				continue;
			}
			unite(x, y + n);
			unite(x + n, y + 2 * n);
			unite(x + 2 * n, y);
		}
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}