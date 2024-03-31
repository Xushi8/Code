// 2024/03/30 19:26:37
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

int deg[N];
bool single[N];

bool is_prime(int x)
{
	if (x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

bool bfs(int u)
{
	int x = u;
	set<int> st;
	while (u != 1)
	{
		deg[x]++;
		if (st.count(u))
		{
			return false;
		}
		st.emplace(u);
		int tmp = u;
		int v = 0;
		while (tmp)
		{
			int last = tmp % 10;
			tmp /= 10;
			v += last * last;
		}
		single[v] = 0;
		u = v;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, r;
	cin >> l >> r;

	fill(single, single + N, true);

	vector<int> ans;
	for (int i = l; i <= r; i++)
	{
		if (bfs(i))
			ans.emplace_back(i);
	}

	int num = 0;
	for (auto x : ans)
	{
		if (is_prime(x))
			deg[x] *= 2;
		if (single[x])
		{
			cout << x << ' ' << deg[x] << '\n';
			num++;
		}
	}

	if (num == 0)
	{
		cout << "SAD" << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}