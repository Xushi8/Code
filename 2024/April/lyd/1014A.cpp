// 2024/04/22 14:45:19
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

int n, W;
int a[N];
bool vis[N];
int sum[N];
int ans;

void dfs(int now, int cnt)
{
	if (cnt >= ans)
	{
		return;
	}

	if (now == n)
	{
		ans = min(ans, cnt);
		return;
	}

	for (int i = 1; i <= cnt; i++)
	{
		if (sum[i] + a[now] <= W)
		{
			sum[i] += a[now];
			dfs(now + 1, cnt);
			sum[i] -= a[now];
		}
	}

	sum[cnt + 1] += a[now];
	dfs(now + 1, cnt + 1);
	sum[cnt + 1] -= a[now];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> W;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n, greater<>());
	ans = n;
	dfs(0, 0);

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}