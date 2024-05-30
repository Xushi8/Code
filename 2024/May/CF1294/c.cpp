// 2024/05/27 17:55:14
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int x;
	cin >> x;
	vector<i64> yinzi;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			yinzi.emplace_back(i);
			if (x / i != i)
				yinzi.emplace_back(x / i);
		}
	}

	for (size_t i = 0; i < yinzi.size(); i++)
	{
		for (size_t j = i + 1; j < yinzi.size(); j++)
		{
			for (size_t k = j + 1; k < yinzi.size(); k++)
			{
				if (yinzi[i] * yinzi[j] * yinzi[k] == x)
				{
					cout << "YES\n";
					cout << yinzi[i] << ' ' << yinzi[j] << ' ' << yinzi[k] << '\n';
					return;
				}
			}
		}
	}

	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}