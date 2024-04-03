// 2024/04/03 20:05:41
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
constexpr int N = 204;
constexpr int INF = 0x3f3f3f3f;
int cnt = 0;
int id;
int minn = 2e9;
int dis[N][N];
int n, m;

void solve(int i)
{
	int k;
	cin >> k;
	vector<int> lujing;
	lujing.emplace_back(0);
	set<int> st;
	bool flag = 1;
	for (int j = 0; j < k; j++)
	{
		// cin >> lujing[j];
		int x;
		cin >> x;
		if (st.count(x))
		{
			flag = 0;
		}
		st.emplace(x);
		lujing.emplace_back(x);
	}
	lujing.emplace_back(0);

	if (!flag || lujing.size() - 2 != n)
		return;
	int tmp = 0;
	for (int j = 0; j < lujing.size() - 1; j++)
	{
		auto u = lujing[j];
		auto v = lujing[j + 1];
		if (dis[u][v] == INF)
		{
			flag = 0;
			break;
		}
		else
		{
			tmp += dis[u][v];
		}
	}

	if (flag)
	{
		cnt++;
		if (tmp < minn)
		{
			minn = tmp;
			id = i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<pii>> G(n + 1);
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	int q;
	cin >> q;

	for (int i = 1; i <= q; i++)
	{
		solve(i);
	}

	cout << cnt << '\n';
	cout << id << ' ' << minn << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}