// 2024/03/22 18:45:48
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
int ans[N];

void dfs(int u, int deep, vector<vector<int>> const& sons)
{
	ans[deep]++;
	for (int v : sons[u])
	{
		dfs(v, deep + 1, sons);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> sons(n);
	for (int i = 0; i < m; i++)
	{
		int far;
		cin >> far;
		far--;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int son;
			cin >> son;
			son--;
			sons[far].emplace_back(son);
        }
	}

	dfs(0, 1, sons);
	int maxn = ans[1];
	int id = 1;
	for (int i = 1; i < N; i++)
	{
		if (ans[i] > maxn)
		{
			maxn = ans[i];
			id = i;
        }
	}

	cout << maxn << ' ' << id << endl;

	// cout << reduce(ans, ans + 100, 0) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}