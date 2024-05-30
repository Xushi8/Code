// // 2024/05/30 10:56:21
// #ifdef LOCAL
// #include <basic_std_lib.h>
// #else
// #include <bits/stdc++.h>
// #endif
// using namespace std;

// using i64 = int64_t;
// using pii = pair<int, int>;
// using pll = pair<i64, i64>;
// constexpr int N = 1000005;

// void solve()
// {
	
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

// 	// int tt;
// 	// cin >> tt;
// 	// while (tt--)
// 	// {
// 	// 	solve();
// 	// }

// 	for (int i = 0; i < 10; i++)
// 	{
// 		int j = i;
// 		set<int> st;
// 		st.emplace(j);
// 		int adds = 0;
// 		vector<int> add;
// 		while (1)
// 		{
// 			add.emplace_back(adds);
// 			adds += j % 10;
// 			j += j % 10;
// 			if (st.count(j % 10))
// 				break;
// 			st.emplace(j % 10);
// 		}

// 		// for (auto x : st)
// 		// {
// 		// 	cout << x << ' ';
// 		// }
// 		for (auto x : add)
// 		{
// 			cout << x << ' ';
//         }
// 		cout << '\n';
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

// 2024/05/30 12:19:03
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
		vector<int> a(n);
		for (auto& x : a)
			cin >> x;
		set<int> b, c;
		for (auto x : a)
		{
			if (x % 10 == 0)
				b.emplace(x);
			else if (x % 5 == 0)
				b.emplace(x + 5);
			else
			{
				while (x % 10 != 6)
				{
					x += x % 10;
				}
				c.emplace(x % 20);
			}
		}

		if (!b.empty())
			cout << (b.size() == 1 && c.empty() ? "YES" : "NO");
		else
			cout << (c.size() == 1 ? "YES" : "NO");
		cout << '\n';
	}
	
#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}