// 2024/04/09 17:41:15
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

int dfs(size_t x, size_t y, size_t l, size_t r, vector<vector<int>> const& a, vector<vector<int>>& dp)
{
	if (x == a.size())
		return 0;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n)), dp(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}

	cout << dfs(0, 0, 0, 0, a, dp) << endl;

	for (auto const& x : dp)
	{
		for (auto const& y : x)
		{
			cout << setw(2) << left << y << ' ';
		}
		cout << '\n';
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}