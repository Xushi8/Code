#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <math.h>
#include <stack>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;
typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define N 1000005

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	int n, d;
	// while (cin >> n >> d && n != 0 && d != 0)
	while(scanf("%d%d", &n, &d) == 2 && n && d)
	{
		cout << "Case " << t++ << ": ";
		vector<pdd> a(n);
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			double x, y;
			// cin >> x >> y;
			scanf("%lf%lf", &x, &y);
			if (y > d)
			{
				flag = 1;
			}

			a[i] = {(x - sqrt(d * d - y * y)), (x + sqrt(d * d - y * y))};
		}
	nex:
		if (flag)
		{
			cout << -1 << '\n';
			continue;
		}

		sort(a.begin(), a.end());

		double now = -1e18;
		size_t ans = 0;
		for (int i = 0; i < n; i++)
		{
			double l = a[i].first;
			double r = a[i].second;
			if (l > now)
			{
				ans++;
				now = r;
			}
			else
			{
				now = min(now, r);
			}
		}
		cout << ans << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
}