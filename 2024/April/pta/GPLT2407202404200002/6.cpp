#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<double> a(n);
	for (auto& x : a)
	{
		cin >> x;
	}

	vector<int> cnt(n, 0);
	int x, y;
	double ans = 0;
	while (cin >> x >> y && x != 0)
	{
		x--;
		cnt[x] += y;
		ans += a[x] * y;
	}

	for (auto x : cnt)
	{
		cout << x << '\n';
	}
	cout << fixed << setprecision(2);
	cout << ans << endl;

	return 0;
}
