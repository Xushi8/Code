// 2024/05/06 16:52:08
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <cmath>
using namespace std;

using i64 = int64_t;
vector<i64> contains;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	i64 n, W;
	cin >> n >> W;
	vector<pair<i64, i64>> a(n);
	for (i64 i = 0; i < n; i++)
	{
		i64 x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	sort(a.begin(), a.end());

	i64 mid = n / 2;

	vector<pair<i64, i64>> wv;
	for (i64 S = 0; S < (1 << mid); S++)
	{
		i64 v = 0, w = 0;
		for (i64 i = 0; i < mid; i++)
		{
			if ((S >> i) & 1)
			{
				v += a[i].first;
				w += a[i].second;
			}
		}

		wv.emplace_back(w, v);
	}

	sort(wv.begin(), wv.end());

	// 保证严格小于
	{
		vector<pair<i64, i64>> tmp;
		tmp.reserve(wv.size());
		tmp.emplace_back(wv.front());
		for (auto p : wv)
		{
			if (p.second > tmp.back().second)
			{
				tmp.emplace_back(p);
			}
		}
		wv = std::move(tmp);
	}
	
	// 
	// size_t tot = 1;
	// for (size_t i = 1; i < (1 << mid); i++)
	// {
	// 	if (wv[tot - 1].second < wv[i].second)
	// 	{
	// 		wv[tot++] = wv[i];
	// 	}
	// }
	// wv.erase(wv.begin() + tot, wv.end());

	i64 ans = 0;
	for (i64 S = 0; S < (1 << (n - mid)); S++)
	{
		i64 v = 0, w = 0;
		for (i64 i = 0; i < (n - mid); i++)
		{
			if ((S >> i) & 1)
			{
				v += a[mid + i].first;
				w += a[mid + i].second;
			}
		}

		if (w <= W)
		{
			auto it = upper_bound(wv.begin(), wv.end(), make_pair(W - w, 0x3f3f3f3f3f3f3f3f));
			it--;
			ans = max(ans, it->second + v);
		}
	}

	cout << ans << endl;

	return 0;
}