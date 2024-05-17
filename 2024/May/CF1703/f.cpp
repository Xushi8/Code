// 2024/05/17 22:05:18
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}

		vector<int> b(n + 1);
		for (int i = 1; i <= n; i++)
		{
			b[i] = (a[i] < i);
		}
		inclusive_scan(b.begin(), b.end(), b.begin());
		i64 ans = 0;
		for (int i = n; i >= 1; i--)
		{
			if (a[i] < i)
			{
				if (1 <= a[i] - 1 && a[i] - 1 <= n)
					ans += b[a[i] - 1];
				else if (a[i] - 1 > n)
					ans += b.back();
			}
		}
		cout << ans << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}