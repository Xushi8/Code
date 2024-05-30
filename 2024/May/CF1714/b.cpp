// 2024/05/29 22:36:33
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;
		deque<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		map<int, int> cnt;
		for (int i = 0; i < n; i++)
		{
			cnt[a[i]]++;
		}

		int ans = 0;
		int ge1 = 0;
		for (auto [x, y] : cnt)
		{
			if (y > 1)
			{
				ge1++;
            }
		}

		while (ge1 > 0)
		{
			ans++;
			auto x = a.front();
			a.pop_front();
			if (--cnt[x] == 1)
			{
				ge1--;
            }
		}

		cout << ans << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}