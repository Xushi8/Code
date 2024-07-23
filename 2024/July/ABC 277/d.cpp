// 2024/07/22 23:34:17
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
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	i64 sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
		sum += x;
	}
	vector<pii> a(mp.begin(), mp.end());
	// a.insert(a.end(), a.begin(), a.end());
	a.reserve(2 * a.size());
	copy(a.begin(), a.begin() + a.size(), inserter(a, a.end()));
	// a.insert(a.end(), mp.begin(), mp.end());
	i64 maxx = 0;
	for (int i = 0; i < int(a.size()); )
	{
		i64 tmp = 1ll * a[i].first * a[i].second;
        int j;
		for (j = i + 1; j < int(a.size()); j++)
		{
			if (a[j].first % m == (a[j - 1].first + 1) % m)
			{
				tmp += 1ll * a[j].first * a[j].second;
			}
			else
			{
				break;
            }
		}
		maxx = max(maxx, tmp);
		i = j;
	}

	i64 ans = sum - maxx;
	if (ans < 0)
		ans = 0;
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