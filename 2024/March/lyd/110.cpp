// 2024/03/18 20:50:37
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

bool cmp(pii const& x, pii const& y)
{
	return x.second < y.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	vector<pii> b(m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		swap(x, y);
		b[i] = {x, y};
	}

	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	int ans = 0;
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[j].first > 0 && a[i].first <= b[j].second && b[j].second <= a[i].second)
			{
				b[j].first--;
				ans++;
				break;
            }
        }
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}