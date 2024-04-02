// 2024/04/02 17:27:46
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

	size_t n;
	cin >> n;
	map<int, int> mp;
	for (size_t i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (i > 1)
		{
			auto it1 = mp.lower_bound(x);
			auto it2 = it1;
			
			int v1, v2;
			v1 = v2 = 2e9;
			if (it1 != mp.end())
			{
				v1 = it1->first - x;
			}
			if (it1 != mp.begin())
			{
				it2--;
				v2 = x - it2->first;
			}

			if (v2 <= v1)
			{
				cout << v2 << ' ' << it2->second << '\n';
			}
			else
			{
				cout << v1 << ' ' << it1->second << '\n';
			}
		}
		mp[x] = i;
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}