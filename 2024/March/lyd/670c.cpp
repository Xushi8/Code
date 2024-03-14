// 2024/03/13 20:52:03
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
	for (size_t i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}

	size_t m;
	cin >> m;
	vector<pii> b(m);
	for (size_t i = 0; i < m; i++)
	{
		cin >> b[i].first;
	}
	for (size_t i = 0; i < m; i++)
	{
		cin >> b[i].second;
	}

	size_t ans = -1;
	int nx = -1, ny = -1;
	for (size_t i = 0; i < m; i++)
	{
		auto [tx, ty] = b[i];
        int x = mp[tx];
        int y = mp[ty];
		if (x > nx || (x == nx && y > ny))
		{
			ans = i;
			nx = x;
			ny = y;
        }
    }

	cout << ans + 1 << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}