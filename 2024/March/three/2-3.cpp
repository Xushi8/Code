// 2024/03/27 14:10:12
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
using psi = pair<string, int>;
constexpr int N = 1000005;

bool cmp(psi const& x, psi const& y)
{
	if (x.second != y.second)
		return x.second > y.second;
	else
		return x.first < y.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, g, k;
	cin >> n >> g >> k;
	int sum = 0;
	vector<psi> a(n);
	for (int i = 0; i < n; i++)
	{
		string x;
		int y;
		cin >> x >> y;
		a[i] = {x, y};
		if (y >= g)
			sum += 50;
		else if (y >= 60)
			sum += 20;
	}

	sort(a.begin(), a.end(), cmp);
	cout << sum << '\n';
	vector<int> rk(n);
	rk[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i].second == a[i - 1].second)
			rk[i] = rk[i - 1];
		else
			rk[i] = i + 1;
	}
	
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = a[i];
		int rank = rk[i];
		if (rank > k)
			break;
		cout << rank << ' ' << x << ' ' << y << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
