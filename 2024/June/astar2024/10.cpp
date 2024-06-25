// 2024/06/24 13:52:07
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 0; i < k; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		a[l]++;
		a[r + 1]--;
	}
	for (int i = 0; i < n; i++)
	{
		a[i + 1] += a[i];
	}

	sort(a.begin(), a.begin() + n);
	cout << a[n / 2] << '\n';
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