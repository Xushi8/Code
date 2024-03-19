// 2024/03/18 20:33:14
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

void solve()
{
	int op, n;
	cin >> op >> n;
    vector<int> ans;
	priority_queue<int, vector<int>, less<>> big_que;
	priority_queue<int, vector<int>, greater<>> less_que;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (big_que.empty() || x <= big_que.top())
		{
			big_que.emplace(x);
		}
		else
		{
			less_que.emplace(x);
		}

		while (big_que.size() >= less_que.size() + 2)
		{
			less_que.emplace(big_que.top());
			big_que.pop();
		}
		while (less_que.size() >= big_que.size() + 2)
		{
			big_que.emplace(less_que.top());
			less_que.pop();
		}

		if (i % 2 == 0)
		{
			while (big_que.size() < less_que.size())
			{
				big_que.emplace(less_que.top());
				less_que.pop();
			}
			ans.emplace_back(big_que.top());
        }
	}

	cout << op << ' ' << ans.size() << '\n';
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " \n"[(i + 1) % 10 == 0 || i + 1 == ans.size()];
    }
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