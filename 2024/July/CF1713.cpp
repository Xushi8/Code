// 2024/07/19 12:30:55
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

int par[N];

void init(int n)
{
	iota(par, par + n, 0);
}

int find(int x)
{
	if (x == par[x])
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
    par[x] = y;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

void solve()
{
	int n;
	cin >> n;
	int m = n;
	init(2 * n);
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
        }
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (a[i][j] > a[j][i]) // 换
			{
				if (same(i, j) || same(i + n, j + n))
					continue;
				unite(i, j + n);
				unite(i + n, j);
			}
			else if(a[i][j] < a[j][i]) // 不换
			{
				if (same(i + n, j) || same(i, j + n))
					continue;
				unite(i, j);
				unite(i + n, j + n);
            }
        }
	}

	vector<int> huan;
	for (int i = 0; i < n; i++)
	{
		if (0 <= find(i) && find(i) < n)
			huan.emplace_back(i);
	}

	for (auto k : huan)
	{
		// cerr << k + 1 << endl;
		for (int i = 0; i < n; i++)
		{
			swap(a[i][k], a[k][i]);
        }
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
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