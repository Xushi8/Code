// 2024/03/12 14:04:13
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

	int n, m;
	cin >> n >> m;
	vector<pair<string, int>> a(n);
	for (int i = 0; i < n; i++)
	{
		string x;
		int y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	auto func = [&](int val, int bit)
	{
		for (int i = 0; i < n; i++)
		{
			auto [x, y] = a[i];
			if (x == "AND")
			{
				val &= y;
			}
			else if (x == "OR")
			{
				val |= y;
			}
			else
			{
				val ^= y;
			}
		}
		return val & (1 << bit);
	};

	int now = 0, ans = 0;
	for (int i = 30; i >= 0; i--)
	{
		int tmp1 = 1 << i;
		int tmp2 = 0;
		int t1 = func(tmp1, i);
		int t2 = func(tmp2, i);
		if (now + tmp1 <= m && t1 > t2)
			now += tmp1, ans += t1;
		else
			now += tmp2, ans += t2;
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}