// 2024/07/26 12:28:16
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

bool is_prime(i64 n)
{
	if (n == 1)
		return false;
	for (i64 i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<i64> a(n);
	i64 sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (n == 1)
	{
		cout << (is_prime(a[0]) ? "Yes" : "No") << '\n';
	}
	else if (n == 2)
	{
		if (sum % 2 == 0)
			cout << (sum != 2 ? "Yes" : "No") << '\n';
		else
			cout << (is_prime(sum - 2) ? "Yes" : "No") << '\n';
	}
	else
	{
		cout << (sum >= 2 * n ? "Yes" : "No") << '\n';
	}
}