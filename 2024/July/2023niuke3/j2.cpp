
void solve1()
{
	int n, m;
	cin >> n >> m;
	vector<set<int>> G(n + 1);
	vector<int> in(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace(v);
		in[v]++;
	}

	queue<int> que;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			que.emplace(i);
		}
	}

	vector<int> ver;
	while (!que.empty())
	{
		auto u = que.front();
		que.pop();
		ver.emplace_back(u);
		for (auto v : G[u])
		{
			if (--in[v] == 0)
			{
				que.emplace(v);
			}
		}
	}

	if (ver.size() == n)
	{
		cout << 1 << '\n';
		for (auto x : ver)
		{
			cout << x << ' ';
		}
		cout << '\n';
	}
	else
	{
		cout << 2 << '\n';
		for (int i = 1; i <= n; i++)
		{
			cout << i << ' ';
		}
		cout << '\n';
		for (int i = n; i >= 1; i--)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n + 1);
	vector<int> in(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		in[v]++;
	}
	queue<int> que;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
			que.emplace(i);
	}

	vector<int> ver;
	while (!que.empty())
	{
		auto u = que.front();
		que.pop();
		ver.emplace_back(u);
		for (int v : G[u])
		{
			if (--in[v] == 0)
			{
				que.emplace(v);
			}
		}
	}

	if (ver.size() == n)
	{
		cout << 1 << '\n';
		for (auto x : ver)
		{
			cout << x << ' ';
		}
		cout << '\n';
	}
	else
	{
		cout << 2 << '\n';
		for (int i = 1; i <= n; i++)
		{
			cout << i << ' ';
		}
		cout << '\n';
		for (int i = n; i >= 1; i--)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}
