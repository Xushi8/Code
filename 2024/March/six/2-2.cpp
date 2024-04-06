// 2024/04/06 14:44:52
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
vector<int> ans;
vector<int> tmp;

void dfs(int u, vector<vector<int>> const& G)
{
	tmp.emplace_back(u);
	for (int v : G[u])
	{
		dfs(v, G);
	}

	if (tmp.size() > ans.size())
	{
		ans = tmp;
    }
    
	tmp.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> G(n);
	set<int> st;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		G[i].reserve(k);
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			G[i].emplace_back(x);
			st.emplace(x);
		}
		sort(G[i].begin(), G[i].end());
	}

	for (int i = 0; i < n; i++)
	{
		if (!st.count(i))
		{
			dfs(i, G);
        }
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)
			cout << ' ';
        cout << ans[i];
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}