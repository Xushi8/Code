// 2024/05/15 22:20:47
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

void bfs(queue<string>& que, int step, unordered_map<string, int>& dis, vector<pair<string, string>> const& a)
{
	size_t count = que.size();
	while (count--)
	{
		auto s = que.front();
		que.pop();
		auto it = dis.find(s);
		if (it != dis.end() && it->second != 0)
			continue;
		dis[s] = step;
		for (size_t i = 0; i < s.size(); i++)
		{
			for (auto const& [x, y] : a)
			{
				if (s.substr(i, x.size()) == x)
				{
					auto t = s.substr(0, i);
					t += y;
					t += s.substr(i + x.size());
					que.emplace(t);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s, t;
	cin >> s >> t;
	if (s == t)
	{
		cout << 0 << endl;
		return 0;
    }
	vector<pair<string, string>> a, b;
	string x, y;
	while (cin >> x >> y)
	{
		if (x == y)
			continue;
		a.emplace_back(x, y);
		b.emplace_back(y, x);
	}

	queue<string> qa, qb;
	qa.emplace(s);
	qb.emplace(t);
	unordered_map<string, int> da, db;
	da[s] = 0;
	db[t] = 0;

	for (int i = 0; i < 6; i++)
	{
		bfs(qa, i, da, a);
		bfs(qb, i, db, b);
	}

	int ans = 11;
	for (auto const& [str, dis] : da)
	{
		auto it = db.find(str);
		if (it != db.end())
		{
			ans = min(ans, dis + it->second);
		}

		cerr << str << ' ' << dis << '\n';
	}

	if (ans == 11)
		cout << "NO ANSWER!\n";
	else
		cout << ans << '\n';

#ifdef LOCAL
			cerr
			 << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}