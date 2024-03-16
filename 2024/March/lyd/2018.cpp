#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <math.h>
#include <stack>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;
typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define N 1000005
size_t n, k;
#define double long double

bool check(double val, vector<double> const& a)
{
	double sum = 0;
	size_t res = 0;
	size_t cnt = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (sum < 0)
			sum = a[i] - val, cnt = 1;
		else
			sum += a[i] - val, cnt++;
		if (sum >= 0)
			res = max(res, cnt);
	}
	return res >= k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	vector<double> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	double ans = 0, l = -1e18, r = 1e18;
	while (r - l > 1e-7)
	{
		double mid = (l + r) / 2;
		if (check(mid, a))
			ans = mid, l = mid;
		else
			r = mid;
	}

	cout << (int)round(1000 * ans) << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
}