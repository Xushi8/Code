#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<i64> a(n), b(n), c(n), d(n);
	for (auto& x : a)
		cin >> x;
	for (auto& x : b)
		cin >> x;
	for (auto& x : c)
		cin >> x;
	for (auto& x : d)
		cin >> x;

	constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;
	vector<i64> seed(n, INF);
	for (int i = 0; i < n; i++)
	{
		if (i + c[i] < n)
		{
			seed[i + c[i]] = min(seed[i + c[i]], b[i]);
		}
	}

	for (int i = 1; i < n; i++)
	{
		seed[i] = min({seed[i - 1], seed[i], a[i - 1]});
	}

	i64 ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += min(seed[i], a[i]) * d[i];
	}

	cout << ans << endl;
}