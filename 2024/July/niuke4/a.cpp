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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int par[N], dep[N], ans[N];

void init(int n)
{
	iota(par, par + n, 0);
	fill(dep, dep + n, 0);
	fill(ans, ans + n, 0);
}

int find(int x)
{
	if (x == par[x])
		return x;
	int t = find(par[x]);
	dep[x] += dep[std::exchange(par[x], t)];
	return par[x];
}

void unite(int x, int y)
{
	int t = find(x);
	ans[t] = max(ans[t], dep[x] + ans[y] + 1);
	par[y] = x;
	dep[y] = 1;
}

void solve()
{
	int n;
	cin >> n;
	init(n);
	vector<int> a(n - 1), b(n - 1), c(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--; c[i]--;
	}

	for (int i = 0; i < n - 1; i++)
	{
		unite(a[i], b[i]);
		cout << ans[c[i]] << ' ';
	}
	cout << '\n';
}