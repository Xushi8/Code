// 2024/06/05 19:44:57
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
constexpr int N = 1000000005;

int func(int val)
{
	int x = sqrt(val);
	if (x * x == val)
		return val;
	else
		return (x + 1) * (x + 1);
}

void solve()
{
	int n;
	cin >> n;
	// vector<int> squ;
	// for (int i = 0; i * i <= N; i++)
	// {
	// 	squ.emplace_back(i * i);
	// }

	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--)
	{
		// auto it = lower_bound(squ.begin(), squ.end(), i);
		// int val = *it - i;
		int x = func(i);
		int val = x - i;
		int j = i;
		for (int index = val; index <= i; index++)
		{
			ans[index] = j;
			j--;
		}
		i = j + 1;
	}

	for (auto x : ans)
	{
		cout << x << ' ';
	}
	cout << '\n';
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