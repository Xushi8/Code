// 2024/04/10 13:33:59
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	size_t n, m, k;
	cin >> n >> m >> k;
	deque<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	stack<int> hezi;
	vector<vector<int>> ans;

	while (1)
	{
		vector<int> songzhen;

		while (1)
		{
			if (hezi.empty())
			{
				if (a.empty())
					break;
				hezi.emplace(a.front());
				a.pop_front();
			}

			if (songzhen.empty())
			{
				songzhen.emplace_back(hezi.top());
				hezi.pop();
				if (songzhen.size() == k)
					break;
			}
			else
			{
				if (songzhen.back() >= hezi.top())
				{
					songzhen.emplace_back(hezi.top());
					hezi.pop();
					if (songzhen.size() == k)
						break;
				}
				else
				{
					if (a.empty())
					{
						break;
					}
					auto x = a.front();
					a.pop_front();
					if (songzhen.back() >= x)
					{
						songzhen.emplace_back(x);
						if (songzhen.size() == k)
							break;
					}
					else
					{
						if (hezi.size() == m)
						{
							a.emplace_front(x);
							break;
						}
						hezi.emplace(x);
					}
				}
			}
		}

		if (songzhen.size() == 0)
			break;
		else
			ans.emplace_back(std::move(songzhen));
	}

	for (auto x : ans)
	{
		for (int i = 0; i < x.size(); i++)
		{
			if (i != 0)
				cout << ' ';
			cout << x[i];
		}
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}