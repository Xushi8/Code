// 2024/06/05 19:20:43
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
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	a.back() = b.back() = 0;

	int max1 = *max_element(a.begin(), a.end());
	int max2 = *max_element(b.begin(), b.end());

	int min1 = *min_element(a.begin(), a.end());
	int min2 = *min_element(b.begin(), b.end());

	int ans = ((max1 - min1) + (max2 - min2)) * 2;
	cout << ans << '\n';
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