// 2024/05/27 17:18:22
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (auto& val : a)
		cin >> val;
	bitset<N> vis;

	int ans = 0;
	vector<int> cnt(N);

	for (auto val : a)
	{
		val %= x;
		if (val + cnt[val] * x < N)
		{
			vis[val + cnt[val] * x] = 1;
			cnt[val]++;
		}

		for (; ans < N; ans++)
		{
			if (!vis[ans])
				break;
		}

		cout << ans << '\n';
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}