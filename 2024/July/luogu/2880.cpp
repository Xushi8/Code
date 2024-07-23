// 2024/07/23 22:45:34
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

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<vector<int>> fmin(n + 1, vector<int>(__lg(n) + 1));
	auto fmax = fmin;
	for (int i = 1; i <= n; i++)
	{
		fmin[i][0] = fmax[i][0] = a[i - 1];
	}
	for (int i = 1; i <= __lg(n); i++)
	{
		for (int j = 1; j + (1 << i) - 1 <= n; j++)
		{
			fmin[j][i] = min(fmin[j][i - 1], fmin[j + (1 << (i - 1))][i - 1]);
			fmax[j][i] = max(fmax[j][i - 1], fmax[j + (1 << (i - 1))][i - 1]);
		}
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int s = __lg(r - l + 1);
		int minn = min(fmin[l][s], fmin[r - (1 << s) + 1][s]);
		int maxx = max(fmax[l][s], fmax[r - (1 << s) + 1][s]);
		cout << maxx - minn << '\n';
	}
}