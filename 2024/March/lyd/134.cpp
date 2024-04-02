// 2024/04/02 16:18:47
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

	size_t n, m;
	cin >> n >> m;
	vector<int_fast32_t> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<int_fast32_t> sum(n + 1);
	sum[0] = 0;
	inclusive_scan(a.begin(), a.end(), sum.begin() + 1);

	deque<int_fast32_t> que;
	que.emplace_back(0);
	int_fast32_t ans = a[0];
	for (size_t i = 1; i <= n; i++)
	{
		if (i - que.front() > m)
			que.pop_front();
		ans = max(ans, sum[i] - sum[que.front()]);
		while (!que.empty() && sum[i] <= sum[que.back()])
			que.pop_back();
		que.emplace_back(i);
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
