// 2024/05/27 17:46:21
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n;
	cin >> n;
	vector<pii> a(n);
	for(auto& [x, y] : a)
		cin >> x >> y;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i].first > a[j].first && a[i].second < a[j].second)
			{
				cout << "NO\n";
				return;
            }
        }
	}

	cout << "YES\n";

	auto dis = [&](pii x, pii y)
	{
        return abs(x.first - y.first) + abs(x.second + y.second);
    };

	pii now = {0, 0};
	vector<int> vis(n, 0);
	for (int cnt = 0; cnt < n; cnt++)
	{
		int now_dis = 1e9;
		int index;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i] && now_dis > dis(now, a[i]))
			{
				now_dis = dis(now, a[i]);
				index = i;
            }
		}

		for (int i = 0; i < a[index].first - now.first; i++)
			cout << 'R';
		for (int i = 0; i < a[index].second - now.second; i++)
			cout << 'U';
		vis[index] = 1;
		now = a[index];
	}

	cout << '\n';
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