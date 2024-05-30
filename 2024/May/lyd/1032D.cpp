// 2024/05/30 13:51:47
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int bit[N];

void add(int i, int x)
{
	for (; i < N; i += i & -i)
	{
		bit[i] += x;
    }
}

int sum(int i)
{
	int res = 0;
	for (; i > 0; i -= i & -i)
	{
		res += bit[i];
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	size_t n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 1; i < n; i++)
	{
		cin >> a[i];
	}

	for (size_t i = 1; i <= n; i++)
	{
		add(i, 1);
	}

	vector<int> final_ans;
	for (auto it = a.rbegin(); it != a.rend(); it++)
	{
		auto x = *it;

		i64 l = 1, r = n, ans = n;
		while (l <= r)
		{
			i64 mid = (l + r) / 2;
			if (sum(mid) > x)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}

		final_ans.emplace_back(ans);
		add(ans, -1);
	}

	reverse(final_ans.begin(), final_ans.end());
	for (auto x : final_ans)
	{
		cout << x << '\n';
	}
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}