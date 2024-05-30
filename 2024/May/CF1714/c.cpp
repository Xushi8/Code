// // 2024/05/29 22:41:42
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
// // vector<int> ans;

// // void dfs(int deep, int val, vector<int>& now_ans, bitset<10>& vis)
// // {
// // 	if (val < 0)
// // 		return;
// // 	if (val == 0)
// // 	{
// // 		if (now_ans.size() < ans.size() || (now_ans.size() == ans.size() && now_ans < ans))
// // 		{
// // 			ans = now_ans;
// // 		}
// // 		return;
// // 	}

// // 	if (deep == 0)
// // 	{
// // 		for (int i = 9; i >= 1; i--)
// // 		{
// // 			if (!vis[i])
// // 			{
// // 				vis[i] = 1;
// // 				now_ans.emplace_back(i);
// // 				dfs(deep + 1, val - i, now_ans, vis);
// // 				now_ans.pop_back();
// // 				vis[i] = 0;
// // 			}
// // 			if (now_ans.size() >= ans.size())
// // 				return;
// // 		}
// // 	}
// // 	else
// // 	{
// // 		for (int i = 9; i >= 0; i--)
// // 		{
// // 			if (!vis[i])
// // 			{
// // 				vis[i] = 1;
// // 				now_ans.emplace_back(i);
// // 				dfs(deep + 1, val - i, now_ans, vis);
// // 				now_ans.pop_back();
// // 				vis[i] = 0;
// // 			}
// // 			if (now_ans.size() >= ans.size())
// // 				return;
// // 		}
// // 	}
// // }

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int tt;
// 	cin >> tt;
// 	map<int, basic_string<int>> dp;
// 	while (tt--)
// 	{
// 		int x;
// 		cin >> x;
// 		auto it = dp.find(x);
// 		if (it != dp.end())
// 		{
// 			for (auto val : it->second)
// 				cout << val;
// 			cout << '\n';
// 			continue;
//         }
		
// 		// bitset<10> vis;
// 		// ans.insert(ans.end(), 11, 10);
// 		// vector<int> now_ans;
// 		// dfs(0, x, now_ans, vis);
// 		// for (auto val : ans)
// 		// 	cout << val;
// 		// cout << '\n';

// 		basic_string<int> a(10, 0);
// 		iota(a.begin(), a.end(), 0);
// 		swap(a[0], a[1]);
// 		basic_string<int> ans(11, 0);
// 		do
// 		{
// 			if (a.front() == 0)
// 				continue;
// 			int sum = 0;
// 			for (size_t i = 0; i < 10; i++)
// 			{
// 				sum += a[i];
// 				if (sum > x)
// 					break;
// 				if (sum == x)
// 				{
// 					if (i + 1 < ans.size() || (i + 1 == ans.size() && a.substr(0, ans.size()) < ans))
// 					{
// 						ans = a.substr(0, i + 1);
// 					}

// 					break;
// 				}
// 			}
// 		} while (next_permutation(a.begin(), a.end()));

// 		for (auto val : ans)
// 			cout << val;
// 		cout << '\n';
// 		dp[x] = std::move(ans);
// 	}


// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }


// 2024/05/30 11:06:23
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
		int val;
		cin >> val;
		int ans = 0;
		int wei = 1;
		for (int i = 9; i >= 1 && val != 0; i--)
		{
			int t = min(i, val);
			val -= t;
			ans += t * wei;
			wei *= 10;
		}

		cout << ans << '\n';
	}
	
#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}