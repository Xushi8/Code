// 2024/07/29 15:27:53
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
vector<array<int, 3>> ans;

void dfs(int bx, int by, int n);

void dfs(int bx, int by, int ex, int ey);

void dfs(int bx, int by, int n)
{
	if (n <= 7)
	{
		ans.push_back({bx, by, n});
		return;
	}

	if (n % 2 == 0)
	{
		dfs(bx, by, n / 2);
		dfs(bx + n / 2, by, n / 2);
		dfs(bx, by + n / 2, n / 2);
		dfs(bx + n / 2, by + n / 2, n / 2);
	}
	else
	{
		dfs(bx, by, n / 2);
		dfs(bx + n / 2, by + n / 2, n - n / 2);
		dfs(bx + n / 2, by, bx + n, by + n / 2);
		dfs(bx, by + n / 2, bx + n / 2, by + n);
	}

	ans.push_back({bx, by, n});
}

void dfs(int bx, int by, int ex, int ey)
{
	int lenx = ex - bx;
	int leny = ey - by;
	if (lenx % 2 == 0)
	{
		int len = lenx / 2;
		for (; by + len < ey; by += len)
		{
			dfs(bx, by, len);
			dfs(bx + len, by, len);
		}
		len = leny - len;
		for (; bx + len <= ex && by + len <= ey; bx += len)
		{
			dfs(bx, by, len);
		}
	}
	else
	{
		int len = leny / 2;
		for (; bx + len < ex; bx += len)
		{
			dfs(bx, by, len);
			dfs(bx, by + len, len);
		}
		len = lenx - len;
		for (; by + len <= ey && bx + len <= ex; by += len)
		{
			dfs(bx, by, len);
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0 << '\n';
		return;
	}
	else if (n <= 7)
	{
		cout << "1 1 " << n << '\n';
		return;
	}

	dfs(1, 1, n);
	cout << ans.size() << '\n';
	for (auto [x, y, z] : ans)
	{
		cout << x << ' ' << y << ' ' << z << '\n';
	}
}