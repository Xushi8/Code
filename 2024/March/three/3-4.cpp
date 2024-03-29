// 2024/03/29 19:44:55
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

double dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> a(n);
	for (auto& [x, y] : a)
	{
		cin >> x >> y;
	}

	double ans = 1e18;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				auto [x1, y1] = a[i];
				auto [x2, y2] = a[j];
				auto [x3, y3] = a[k];
				double a = dis(x1, y1, x2, y2);
				double b = dis(x1, y1, x3, y3);
				double c = dis(x2, y2, x3, y3);

				double cos_c = (a * a + b * b - c * c) / (2 * a * b);
				double square = a * b * sqrt(1 - cos_c * cos_c) / 2;
				ans = min(ans, square);
			}
		}
	}

	cout << setprecision(3) << fixed << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}