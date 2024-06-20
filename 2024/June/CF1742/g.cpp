// 2024/06/20 21:58:26
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
	vector<unsigned int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<bitset<32>> bits(n);
	for (int i = 0; i < n; i++)
	{
		bits[i] = a[i];
	}

	vector<bool> vis(n);

	vector<int> ans;
	array<bool, 32> has_bit;
	has_bit.fill(false);
	for (int i = 31; i >= 0; i--)
	{
		if (has_bit[i])
			continue;

		map<int, int, greater<>> mp; // 权重 下标
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && bits[j][i])
			{
				int val = 0;
				for (int k = i; k >= 0; k--)
				{
					if (!has_bit[k] && bits[j][k])
					{
						val |= 1 << k;
					}
				}
				mp[val] = j;
			}
		}

		if (mp.empty())
			continue;

		int index = mp.begin()->second;
		vis[index] = true;
		ans.emplace_back(a[index]);
		for (int k = i; k >= 0; k--)
		{
			if (!has_bit[k] && bits[index][k])
			{
				has_bit[k] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			ans.emplace_back(a[i]);
		}
	}

	for (auto x : ans)
	{
		cout << x << ' ';
	}
	cout << '\n';
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