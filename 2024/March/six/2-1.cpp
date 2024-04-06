// 2024/04/06 14:36:43
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, maxx;
	cin >> n >> m >> maxx;
	vector<queue<char>> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i].emplace(s[j]);
		}
	}

	vector<char> ans;
	stack<char> stk;
	int op;
	while (cin >> op && op != -1)
	{
		if (op == 0)
		{
			if (!stk.empty())
			{
				ans.emplace_back(stk.top());
				stk.pop();
			}
		}
		else
		{
			if (!a[op].empty())
			{
				if (stk.size() == maxx)
				{
					ans.emplace_back(stk.top());
					stk.pop();
				}
				stk.emplace(a[op].front());
				a[op].pop();
			}
		}
	}

	ans.emplace_back('\0');
	cout << ans.data() << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}