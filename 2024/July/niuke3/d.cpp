// 2024/07/24 10:41:29
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

void solve()
{
	int n;
	cin >> n;
	vector<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
	map<int, int> mp;
	vector<bool> used(n);
	for (size_t i = 0; i < a.size(); i++)
	{
		auto [x, y] = a[i];
		if (x == y)
		{
			used[i] = 1;
			mp[x]++;
		}
	}
	priority_queue<pii> que;
	for (auto [x, cnt] : mp)
	{
		que.emplace(cnt, x);
	}
	vector<pii> ans;
	ans.reserve(n);
	while (que.size() >= 2)
	{
		auto [cnt1, x1] = que.top();
		que.pop();
		auto [cnt2, x2] = que.top();
		que.pop();
		ans.emplace_back(x1, x1);
		ans.emplace_back(x2, x2);
		if (cnt1 - 1 > 0)
			que.emplace(cnt1 - 1, x1);
		if (cnt2 - 1 > 0)
			que.emplace(cnt2 - 1, x2);
	}

	if (que.size() == 1)
	{
		auto [cnt, x] = que.top();
		if (ans.empty() || x != ans.back().second)
		{
			ans.emplace_back(x, x);
			cnt--;
		}
		vector<int> tmp;
		for (int i = 0; i < n; i++)
		{
			if (!used[i] && x != a[i].first && x != a[i].second)
				tmp.emplace_back(i);
		}
		if (tmp.size() < cnt) // 找不到足够多的数字来填补这个数字
		{
			cout << "No\n";
			return;
		}
		for (int i = 0; i < cnt; i++)
		{
			int index = tmp[i];
			used[index] = 1;
			ans.emplace_back(a[index]);
			ans.emplace_back(x, x);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			used[i] = 1;
			if (!ans.empty() && ans.back().second == a[i].first)
				ans.emplace_back(a[i].second, a[i].first);
			else
				ans.emplace_back(a[i]);
		}
	}

	cout << "Yes\n";
	for (auto [x, y] : ans)
	{
		cout << x << ' ' << y << '\n';
	}
}