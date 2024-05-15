// 2024/05/15 17:26:24
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pll> a(n);
	for (auto& [x, y] : a)
		cin >> x >> y;

	double maxx = 1e18;
	pii ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			i64 x = a[i].first - a[j].first;
			i64 y = a[i].second - a[j].second;
			if (maxx > sqrt(x * x + y * y))
			{
				maxx = sqrt(x * x + y * y);
				ans = {i + 1, j + 1};
			}
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}