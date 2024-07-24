// 2024/07/24 22:24:58
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	i64 n, k;
	cin >> n >> k;
	i64 sum = k * (k + 1) / 2;
	set<i64> st;
	for (int i = 0; i < n; i++)
	{
		i64 x;
		cin >> x;
        st.emplace(x);
	}

	for (auto x : st)
	{
		if (1 <= x && x <= k)
		{
			sum -= x;
        }
	}
	cout << sum << '\n';
}