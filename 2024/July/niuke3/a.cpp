// 2024/07/23 12:52:25
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

i64 bit[N];
int n;
void add(int i, int x)
{
	while (i <= n)
	{
		bit[i] += x;
		i += i & -i;
	}
}

i64 sum(int i)
{
	i64 ret = 0;
	while (i > 0)
	{
		ret += bit[i];
		i -= i & -i;
	}
	return ret;
}

void solve()
{
	int L, R;
	cin >> n >> L >> R;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<int> take;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 2)
		{
			take.emplace_back((a[i] - 1) / 2);
		}
	}

	if (R >= n)
	{
		cout << "Yes\n";
		return;
	}
	const int m = take.size();
	take.insert(take.begin(), -1);
	sort(take.begin(), take.end());
	for (int i = 1; i <= m; i++)
	{
		add(i, take[i]);
	}
	int to_be = n - m;
	while (to_be > 0)
	{
		// for (int i = 1; i <= 5; i++)
		// {
		// 	cerr << sum(i) << ' ';
		// }
		// cerr << '\n';

		int len = L;
		// 找到第一个 >= len的位置
		int l = 1, r = m;
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (sum(mid) >= len && (len == 1 || sum(mid + 1) - sum(mid) > 0))
				ans = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		if (ans == -1)
		{
			cout << "No\n";
			return;
		}

		add(ans - len + 1, -1);
		add(ans, 1);
		to_be -= R - L;
	}

	cout << "Yes\n";

	// vector<i64> a(n);
	// i64 sum = 0;
	// i64 sum1 = 0;
	// i64 cnt1 = 0;
	// vector<int> tran;
	// for (int i = 0; i < n; i++)
	// {
	// 	cin >> a[i];
	// 	if (a[i] <= 2)
	// 		cnt1++;
	// 	else
	// 	{
	// 		sum += (a[i] - 1) / 2;
	// 		tran.emplace_back((a[i] - 1) / 2);
	// 		if ((a[i] - 1) / 2 - 1 > 0)
	// 		{
	// 			sum1 += (a[i] - 1) / 2 - 1;
	// 		}
	// 	}
	// }
	// sort(tran.begin(), tran.end());
	// if (R >= n)
	// {
	// 	cout << "Yes\n";
	// 	return;
	// }

	// // 每次r - l个人, 消耗l
	// i64 need = (cnt1 + (R - L - 1)) / (R - L);

	// if (need <= sum / L - sum1)
	// {
	// 	cout << "Yes\n";
	// }
	// else
	// {
	// 	cout << "No\n";
	// }
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