// 2024/05/16 18:01:44
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

constexpr int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve()
{
	array<array<char, 5>, 5> be;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> be[i][j];
		}
	}

	constexpr array<array<char, 5>, 5> ed = {
		{
			{'1', '1', '1', '1', '1'},
			{'0', '1', '1', '1', '1'},
			{'0', '0', '*', '1', '1'},
			{'0', '0', '0', '0', '1'},
			{'0', '0', '0', '0', '0'},
		}};

	map<array<array<char, 5>, 5>, int> da, db;
	map<array<array<char, 5>, 5>, pii> la, lb;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (be[i][j] == '*')
			{
				la[be] = {i, j};
				lb[ed] = {2, 2};
			}
		}
	}

	queue<array<array<char, 5>, 5>> qa, qb;
	qa.emplace(be);
	qb.emplace(ed);

	auto bfs = [&](queue<array<array<char, 5>, 5>>& que, const int step, map<array<array<char, 5>, 5>, int>& dis, map<array<array<char, 5>, 5>, pii>& location)
	{
		size_t count = que.size();
		while (count--)
		{
			auto a = que.front();
			que.pop();
			if (dis.count(a))
				continue;
			dis[a] = step;
			auto [x, y] = location[a];
			for (int k = 0; k < 8; k++)
			{
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (!(0 <= tx && tx < 5 && 0 <= ty && ty < 5))
					continue;
				swap(a[x][y], a[tx][ty]);
				location[a] = {tx, ty};
				que.emplace(a);
				swap(a[x][y], a[tx][ty]);
			}
		}
	};

	for (int i = 0; i < 8; i++)
	{
		bfs(qa, i, da, la);
		bfs(qb, i, db, lb);
	}
	if (qa.size() < qb.size())
		bfs(qa, 8, da, la);
	else
		bfs(qb, 8, db, lb);

	int ans = 16;
	for (auto const& [a, dis] : da)
	{
		auto it = db.find(a);
		if (it != db.end())
		{
			ans = min(ans, dis + it->second);
		}

		// for (int i = 0; i < 5; i++)
		// {
		// 	for (int j = 0; j < 5; j++)
		// 	{
		// 		cout << a[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << endl;
	}

	cout << (ans > 15 ? -1 : ans) << '\n';
#ifdef LOCAL
	system("clear");
#endif
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
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
