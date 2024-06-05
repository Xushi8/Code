// 2024/06/05 20:18:33
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
	vector<int> a(1 << n);
	iota(a.begin(), a.end(), 1);

	auto check = [&](int i)
	{
		cout << "? " << a[i] << ' ' << a[i + 2] << endl;
		int x;
		cin >> x;
		if (x == 0)
		{
			cout << "? " << a[i + 1] << ' ' << a[i + 3] << endl;
			cin >> x;
			if (x == 1)
			{
				return a[i + 1];
			}
			else
			{
				return a[i + 3];
			}
		}
		else if (x == 1)
		{
			cout << "? " << a[i] << ' ' << a[i + 3] << endl;
			cin >> x;
			if (x == 1)
			{
				return a[i];
			}
			else
			{
				return a[i + 3];
			}
		}
		else
		{
			cout << "? " << a[i + 1] << ' ' << a[i + 2] << endl;
			cin >> x;
			if (x == 1)
			{
				return a[i + 1];
			}
			else
			{
				return a[i + 2];
			}
		}
	};

	while (a.size() > 1)
	{
		vector<int> tmp;
		if (a.size() < 4)
		{
			cout << "? " << a.front() << ' ' << a.back() << endl;
			int x;
			cin >> x;
			if (x == 1)
			{
				tmp.push_back(a.front());
			}
			else
			{
				tmp.push_back(a.back());
            }
		}
		else
		{
			for (int i = 0; i + 4 <= a.size(); i += 4)
			{
				tmp.emplace_back(check(i));
			}
		}
		a = std::move(tmp);
	}

	cout << "! " << a.front() << endl;
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