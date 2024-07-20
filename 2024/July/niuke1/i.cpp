// 2024/07/20 13:24:05
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
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	enum fx
	{
		ABOVE,
		BELOW,
		LEFT,
		RIGHT,
	};

	// 指向的方向
	map<string, int> fangxiang = {
		{"above", ABOVE},
		{"below", BELOW},
		{"left", LEFT},
		{"right", RIGHT},
	};

	constexpr int dx[4] = {-1, 1, 0, 0};
	constexpr int dy[4] = {0, 0, -1, 1};

	auto change = [&](int& now_fangxiang, int x, int y, set<pii>& ans)
	{
		int ch = a[x][y];
		switch (now_fangxiang)
		{
		case ABOVE:
			switch (ch)
			{
			case '-':
				ans.emplace(x, y);
				now_fangxiang = BELOW;
				break;
			case '|':
				break;
			case '/':
				ans.emplace(x, y);
				now_fangxiang = RIGHT;
				break;
			case '\\':
				ans.emplace(x, y);
				now_fangxiang = LEFT;
				break;
			}
			break;
		case BELOW:
			switch (ch)
			{
			case '-':
				ans.emplace(x, y);
				now_fangxiang = ABOVE;
				break;
			case '|':
				break;
			case '/':
				ans.emplace(x, y);
				now_fangxiang = LEFT;
				break;
			case '\\':
				ans.emplace(x, y);
				now_fangxiang = RIGHT;
				break;
			}
			break;
		case LEFT:
			switch (ch)
			{
			case '-':
				break;
			case '|':
				ans.emplace(x, y);
				now_fangxiang = RIGHT;
				break;
			case '/':
				ans.emplace(x, y);
				now_fangxiang = BELOW;
				break;
			case '\\':
				ans.emplace(x, y);
				now_fangxiang = ABOVE;
				break;
			}
			break;
		case RIGHT:
			switch (ch)
			{
			case '-':
				break;
			case '|':
				ans.emplace(x, y);
				now_fangxiang = LEFT;
				break;
			case '/':
				ans.emplace(x, y);
				now_fangxiang = ABOVE;
				break;
			case '\\':
				ans.emplace(x, y);
				now_fangxiang = BELOW;
				break;
			}
			break;
		default:
			__builtin_unreachable();
		}
	};

	map<array<int, 3>, size_t> all_ans;

	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		string t;
		cin >> x >> y >> t;
		x--;
		y--;
		int now_fangxiang = fangxiang[t];
		set<pii> ans;
		map<pii, array<int, 4>> mp;
		vector<array<int, 3>> path;
		size_t ttt = 0;
		while (1)
		{
			x += dx[now_fangxiang];
			y += dy[now_fangxiang];
			if (!(0 <= x && x < n && 0 <= y && y < m))
				break;
			if (all_ans.count({x, y, now_fangxiang}))
			{
				ttt = all_ans[{x, y, now_fangxiang}];
				break;
            }
			auto it = mp.find({x, y});
			if (it == mp.end())
				mp[{x, y}].fill(0);
			if (mp[{x, y}][now_fangxiang] == 1)
			{
				array<int, 3> tmp = {x, y, now_fangxiang};
				for (size_t i = 0; i < path.size(); i++)
				{
					if (all_ans.count(path[i]))
					{
						break;
					}
					all_ans.emplace(path[i], ans.size());
					if (path[i] == tmp)
					{
						size_t t_ans = ans.size() - i;
						for (size_t j = i; j < path.size(); j++)
						{
							if (all_ans.count(path[j]))
							{
								break;
							}
							all_ans.emplace(path[j], t_ans);
                        }
                        
						break;
                    }
				}
				break;
			}
			mp[{x, y}][now_fangxiang] = 1;
			path.push_back({x, y, now_fangxiang});
			change(now_fangxiang, x, y, ans);
			// cerr << x << ' ' << y << '\n';
		}

		for (size_t i = 0; i < path.size(); i++)
		{
			if (all_ans.count(path[i]))
			{
				break;
			}
			all_ans.emplace(path[i], ans.size());
		}

		cout << ans.size() + ttt << '\n';
		// cerr << '\n';
	}
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