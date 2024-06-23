// 2024/06/24 00:07:58
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
	vector<array<int, 2>> trie(1);
	trie[0].fill(-1);
	vector<i64> arr;
	trie.reserve(5 * N);
	arr.reserve(5 * N);

	auto insert = [&](i64 x)
	{
		int u = 0;
		for (int i = 32; i >= 0; i--)
		{
			int bit = (x >> i) & 1;
			if (trie[u][bit] == -1)
			{
				trie[u][bit] = int(trie.size());
				trie.emplace_back();
				trie.back().fill(-1);
			}
			u = trie[u][bit];
		}
		if (u >= arr.size())
		{
			arr.resize(2 * u);
		}
		arr[u] = x;
	};

	auto query = [&](i64 x) -> i64
	{
		int u = 0;
		for (int i = 32; i >= 0; i--)
		{
			int bit = (x >> i) & 1;
            int v = trie[u][bit ^ 1] != -1 ? trie[u][bit ^ 1] : trie[u][bit];
			u = v;
		}
		return arr[u];
	};

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		i64 x;
		cin >> x;
		insert(x);
	}
	for (int i = 0; i < m; i++)
	{
		i64 x;
		cin >> x;
		cout << query(x) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; i++)
	{
		cout << "Case #" << i << ":\n";
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}