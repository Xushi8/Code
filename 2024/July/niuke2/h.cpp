// 2024/07/21 14:59:13
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

pii operator+(pii l, pii r)
{
	return {l.first + r.first, l.second + r.second};
}

pii operator-(pii l, pii r)
{
	return {l.first - r.first, l.second - r.second};
}

pii change(char ch)
{
	switch (ch)
	{
	case 'A':
		return {-1, 0};
		break;
	case 'S':
		return pii{0, -1};
		break;
	case 'D':
		return pii{1, 0};
		break;
	case 'W':
		return pii{0, 1};
		break;
	default:
		__builtin_unreachable();
	}
}

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	if (x == 0 && y == 0)
	{
		cout << 1ll * n * (n + 1) / 2 << '\n';
		return;
	}
	pii tar = {x, y};
	string s;
	cin >> s;
	n = s.size();
	vector<pii> sum(n + 1);
	for (int i = 0; i < n; i++)
	{
		sum[i + 1] = sum[i] + change(s[i]);
	}

	i64 ans = 0;
	map<pii, int> mp;
	for (int i = 0; i <= n; i++)
	{
		pii t = sum[i] - tar;
		ans += mp[t] * (n - i + 1);
		mp[t] = 0;
		mp[sum[i]]++;
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