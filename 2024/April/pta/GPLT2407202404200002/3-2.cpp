// 2024/04/21 09:21:12
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

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	vector<size_t> factories;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '1')
		{
			factories.emplace_back(i);
		}
	}

	size_t l = 0, r = k - 1; // []
	ll ans = 0;
	for (size_t i = l; i < k; i++)
	{
		ans += factories[i] - 0;
	}
	for (size_t i = 0; i < s.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		if (r < factories.size() - 1 && i - factories[l] >= factories[r + 1] - i)
		{
			ans -= i - factories[l];
			ans += factories[r + 1] - i;
			l++;
			r++;
		}

		if (i > factories[r])
		{
			ans += 2;
        }

		cout << ans;
	}
	cout << '\n';
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