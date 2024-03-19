// 2024/03/19 14:19:46
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	cin >> n >> d;
	vector<pair<double, double>> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (y > d)
		{
			cout << -1 << endl;
			return 0;
		}
		a[i] = {x - sqrt(d * d - y * y), x + sqrt(d * d - y * y)};
	}

	sort(a.begin(), a.end());
	double now = -1e8;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [l, r] = a[i];
		if (now < l)
		{
			ans++;
			now = r;
		}
		else
		{
			now = min(now, r);
		}
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}