#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	ll sum = 0;
	for (auto& x : a)
	{
		cin >> x;
		sum += x;
	}

	sum -= n * (m - 1);
	cout << sum << endl;

	return 0;
}
