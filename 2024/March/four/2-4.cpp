// 2024/03/30 20:08:41
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

	int n, m, t;
	cin >> n >> m >> t;
	while (t--)
	{
		deque<int> que;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			que.emplace_back(x);
		}

		int now = 1;
		stack<int> stk;
		bool flag = 1;
		set<int> st;
		while (!que.empty())
		{
			auto x = que.front();
			que.pop_front();
			if (x == now)
			{
				now++;
				while (st.count(now) != 0)
				{
					while (!stk.empty())
					{
						auto x = stk.top();
						stk.pop();
						st.erase(x);
						if (x == now)
						{
							now++;
							break;
						}
						else
						{
							flag = 0;
							goto out;
							que.emplace_front(x);
						}
					}
				}
			}
			else
			{
				stk.emplace(x);
				st.emplace(x);
				if (stk.size() > m)
				{
					flag = 0;
					break;
				}
			}
		}
	out:
		cout << (flag ? "YES" : "NO") << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}