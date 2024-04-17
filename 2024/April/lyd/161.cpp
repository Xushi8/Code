// 2024/04/17 08:32:30
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

void solve()
{
	int n;
	cin >> n;
	int tot = 0;
	vector<vector<int>> trie(n * 10 + 5, vector<int>(10));
	vector<int> cnt(n * 10 + 5);

	auto insert = [&](string_view s)
	{
		int u = 0;
		for (char ch : s)
		{
			ch -= '0';
			int& v = trie[u][ch];
			if (v == 0)
				v = ++tot;
			u = v;
		}
		cnt[u]++;
	};

	auto check = [&](string_view s)
	{
		int u = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			char ch = s[i];
			ch -= '0';
			int& v = trie[u][ch];
			if (v == 0)
				break;
			u = v;
			if ((cnt[u] > 0 && i + 1 != s.size()) || cnt[u] > 1)
			{
				return false;
			}
		}
		return true;
	};

	bool flag = 1;

	vector<string> s(n);
	for (auto& x : s)
	{
		cin >> x;
		insert(x);
	}

	for (auto& x : s)
	{
		if (!check(x))
		{
			flag = 0;
			break;
		}
	}

	cout << (flag ? "YES" : "NO") << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
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