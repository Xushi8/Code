// 2024/04/12 18:58:59
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
constexpr int N = 55;

int ans = N;
ll n, m;
ll a[N];
ll sum[N];

void dfs(ll now_sum, int deep, int cnt)
{
	if (cnt >= ans)
		return;
	if (now_sum == m)
	{
		ans = min(ans, cnt);
		return;
	}
	if (deep == n || now_sum > m || now_sum + sum[deep] < m)
		return;
	dfs(now_sum, deep + 1, cnt);
	dfs(now_sum + a[deep], deep + 1, cnt);
	dfs(now_sum + a[deep] / 2, deep + 1, cnt + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	m *= 2;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] *= 2;
	}
	sort(a, a + n, greater<>());
	for (int i = n - 1; i >= 0; i--)
	{
		sum[i] = sum[i + 1] + a[i];
    }
	dfs(0, 0, 0);

	if (ans == N)
		ans = -1;
	cout << ans << endl;

#ifdef LOCAL
	cerr
		<< "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}