// #include <iostream>

// using namespace std;

// const int N = 55, M = 2 * N;

// int n, m;
// int w[N][N];
// int f[M][N][N];

// int main()
// {
//     //input
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++ i)
//     {
//         for (int j = 1; j <= m; ++ j)
//         {
//             cin >> w[i][j];
//         }
//     }
//     //dp
//     for (int k = 2; k <= n + m; ++ k)
//     {
//         for (int i = 1; i < k && i <= n; ++ i)
//         {
//             for (int j = 1; j < k && j <= n; ++ j)
//             {
//                 int v = w[i][k - i];
//                 if (i != j) v += w[j][k - j];

//                 int &t = f[k][i][j];
//                 t = max(t, f[k - 1][i][j]);
//                 t = max(t, f[k - 1][i - 1][j]);
//                 t = max(t, f[k - 1][i][j - 1]);
//                 t = max(t, f[k - 1][i - 1][j - 1]);
//                 t += v;
//             }
//         }
// 	}

// 	for (int k = 2; k <= n + m; k++)
// 	{
// 		for (int i = 1; i <= n; i++)
// 		{
// 			for (int j = 1; j <= m; j++)
// 			{
// 				cerr << f[k][i][j] << ' ';
// 			}
// 			cout << '\n';
//         }
//     }

//     //output
//     cout << f[n + m][n][n] << endl;
//     return 0;
// }

// 2024/06/18 12:20:46
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

// void solve()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	vector<vector<int>> a(n + 1, vector<int>(m + 1));
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= m; j++)
// 		{
// 			cin >> a[i][j];
// 		}
// 	}

// 	vector<vector<vector<int>>> dp(n + m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

// 	for (int index = 2; index <= n + m; index++)
// 	{
// 		for (int i = 1; i <= n; i++)
// 		{
// 			for (int j = 1; j <= n; j++)
// 			{
// 				if (!(1 <= index - i && index - i <= m && 1 <= index - j && index - j <= m))
// 					continue;
// 				dp[index][i][j] = max({dp[index][i][j],
// 					dp[index - 1][i - 1][j], dp[index - 1][i][j - 1], dp[index - 1][i - 1][j - 1], dp[index - 1][i][j]});
// 				int val = a[i][index - i];
// 				if (i != j)
// 					val += a[j][index - j];
// 				dp[index][i][j] += val;
// 			}
// 		}
// 	}

// 	cout << dp[n + m][n][n] << '\n';
// }

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<vector<vector<int>>> dp(n + m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

	for (int k = 2; k <= n + m; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!(1 <= k - i && k - i <= m && 1 <= k - j && k - j <= m))
					continue;
				dp[k][i][j] = max({dp[k][i][j], dp[k - 1][i - 1][j], dp[k - 1][i][j - 1], dp[k - 1][i][j], dp[k - 1][i - 1][j - 1]});
				int val = a[i][k - i];
				if (i != j)
					val += a[j][k - j];
				dp[k][i][j] += val;
			}
		}
	}

	cout << dp[n + m][n][n] << '\n';
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