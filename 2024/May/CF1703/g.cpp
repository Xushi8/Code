// 2024/05/17 22:36:18
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

// void solve()
// {
// 	i64 n, k;
// 	cin >> n >> k;
// 	vector<i64> a(n);
// 	for (i64 i = 0; i < n; i++)
// 	{
// 		cin >> a[i];
// 	}
// 	vector<i64> sum(n + 1);
// 	inclusive_scan(a.begin(), a.end(), sum.begin() + 1);
// 	i64 ans = 0;
// 	vector<i64> tmp;
// 	for (int i = n; i >= 0; i--)
// 	{
// 		i64 now_sum = sum[i] - k * i;
// 		for (auto x : tmp)
// 		{
// 			now_sum += x;
// 		}
// 		ans = max(ans, now_sum);

// 		if (i - 1 >= 0)
// 			tmp.emplace_back(a[i - 1]);
// 		for (auto& x : tmp)
// 			x /= 2;
// 		sort(tmp.begin(), tmp.end(), greater<>());
// 		auto it = lower_bound(tmp.begin(), tmp.end(), 0);
// 		if (it != tmp.end() && *it == 0)
// 			tmp.erase(it, tmp.end());
// 	}

// 	cout << ans << '\n';
// }

void solve()
{
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n + 1);
	for (i64 i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	vector<i64> sum(n + 1);
	inclusive_scan(a.begin(), a.end(), sum.begin());

	multiset<int> st;
    i64 ans = 0;
	for (i64 i = n; i >= 0; i--)
	{
		i64 now_sum = sum[i] - i * k;
		for (auto x : st)
			now_sum += x;
		ans = max(ans, now_sum);
		st.emplace(a[i]);
		multiset<int> tmp;
		for (auto x : st)
		{
			if (x / 2 > 0)
				tmp.emplace(x / 2);
		}
		st = std::move(tmp);
	}

	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}