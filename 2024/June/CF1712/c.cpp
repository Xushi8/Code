// 2024/06/12 13:56:28
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
    vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ans = 0;
	set<int> erased;
	while (!is_sorted(a.begin(), a.end()))
	{
		int minn = a.back();
		for (int i = n - 2; i >= 0; i--)
		{
			if (erased.count(a[i]))
			{
				a[i] = 0;
				minn = 0;
				continue;
            }
			
			if (a[i] > minn)
			{
				ans++;
				erased.emplace(a[i]);
			}
			else
			{
				minn = min(minn, a[i]);
            }
        }   

		for (auto& x : a)
		{
			if (erased.count(x))
				x = 0;
        }
	}

	cout << ans << '\n';
	cout << flush;
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