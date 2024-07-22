// 2024/07/21 17:28:09
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(2 * n + 2);
	vector<array<int, 2>> ind(n + 2);
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> a[i];
		if (ind[a[i]][0] == 0)
			ind[a[i]][0] = i;
		else
			ind[a[i]][1] = i;
	}
	ind.back() = {0, 2 * n + 1};

	auto cpi = ind;
	// 按区间长度从小到大排序
	sort(cpi.begin(), cpi.end(), [](auto const& l, auto const& r)
		{
			if(l[1] - l[0] != r[1] - r[0])
				return l[1] - l[0] < r[1] - r[0];
			else
				return l[1] < r[1];
		});

	vector<int> f(2 * n + 2), dp(2 * n + 2);
	for (auto [l, r] : cpi)
	{
		f[l] = a[l];
		for (int i = l + 1; i <= r; i++)
		{
			// 将当前值的权重设为 a[l]
			f[i] = f[i - 1] + a[l];
			int left_ind = ind[a[i]][0];
			// 如果当前位置的值在右侧且其左侧的值在大区间内
			if (left_ind != i && left_ind > l)
			{
				// 看一看是旧值好还是新值好
				f[i] = max(f[i], f[left_ind - 1] + dp[i]);
			}
		}
		// 将当前数值保存到 r 所在的位置中
		dp[r] = f[r];
	}
	cout << dp[2 * n + 1] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}