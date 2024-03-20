// 2024/03/20 13:39:38
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
constexpr int N = 505;
bool vis[N];
int n, m;

int func(vector<set<int>> G)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		vis[i] = 0;
	queue<int> que;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			cnt++;
			que.emplace(i);
			vis[i] = 1;
			while (!que.empty())
			{
				auto u = que.front();
				que.pop();
				for (auto v : G[u])
				{
					if (!vis[v])
					{
						vis[v] = 1;
						que.emplace(v);
					}
				}
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vector<set<int>> G(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace(v);
		G[v].emplace(u);
	}

	int q;
	cin >> q;

	int pre = func(G);

	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		G[x].clear();
		for (auto& u : G)
			u.erase(x);
		int nex = func(G);
		if (nex > pre + 1)
			cout << "Red Alert: City " << x << " is lost!" << '\n';
		else
			cout << "City " << x << " is lost." << '\n';
		pre = nex;

		if (i + 1 >= n)
		{
			cout << "Game Over." << endl;
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}