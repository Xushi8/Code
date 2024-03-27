// 2024/03/27 13:16:16
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
constexpr int N = 26;
int n, m;

string tmp;

int used[N];
int tot = 0;
int all = 1;

void dfs(int deep)
{
	if (deep == n)
	{
		tot++;
		if (tot == m)
		{
			cout << tmp << endl;
			exit(0);
		}
		return;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (used[i] < n)
		{
			used[i]++;
			tmp += 'a' + i;
			dfs(deep + 1);
			tmp.pop_back();
			used[i]--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		all *= 26;
	}
	dfs(0);

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}