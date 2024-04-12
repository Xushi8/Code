// 2024/04/10 13:21:49
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

	int n, k, s;
	cin >> n >> k >> s;
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		mp[x].emplace_back(y);
	}

	int ans = 0;
	for (auto& [x, y] : mp)
	{
		if (x < 175)
			continue;
		sort(y.begin(), y.end());

		if (y.size() <= k)
			ans += y.size();
		else
		{
			ans += k;
			y.erase(y.begin(), y.begin() + k);
			auto it = lower_bound(y.begin(), y.end(), s);
			ans += y.end() - it;
		}
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}