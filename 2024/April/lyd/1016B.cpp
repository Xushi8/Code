// 2024/04/22 17:00:48
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
constexpr int N = 55;
int W, n;
int a[N];
int ans;
vector<int> sum;

void dfsl(int now, int now_sum)
{
	if (now == n / 2)
	{
		sum.emplace_back(now_sum);
		return;
	}

	dfsl(now + 1, now_sum);
	if (ll(now_sum) + a[now] <= W)
	{
		dfsl(now + 1, now_sum + a[now]);
	}
}

void dfsr(int now, int now_sum)
{
	if (now == n)
	{
		auto it = upper_bound(sum.begin(), sum.end(), W - now_sum);
		if (it != sum.begin())
		{
			it--;
			ans = max(ans, *it + now_sum);
		}
		return;
	}

	dfsr(now + 1, now_sum);
	if (ll(now_sum) + a[now] <= W)
	{
		dfsr(now + 1, now_sum + a[now]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> W >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n, greater<>());

	dfsl(0, 0);
	sort(sum.begin(), sum.end());
	sum.erase(unique(sum.begin(), sum.end()), sum.end());

	dfsr(n / 2, 0);
	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}