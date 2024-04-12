// 2024/04/12 10:18:11
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

	int n;
	cin >> n;
	vector<pii> a(n);
	for (auto& [x, y] : a)
	{
		cin >> x >> y;
	}

	auto check = [&](ll val) -> int
	{
		for (auto [x, y] : a)
		{
			if (x / val > y)
				return -1;
			else if (x / val < y)
				return 1;
		}
		return 0;
    };

	ll l = 1, r = 2e9, minn = 0xffffffff, maxx = 0xffffffff;
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		int ret = check(mid);
		if (ret >= 0)
			minn = mid, r = mid - 1;
		else
			l = mid + 1;
    }

	l = 1, r = 2e9;
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		int ret = check(mid);
		if (ret <= 0)
			maxx = mid, l = mid + 1;
		else
			r = mid - 1;
	}

	cout << minn << ' ' << maxx << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}