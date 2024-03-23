// 2024/03/23 19:57:16
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
constexpr int N = 10005;

int par[N];

void init(int n = N)
{
	iota(par, par + n, 0);
}

int find(int x)
{
	if (x == par[x])
		return x;
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<int> cnt;
	int n;
	cin >> n;
	init(N);
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		vector<int> tmp(m);
		for (int j = 0; j < m; j++)
		{
			cin >> tmp[j];
			tmp[j]--;
			cnt.emplace(tmp[j]);
		}
		for (int j = 1; j < m; j++)
		{
			unite(tmp[j], tmp[j - 1]);
        }
	}

	set<int> st;
	for (int i = 0; i < cnt.size(); i++)
	{
		st.emplace(find(i));
	}
	cout << cnt.size() << ' ' << st.size() << '\n';

	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << (same(x, y) ? 'Y' : 'N') << '\n';
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}