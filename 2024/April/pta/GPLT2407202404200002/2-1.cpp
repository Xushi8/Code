#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 100005;
set<int> own[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			own[x].emplace(i);
		}
	}

	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		auto const& a = own[x];
		auto const& b = own[y];
		int ans = 0;
		for (auto t : a)
		{
			if (b.count(t) == 1)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
