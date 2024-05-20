// 2024/05/16 20:59:16
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

map<int, int> par;

void init(int n)
{
    par.clear();
}

int find(int x)
{
	auto it = par.find(x);
	if (it == par.end() || it->second == x)
		return par[x] = x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		par[x] = y;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

bool solve()
{
	int n;
	cin >> n;
	init(n);
	vector<pii> no_same;
	for (int i = 0; i < n; i++)
	{
		int x, y, op;
		cin >> x >> y >> op;
		if (op == 0)
		{
			// if (same(x, y) || same(x + n, y + n))
			// 	return false;
			// unite(x, y + n);
			// unite(y, x + n);
			no_same.emplace_back(x, y);
		}
		else
		{
			unite(x, y);
        }
	}

	for (auto const& [x, y] : no_same)
	{
		if (same(x, y))
			return false;
	}

	return true;

	return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		auto ret = solve();
		cout << (ret ? "YES" : "NO") << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}