// 2024/04/06 14:53:31
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

bool cmp(pair<int, vector<int>> const& x, pair<int, vector<int>> const& y)
{
	if (x.first != y.first)
		return x.first > y.first;
	else
		return x.second < y.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	map<vector<int>, int> mp;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp(m);
		for (int j = 0; j < m; j++)
		{
			cin >> tmp[j];
		}

		mp[tmp]++;
	}

	cout << mp.size() << '\n';
	vector<pair<int, vector<int>>> ans;
	for (auto& [x, y] : mp)
	{
		ans.emplace_back(y, x);
	}

	sort(ans.begin(), ans.end(), cmp);
	for (auto [x, y] : ans)
	{
		cout << x;
		for (auto z : y)
		{
			cout << ' ' << z;
		}
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}