// 2024/07/25 10:01:28
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

pii operator+(pii l, pii r)
{
	return {l.first + r.first, l.second + r.second};
}

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector<vector<int>> f(n + 2, vector<int>(22));
	vector<vector<pii>> ans(n + 2, vector<pii>(22));
	for (int i = 0; i < n; i++)
	{
		f[i][0] = (i + 1) % n;
	}
	for (int i = 0; i < n; i++)
	{
		ans[i][0] = (s[i] == '1' ? pii{0, 1} : pii{1, 0});
	}

	auto func = [&](int u) -> void
	{
		for (int i = 1; i < 22; i++)
		{
			for (int j = 0; j < n; j++)
			{
				f[j][i] = f[f[j][i - 1]][i - 1];
				ans[j][i] = ans[j][i - 1] + ans[f[j][i - 1]][i - 1];
			}
		}

		vector<int> t_f(n + 2), t_ans(n + 2);
		for (int j = 0; j < n; j++)
		{
			int now = j, l = 0, r = 0;
			for (int i = 21; i >= 0; i--)
			{
				if (l + ans[now][j].first < u && r + ans[now][j].second < u)
				{
					l += ans[now][j].first;
					r += ans[now][j].second;
					now = f[now][j];
                }
			}
			t_ans[j] = ans[now][0].second;
			t_f[j] = f[now][0];
		}
		for (int j = 0; j < n; j++)
		{
			if (t_ans[j] == 0)
			{
				ans[j][0] = {1, 0};
			}
			else
			{
				ans[j][0] = {0, 1};
			}
			f[j][0] = t_f[j];
        }
	};

	func(a);
	func(b);
	for (int j = 0; j < n; j++)
	{
		cout << ans[j][0].second;
	}
	cout << '\n';
}