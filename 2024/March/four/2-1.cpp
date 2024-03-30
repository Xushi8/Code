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
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int dfs(int u, set<int>& st, int deep)
{
	st.emplace(u);
	int val = 0;
	int tmp = u;
	while (tmp != 0)
	{
		int last = tmp % 10;
		tmp /= 10;
		val += last * last;
	}

	single[val] = 0;

	if (deep != 0)
	{
		single[u] = 0;
	}

	if (val == 1)
	{
		return 1;
	}

	if (st.count(val) == 1)
	{
		single[u] = 0;
		return -1;
	}

	int cnt = dfs(val, st, deep + 1);
	if (cnt == -1)
	{
		single[u] = 0;
		return -1;
	}

	cnt++;
	deg[u] = cnt;
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, r;
	cin >> l >> r;

	fill(single, single + N, true);

	for (int i = l; i <= r; i++)
	{
		set<int> st;
		if (single[i])
			dfs(i, st, 0);
	}

	int num = 0;
	for (int i = l; i <= r; i++)
	{
		if (single[i])
		{
			num++;
			cout << i << ' ';
			if (is_prime(i))
				cout << deg[i] * 2 << '\n';
			else
				cout << deg[i] << '\n';
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