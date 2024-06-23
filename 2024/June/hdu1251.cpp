// 2024/06/23 23:47:25
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
/*  tourist trie
	vector<vector<int>> trie(1, vector<int>(2, -1));
	vector<int> val(1, 0);
	bool ok = true;
	for (int i = 0; i < 2 * n; i++)
	{
		int x = (i < n ? b[i] : a[i - n]);
		int sign = (i < n ? 1 : -1);
		while (x % 2 == 0)
		{
			x /= 2;
		}
		int bit = 30;
		while (!(x & (1 << bit)))
		{
			bit -= 1;
		}
		int t = 0;
		for (int j = bit; j >= 0; j--)
		{
			int d = (x >> j) & 1;
			if (trie[t][d] == -1)
			{
				trie[t][d] = (int)trie.size();
				trie.emplace_back(2, -1);
				val.push_back(0);
			}
			t = trie[t][d];
			val[t] += sign;
			if (val[t] < 0)
			{
				ok = false;
			}
		}
	}
*/

void solve()
{
	// 第一维是层数, 初始化为1. 第二维是数量, 如a-z为26, 0-1为2, 初始化为-1
	vector<array<int, 26>> trie(1);
	trie.front().fill(-1);
	trie.reserve(N);
	// 存数量每次扩大2倍
	vector<int> cnt;
	cnt.reserve(N);

	auto insert = [&](string_view s)
	{
		int u = 0;
		for (auto ch : s)
		{
			int val = ch - 'a';
			if (trie[u][val] == -1)
			{
				trie[u][val] = int(trie.size());
				trie.emplace_back().fill(-1);
			}
			u = trie[u][val];
			if (u >= int(cnt.size()))
			{
				cnt.resize(2 * u);
			}
			cnt[u]++;
		}
	};

	auto query = [&](string_view s) -> int
	{
		int u = 0;
		for (auto ch : s)
		{
			int val = ch - 'a';
			if (trie[u][val] == -1)
			{
				return 0;
			}
			u = trie[u][val];
		}
		return cnt[u];
	};

	string s;
	while (getline(cin, s))
	{
		if (s.empty())
			break;
		insert(s);
	}

	while (getline(cin, s))
	{
		cout << query(s) << '\n';
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