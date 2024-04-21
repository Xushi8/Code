#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 100005;

vector<int> sons[N];

bool flag = 1;
size_t maxn = 0;
size_t k;

void dfs(int u)
{
	maxn = max(maxn, sons[u].size());
	if (sons[u].size() != 0)
	{
		if (sons[u].size() != k)
		{
			flag = 0;
		}
	}

	for (int v : sons[u])
	{
		dfs(v);
	}
}

vector<int> ans;

void qianxu(int u)
{
	ans.push_back(u);
	for (int v : sons[u])
	{
		qianxu(v);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int root;
	for (int i = 1; i <= n; i++)
	{
		int par;
		cin >> par;
		if (par == 0)
		{
			root = i;
			continue;
		}

		sons[par].push_back(i);
	}

	for (int i = 0; i <= n; i++)
	{
		sort(sons[i].begin(), sons[i].end());
	}

	k = sons[root].size();
	dfs(root);

	cout << maxn << ' ' << (flag ? "yes" : "no") << '\n';

	qianxu(root);
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans[i];
	}

	return 0;
}
