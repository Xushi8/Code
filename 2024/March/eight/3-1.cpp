// 2024/04/13 20:46:49
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

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int n, m, V, D;
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> V >> D;
	multiset<pii> all_human;
	vector<vector<int>> city_human(m);
	int my_city, my_val;
	for (int i = 0; i < n; i++)
	{
		int city, val;
		cin >> city >> val;
		if (i == 0)
		{
			my_city = city;
			my_val = val;
			continue;
		}
		city_human[city].emplace_back(val);
		all_human.emplace(val, city);
	}
	for (int i = 0; i < m; i++)
	{
		sort(city_human[i].begin(), city_human[i].end());
	}

	vector<vector<int>> dis(m, vector<int>(m, INF));
	vector<vector<int>> tujing(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++)
	{
		dis[i][i] = 0;
	}
	for (int i = 0; i < V; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = w;
		tujing[u][v] = tujing[v][u] = 1;
	}

	for (int k = 0; k < m; k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					tujing[i][j] = tujing[i][k] + tujing[k][j];
				}
			}
		}
	}

	int now_time = 1;
	while (1)
	{
		if (all_human.size() == 0)
		{
			cout << "WIN on day " << now_time << " with " << my_val << "!" << endl;
			break;
		}

		auto it1 = all_human.lower_bound({my_val, -1});
		auto it2 = all_human.lower_bound({my_val + 1, -1});
		if (it1 == it2) // 没有 val 相同的对手, 尝试找到小一级的对手
		{
			if (it1 == all_human.begin())
			{
				cout << "Lose on day " << now_time << " with " << my_val << "." << endl;
				break;
			}
			else
			{
				it1--;
				auto xiaoyu = *it1;
				it1 = all_human.lower_bound({xiaoyu.first, -1});
				it2 = all_human.lower_bound({xiaoyu.first + 1, -1});
			}
		}
		if (now_time > D)
		{
			if (all_human.empty())
			{
				cout << "WIN on day " << D << " with " << my_val << "!" << endl;
				break;
			}
			cout << "Game over with " << my_val << "." << endl;
			break;
		}

		vector<pii> tmp(it1, it2);
		int min_dis = INF;
		for (auto [val, city] : tmp)
		{
			min_dis = min(min_dis, dis[my_city][city]);
		}
		vector<int> tmp1; // 存距离相同的城市
		for (auto [val, city] : tmp)
		{
			if (min_dis == dis[my_city][city])
			{
				tmp1.emplace_back(city);
			}
		}

		int min_tujing = INF;
		for (auto city : tmp1)
		{
			min_tujing = min(min_tujing, tujing[my_city][city]);
		}
		vector<int> tmp2; // 存途径城市相同的城市
		for (auto city : tmp1)
		{
			if (min_tujing == tujing[my_city][city])
			{
				tmp2.emplace_back(city);
			}
		}

		sort(tmp2.begin(), tmp2.end());
		int to_city = tmp2.front();
		if (my_city != to_city)
			cout << "Move from " << my_city << " to " << to_city << "." << '\n';
		now_time += min_dis;
		if (now_time > D)
		{
			if (all_human.empty())
			{
				cout << "WIN on day " << D << " with " << my_val << "!" << endl;
				break;
			}
			cout << "Game over with " << my_val << "." << endl;
			break;
		}
		cout << "Get " << it1->first << " at " << to_city << " on day " << now_time << "." << '\n';
		now_time++;
		my_val += it1->first;
		all_human.erase(all_human.find({it1->first, to_city}));
		city_human[to_city].erase(find(city_human[to_city].begin(), city_human[to_city].end(), it1->first));

		// 联合
		int sum = 0;
		bool flag = 0;
		for (int i = 0; i < city_human[to_city].size(); i++)
		{
			int val = city_human[to_city][i];
			if (val <= my_val)
			{
				sum += val;
				all_human.erase(all_human.find({val, to_city}));
			}
			else
			{
				flag = 1;
				city_human[to_city].erase(city_human[to_city].begin(), city_human[to_city].begin() + i);
				city_human[to_city].insert(lower_bound(city_human[to_city].begin(), city_human[to_city].end(), sum), sum);
				all_human.emplace(sum, to_city);
				break;
			}
		}
		if (!flag && sum != 0)
		{
			city_human[to_city].clear();
			city_human[to_city].emplace_back(sum);
			all_human.emplace(sum, to_city);
		}

		my_city = to_city;

		if (now_time > D)
		{
			if (all_human.empty())
			{
				cout << "WIN on day " << D << " with " << my_val << "!" << endl;
				break;
			}
			cout << "Game over with " << my_val << "." << endl;
			break;
		}

		if (!city_human[to_city].empty() && city_human[to_city].front() <= my_val) // 证明只有一个, 可以击破
		{
			cout << "Get " << city_human[to_city].front() << " at " << to_city << " on day " << now_time << "." << '\n';
			now_time++;
			my_val += city_human[to_city].front();
			all_human.erase(all_human.find({city_human[to_city].front(), to_city}));
			city_human[to_city].clear();
			if (now_time > D)
			{
				if (all_human.empty())
				{
					cout << "WIN on day " << D << " with " << my_val << "!" << endl;
					break;
				}
				cout << "Game over with " << my_val << "." << endl;
				break;
			}
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}