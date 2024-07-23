// 2024/07/23 10:51:15
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
	vector<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {y, x};
	}
	sort(a.begin(), a.end(), greater<>());

	// priority_queue贪心
	i64 sum = 0;
	i64 ans = 0;
	priority_queue<i64, vector<i64>, greater<>> que;
	for (auto [s, v] : a)
	{
		sum += v;
		que.emplace(v);
		while (que.size() > s)
		{
			sum -= que.top();
			que.pop();
		}

		ans = max(ans, sum);
	}
	cout << ans << '\n';
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