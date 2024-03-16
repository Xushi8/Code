// 2024/03/15 21:39:22
#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 5050;
constexpr int maxn = N - 2;

int sum[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	r = min(r, maxn);
	for (int i = 0; i < n; i++)
	{
		int x, y, val;
		cin >> x >> y >> val;
		x++; y++;
		sum[x][y] += val;
	}

	for (int i = 1; i <= maxn; i++)
	{
		for (int j = 1; j <= maxn; j++)
		{
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int ans = -1;
	for (int i = r; i <= maxn; i++)
	{
		for (int j = r; j <= maxn; j++)
		{
			ans = max(ans, sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r]);
		}
	}
	cout << ans << endl;
	return 0;
}