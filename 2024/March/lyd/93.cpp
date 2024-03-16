// 2024/03/15 17:53:41
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
int n, m;
vector<int> ans;

void dfs(int deep)
{
	// if (deep + ans.size() < m)
	// 	return;
	// if (deep + ans.size() == m)
	// {
	// 	if (deep == 0)
	// 	{
	// 		for (auto it = ans.rbegin(); it != ans.rend(); it++)
	// 		{
	// 			cout << *it << ' ';
	//         }
	// 		cout << '\n';
	// 		return;
	//     }
	// }
	// if (deep == 0)
	// 	return;

	// ans.emplace_back(deep);
	// dfs(deep - 1);
	// ans.pop_back();

	// dfs(deep - 1);

	if (n - deep + ans.size() < m)
		return;
	if (ans.size() == m)
	{
		for (auto x : ans)
		{
			cout << x + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	if (deep == n)
		return;

	ans.emplace_back(deep);
	dfs(deep + 1);
	ans.pop_back();

	dfs(deep + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	dfs(0);

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}