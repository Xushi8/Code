// 2024/05/20 14:39:41
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

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (auto& x : a)
		cin >> x;
	sort(a.begin(), a.end());
	vector<int> siz;
	siz.reserve(m);
	for (int i = 1; i < m; i++)
	{
		siz.emplace_back(a[i] - a[i - 1] - 1);
	}
	siz.emplace_back(n + a.front() - a.back() - 1);
	sort(siz.begin(), siz.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < siz.size(); i++)
	{
		if (siz[i] - 4 * i > 1)
		{
			ans += siz[i] - 1 - 4 * i;
		}
		else if (siz[i] - 4 * i == 1)
		{
			ans++;
		}
		else
		{
			break;
        }
    }

	cout << n - ans << '\n';
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