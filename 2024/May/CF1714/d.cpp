// 2024/05/30 10:36:00
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
		string s;
		cin >> s;
		int m;
		cin >> m;
		vector<string> a(m);
		for (int i = 0; i < m; i++)
		{
			cin >> a[i];
		}

		vector<pii> qujian;
		for (auto val : a)
		{
			size_t pos = 0;
			size_t nex_pos;
			while ((nex_pos = s.find(val, pos)) != string::npos)
			{
				qujian.emplace_back(nex_pos, nex_pos + val.size());
				pos = nex_pos + 1;
			}
		}

		sort(qujian.begin(), qujian.end());
		vector<pii> ans;
		int pre = 0;
		while (pre < s.size())
		{
			int maxx = -1;
			pii tmp;
			for (auto [x, y] : qujian)
			{
				if (0 <= x && x <= pre)
				{
					if (maxx < y)
					{
						maxx = y;
						tmp = {x, y};
					}
				}
			}
			if (maxx == -1 || maxx == pre)
			{
				cout << "-1\n";
				goto out;
			}
			ans.emplace_back(tmp);
			pre = tmp.second;
		}

		if (ans.empty() || ans.front().first != 0 || ans.back().second != s.size())
			cout << -1 << '\n';
		else
		{
			cout << ans.size() << '\n';
			for (auto [x, y] : ans)
			{
				// cout << x + 1 << ' ' << y << '\n';
				auto ts = s.substr(x, y - x);
				for (size_t i = 0; i < a.size(); i++)
				{
					if (a[i] == ts)
					{
						cout << i + 1 << ' ';
						break;
					}
				}
				cout << x + 1 << '\n';
			}
		}
	out:
		// cout << flush;

		// size_t pre = 0;
		// ans.emplace_back(qujian.front());
		// for (size_t i = 1; i < qujian.size(); i++)
		// {
		// 	if (qujian[i].second > qujian[pre].second)
		// 	{
		// 		if (qujian[i].first == qujian[pre].first)
		// 			ans.pop_back();
		// 		ans.emplace_back(qujian[i]);
		// 		pre = i;
		// 	}
		// }

		// bool flag = 1;
		// for (size_t i = 1; i < ans.size(); i++)
		// {
		// 	if (ans[i - 1].second < ans[i].first)
		// 	{
		// 		flag = 0;
		// 		break;
		// 	}
		// }

		// if (ans.empty() ||  ans.back().second != s.size() || ans.front().first != 0)
		// 	flag = 0;

		// if (!flag)
		// 	cout << -1 << '\n';
		// else
		// {
		// 	cout << ans.size() << '\n';
		// 	for (auto [x, y] : ans)
		// 	{
		// 		cout << x + 1 << ' ' << y << '\n';
		// 	}
		// }
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}