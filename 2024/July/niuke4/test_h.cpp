// 2024/07/25 14:09:51
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
	set<i64> st;
	for (int i = 0; i < n; i++)
	{
		i64 x;
		cin >> x;
		st.emplace(x);
	}

	vector<i64> a(st.begin(), st.end());
	if (a.size() == 1)
	{
		cout << 0 << '\n';
		return;
	}

	int g1 = a[1] - a[0];
	for (int i = 2; i < a.size(); i++)
	{
		g1 = std::gcd(g1, a[i] - a[0]);
	}

	int g2 = a[1] - a[0];
	for (int i = 2; i < a.size(); i++)
	{
		g2 = std::gcd(g2, a[i] - a[i - 1]);
	}

	cout << g1 << ' ' << g2 << '\n';
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