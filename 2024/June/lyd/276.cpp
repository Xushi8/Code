// 2024/06/18 09:46:26
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
        }
	}

	vector<int> query(q + 1);
	for (int i = 1; i <= q; i++)
	{
		cin >> query[i];
		query[i]--;
	}

	query[0] = 2;

	constexpr int INF = 0x3f3f3f3f;
	vector<vector<vector<int>>> dp(q + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INF)));
	dp[0][0][1] = 0;

	for (int i = 0; i < q; i++)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				int z = query[i];
				if (x == y || y == z || z == x)
					continue;
				int val = dp[i][x][y];
				int to = query[i + 1];
				dp[i + 1][x][y] = min(dp[i + 1][x][y], val + a[z][to]);
				dp[i + 1][z][y] = min(dp[i + 1][z][y], val + a[x][to]);
				dp[i + 1][x][z] = min(dp[i + 1][x][z], val + a[y][to]);
            }
        }
	}

	int ans = INF;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			int z = query[q];
			if (x == y || y == z || z == x)
				continue;
			ans = min(ans, dp[q][x][y]);
		}
    }
	cout << ans << '\n';

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << dp[q][i][j] << ' ';
	// 	}
	// 	cout << '\n';
    // }
}

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