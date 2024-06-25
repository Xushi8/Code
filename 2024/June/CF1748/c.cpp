// 2024/06/25 22:07:08
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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<i64> sum(n + 1);
	for (int i = 0; i < n; i++)
	{
		sum[i + 1] = sum[i] + a[i];
	}
	vector<int> zero;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			zero.emplace_back(i + 1);
        }
	}
	zero.emplace_back(n + 1);
	int ans = 0;
	for (int i = 1; i < zero.front(); i++)
	{
		ans += sum[i] == 0;
	}

	for (int i = 0; i + 1 < zero.size(); i++)
	{
		map<i64, int> mp;
		for (int j = zero[i]; j < zero[i + 1]; j++)
		{
			mp[sum[j]]++;
		}
		int maxx = 0;
		for (auto [x, y] : mp)
		{
			maxx = max(maxx, y);
		}
		ans += maxx;
	}

	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
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