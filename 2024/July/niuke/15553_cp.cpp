#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
ll t, n, k, ans, a[maxn], sum[maxn], f1[maxn], f2[maxn];
void solve();
int main()
{
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

void solve()
{
	memset(f1, -0x7f, sizeof(f1));
	memset(f2, -0x7f, sizeof(f2));
	cin >> n >> k;
	ans = -1e18;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}
	for (int i = k; i <= n - k; i++)
		f1[i] = max(sum[i] - sum[i - k], f1[i - 1]);
	for (int i = n - k + 1; i >= k + 1; i--)
		f2[i] = max(sum[i + k - 1] - sum[i - 1], f2[i + 1]);
	for (int i = k; i <= n - k; i++)
		ans = max(ans, f1[i] + f2[i + 1]);
	cout << ans << endl;
}