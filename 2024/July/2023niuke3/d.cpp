// 2024/07/26 15:56:47
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

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;
			a[i][j] = ch - '0';
        }
    }

	constexpr int INF = 0x3f3f3f3f;
	auto func = [&](const int op, const int tar) -> int
	{
		auto b = a;
		int res = 0;
		if (op == 1)
		{
			res++;
			for (int i = 0; i < n; i++)
			{
				b[i][0] = !b[i][0];
            }
		}

		for (int i = 0; i < n; i++)
		{
			if (b[i][0] != tar)
			{
				res++;
				for (int j = 0; j < n; j++)
				{
					b[i][j] = !b[i][j];
                }
            }
		}
		
		for (int j = 0; j < n; j++)
		{
			if (b[0][j] != tar)
			{
				res++;
				for (int i = 0; i < n; i++)
				{
					b[i][j] = !b[i][j];
                }
            }
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[i][j] != tar)
				{
					return INF;
                }
            }
		}

		return res;
	};

	int ans = INF;
	ans = min({ans, func(0, 0), func(0, 1), func(1, 0), func(1, 1)});
	cout << (ans != INF ? ans : -1) << '\n';
}