// 2024/07/20 12:57:03
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
constexpr i64 MOD = 1000000007;

void solve()
{
	int q;
	cin >> q;
	vector<i64> a, sum;
	a.reserve(q);
	sum.resize(q);
	while (q--)
	{
		int num, x;
		cin >> num >> x;
		a.erase(a.end() - num, a.end());
		a.emplace_back(x);
		i64 index = a.size() - 1;
		sum[index] = a.back() * a.size() % MOD;
		if (index != 0)
			sum[index] += sum[index - 1];
		sum[index] %= MOD;
		cout << sum[index] << '\n';
	}
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