// 2024/06/03 21:07:45
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

void print(vector<int> const& a)
{
	for (auto x : a)
	{
		cout << x << ' ';
	}
	cout << '\n';
}

void solve()
{
	int n;
	cin >> n;
	cout << n << '\n';
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);

	for (int i = 0; i < n - 1; i++)
	{
		print(a);
		swap(a[i], a[i + 1]);
	}
	print(a);
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